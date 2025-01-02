#include "stdio.h"
#include "libft.h"
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	obtain_list(char *structure_name, t_typelist **list);
int	cut_string(char **string, size_t start, size_t end);

void	*ft_memcpy_aa(void *dest, const void *src, size_t n)
{
	void	*pointer;

	if ((!dest) && (!src))
		return (NULL);
	pointer = dest;
	while ((n--) && (dest))
	{
		*((char *)dest) = *((char *)src);
		++dest;
		++src;
	}
	return (pointer);
}

int	ft_realloc(void **content, size_t size)
{
	void	*re_content;

	re_content = malloc(size + 1);
	if (!(re_content))
		return (1);
	ft_memcpy_aa(re_content, *content, size);
	free(*content);
	*content = re_content;
	return (0);
}

int	take_line(char *line)
{
	int		start;
	int		end;
	char	*temp;

	start = 0;
	end = 0;
	while ((line[start] != 's') && (line[start + 1] != '_'))
	{
		start++;
		if (line[start] == '\n')
			break ;
		if (line[start] == 0)
			break ;
	}
	end = start;
	while ((line[end] != '\n') && (line[end] != 0))
	{
		end++;
	}
	if (start == end)
		return (2);
	temp = line;
	line = ft_substr(line, start, end - start);
	if (!line)
		return (free(temp), 1);
	return (free(temp), 0);
}

int	take_list(char *line, t_typelist **list)
{
	char	*struct_to_find;

	struct_to_find = ft_strdup(line);
	cut_string(&struct_to_find, 0, 1);
	free(struct_to_find);
	if (obtain_list(struct_to_find, list) != 0)
		return (1);
	return (0);
}

int	get_struct_list(t_typelist ***struct_list, char ***struct_list_names)
{
	int		fd;
	int		line_num;
	int		counter;
	char	*line;

	counter = 1;
	fd = open("test.c", O_RDONLY);
	if (fd == -1)
		return (printf("1\n"));
	*struct_list_names = (char **)malloc(1 * sizeof(char *));
	if (!(*struct_list_names))
		return (printf("1\n"));
	*struct_list = (t_typelist **)malloc(1 * sizeof(t_typelist *));
	if (!(*struct_list))
		return (free(*struct_list_names), 1);
	while ("Loop")
	{
		line = line_fgm(FIND, fd, 1, "struct s_");
		if (!line)
			break ;
		++counter;
		if (ft_realloc((void **)*struct_list_names, counter * 8) != 0)
			return (free(*struct_list_names), free(*struct_list), 1);
		if (ft_realloc((void **)*struct_list, counter * 8) != 0)
			return (free(*struct_list_names), free(*struct_list), 1);
		take_line(line);
		take_list(line, &((*struct_list)[counter - 2]));
		(*struct_list_names)[counter - 2] = line;
	}
	return (0);
}

int	main()
{
	t_typelist	**struct_list;
	char		**struct_list_names;
	t_typelist	*list;
	t_typelist	*temp;
	int			counter;

	struct_list = NULL;
	if (get_struct_list(&struct_list, &struct_list_names) != 0)
		return (printf("ERROR!\n"));
	counter = 1;
	list = NULL;
	temp = NULL;
	while (struct_list)
	{
		list = *struct_list;
		printf("\nLIST %s:\n", *struct_list_names);
		while ((list) && (list->next))
		{
			printf("type n_%d: %s\n", counter, (char *)list->type);
			printf("name n_%d: %s\n\n", counter, (char *)list->content);
			free(list->content);
			free(list->type);
			temp = list;
			list = list->next;
			free(temp);
			++counter;
		}
		if (list)
			free(list);
		if (*struct_list_names)
			free(*struct_list_names);
		++struct_list;
		++struct_list_names;
	}
	if (struct_list)
		free(struct_list);
	if (struct_list_names)
		free(struct_list_names);
	return (0);
}