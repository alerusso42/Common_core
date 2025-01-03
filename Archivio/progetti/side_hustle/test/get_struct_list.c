#include "stdio.h"
#include "libft.h"
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	obtain_list(char *structure_name, t_typelist **list);
int	cut_string(char **string, size_t start, size_t end);

char	*line_fgm_aa(int flag, int fd, int num_search, ...)
{
	char	*string;
	char	*search;
	int		counter;
	va_list	list;

	va_start(list, num_search);
	counter = 1;
	string = get_next_line(fd, 0);
	if (!string)
	{
		va_end(list);
		return (NULL);
	}
	search = va_arg(list, char *);
	while ((search) && (string) && (num_search--))
	{
		while (strstr(string, search) == NULL)
		{
			free(string);
			string = get_next_line(fd, 0);
			if (!string)
				break ;
			++counter;
		}
		search = va_arg(list, char *);
	}
	va_end(list);
	if (!string)
		return (NULL);
	if (flag == FIND)
		return (free(string), ft_itoa(counter));
	if (flag == GET)
		return (string);
	return ("Metti le flag ammodo, mongoloide");
}

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

	re_content = ft_calloc(size, 1);
	if (!(re_content))
		return (1);
	ft_memcpy_aa(re_content, *content, size - 8);
	free(*content);
	*content = re_content;
	return (0);
}

int	take_line(char **line)
{
	int		start;
	int		end;
	char	*temp;

	start = 0;
	end = 0;
	while (((*line)[start] != 's') || ((*line)[start + 1] != '_'))
	{
		start++;
		if ((*line)[start] == '\n')
			break ;
		if ((*line)[start] == 0)
			break ;
		if ((*line)[start] == '\t')
			(*line)[start] = ' ';
	}
	end = start;
	while (((*line)[end] != '\n') && ((*line)[end] != 0))
	{
		end++;
		if ((*line)[end] == '\t')
			(*line)[end] = ' ';
	}
	if (start == end)
		return (2);
	temp = (*line);
	(*line) = ft_substr((*line), start, end - start);
	if (!(*line))
		return (free(temp), 1);
	return (free(temp), 0);
}

int	take_list(char *line, t_typelist **list)
{
	char	*struct_to_find;

	struct_to_find = ft_strdup(line);
	cut_string(&struct_to_find, 0, 1);
	if (obtain_list(struct_to_find, list) != 0)
		return (free(struct_to_find), 1);
	free(struct_to_find);
	return (0);
}

int	get_struct_list(t_typelist ***struct_list, char ***struct_list_names)
{
	int		fd;
	int		counter;
	char	*line;

	counter = 1;
	fd = open("test.c", O_RDONLY);
	if (fd == -1)
		return (printf("1\n"));
	*struct_list_names = (char **)malloc(1 * sizeof(char *));
	if (!(*struct_list_names))
		return (printf("1\n"));
	*struct_list = (t_typelist **)ft_calloc(1, sizeof(t_typelist *));
	if (!(*struct_list))
		return (free(*struct_list_names), 1);
	while ("Loop")
	{
		line = line_fgm_aa(GET, fd, 1, "typedef struct");
		if (!line)
			break ;
		++counter;
		if (ft_realloc((void **)struct_list_names, counter * 8) != 0)
			return (free(*struct_list_names), free(*struct_list), 1);
		if (ft_realloc((void **)struct_list, counter * 8) != 0)
			return (free(*struct_list_names), free(*struct_list), 1);
		take_line(&line);
		(*struct_list)[counter - 2] = NULL;
		take_list(line, &((*struct_list)[counter - 2]));
		(*struct_list_names)[counter - 2] = line;
	}
	(*struct_list)[counter - 1] = NULL;
	(*struct_list_names)[counter - 1] = NULL;
	return (0);
}

/*
	mode 0: freea e rende NULL un puntatore.
	mode 1: salva un puntatore (massimo 5).
	mode 2: libera tutti i puntatori salvati.
*/
void	del_pointer(void **ptr, int mode)
{
	static void	*save_1 = NULL;
	static void	*save_2 = NULL;
	static void	*save_3 = NULL;
	static void	*save_4 = NULL;
	static int	count_saves = 0;

	if (mode == 0)
	{
		if (*ptr)
			free(*ptr);
		*ptr = NULL;
		return ;
	}
	if (mode == 1)
	{
		if (count_saves == 0)
			save_1 = *ptr;
		else if (count_saves == 1)
			save_2 = *ptr;
		else if (count_saves == 2)
			save_3 = *ptr;
		else if (count_saves == 3)
			save_4 = *ptr;
		++count_saves;
		return ;
	}
	if (count_saves > 0)
		del_pointer(&save_1, 0);
	if (count_saves > 1)
		del_pointer(&save_2, 0);
	if (count_saves > 2)
		del_pointer(&save_3, 0);
	if (count_saves > 3)
		del_pointer(&save_4, 0);
	count_saves = 0;
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
	list = NULL;
	temp = NULL;
	del_pointer((void **)&struct_list, 1);
	del_pointer((void **)&struct_list_names, 1);
	while ((struct_list) && (*struct_list))
	{
		counter = 1;
		list = *struct_list;
		printf("\nLIST %s:\n", *struct_list_names);
		while ((list) && (list->next))
		{
			printf("type n_%d: %s\n", counter, (char *)list->type);
			printf("name n_%d: %s\n\n", counter, (char *)list->content);
			del_pointer((void **)&(list->content), 0);
			del_pointer((void **)&(list->type), 0);
			temp = list;
			list = list->next;
			del_pointer((void **)&(temp), 0);
			++counter;
		}
		del_pointer((void **)&(list), 0);
		del_pointer((void **)&(*struct_list_names), 0);
		++struct_list;
		++struct_list_names;
	}
	del_pointer(NULL, 2);
	del_pointer(NULL, 2);
	return (0);
}