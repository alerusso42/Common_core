#include "stdio.h"
#include "libft.h"
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	obtain_list(char *structure_name, t_typelist **list);
/*
void hold_space(int counter, int fd)
{
	while (counter--)
		write(fd, " ", 1);
	write(fd, "\n", 1);
}*/

void	check_element_size(int *n_element_size, int counter)
{
	static int	check_multiple_of_ten = 10;

	if (counter - 1 == check_multiple_of_ten)
	{
		check_multiple_of_ten *= 10;
		*n_element_size += 1;
	}
}

static void	initiate_write(t_typelist *list, int fd, char *struct_name)
{
	int		space;
	int		counter;
	char	*n_element;
	int		n_element_size;

	write(fd, "[", 1);
	write(fd, struct_name, ft_strlen(struct_name));
	write(fd, "]\n", 2);
	space = set_maximum_word_len(-1) + 1;
	counter = 1;
	n_element = NULL;
	n_element_size = 1;
	while ((list) && (list->next))
	{
		write(fd, "Name_", 5);
		n_element = ft_itoa(counter++);
		check_element_size(&n_element_size, counter);
		if (n_element)
			write(fd, n_element, n_element_size);
		write(fd, " = ", 3);
		hold_space(space, fd);
		write(fd, "type_", 5);
		if (n_element)
			write(fd, n_element, n_element_size);
		write(fd, " = ", 3);
		hold_space(space, fd);
		list = list->next;
		if (n_element)
			free(n_element);
	}
}

int	save_struct(char *struct_name, t_typelist *list)
{
	int			fd;
	int			line_num;
	char		*s;

	fd = open("struct_list.txt", O_CREAT | O_APPEND | O_RDWR, 0666);
	if (fd < 0)
		return (printf("1\n"));
	line_num = find_number_line(fd, "struct_list.txt", 1, struct_name);
	if (line_num != -1)
		return (printf("struct già esistente."), 0);
	set_maximum_word_len(20);
	initiate_write(list, fd, struct_name);
	line_num = find_number_line(fd, "struct_list.txt", 1, struct_name);
	if (line_num < 0)
		return (printf("3\n"));
	line_num++;
	while ((list) && (list->next))
	{
		s = (char *)list->content;
		if (s)
		{
			write_line(fd, "struct_list.txt", line_num++, 1, s);
		}
		s = (char *)list->type;
		if (s)
		{
			write_line(fd, "struct_list.txt", line_num++, 1, s);
		}
		list = list->next;
	}
	write(fd, "\n\n", 2);
	return (0);
}

/*
int	main()
{
	t_typelist	*list;
	t_typelist	*temp;
	int			counter;

	list = NULL;
	if (obtain_list("car", &list) != 0)
		return (printf("\nErrore in fase di parsing\n"));
	counter = 1;
	if (save_struct("s_car", list) != 0)
		return (printf("\nErrore in fase di salvataggio.\n"));
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
	return (0);
}
*/
