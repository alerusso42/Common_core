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

void	write_default_value(int fd, char *filename, char *type)
{
	int		line_num;
	char	**matrix;
	char	*line;
	int		index;
	int		fd_2;

	fd_2 = open("default_values.txt", O_RDONLY);
	line_num = find_number_line(fd_2, "default_values.txt", 2, "[LIST]", type);
	if (line_num == -1)
		return ;
	if ((strstr(type, "int*")) || (strstr(type, "char**")))
	{
		matrix = read_all_line(fd_2, "default_values.txt", line_num);
		if (!matrix)
			return ;
		index = 1;
		while (matrix[index])
		{
			write_line(fd, filename, line_num, index, matrix[index]);
		}
		free_matrix(matrix);
		return ;
	}
	line = read_line(fd_2, filename, line_num, 1);
	if (!line)
		return ;
	write_line(fd, filename, line_num, 1, line);
	free(line);
}

void	write_types_list(int fd, char *filename, t_typelist *list)
{
	int	counter;

	if ((fd == -1) || (!filename) || (!list) || (!(list->next)))
		return ;
	counter = 120;
	reset_fd(fd, filename);
	close(fd);
	open(filename, O_RDWR | O_APPEND);
	list = list->next;
	while ((list) && (list->next))
	{
		write(fd, (char *)list->type, ft_strlen((char *)list->type));
		write(fd, " = ", 3);
		write_default_value(fd, filename, list->type);
		hold_space(counter, fd);
		list = list->next;
	}
}

void	print_default_data(int fd, char *filename, t_typelist *list)
{
	int		fd_2;
	int		line_num;

	if (fd == -1)
		return ;
	write(fd, "SPACE FOR STRUCT DATA.\nFEEL FREE TO CHANGE THE DATA.\n\n", 54);
	write(fd, "[DEFAULT]\n", 10);
	fd_2 = open("default_values.txt", O_RDONLY);
	line_num = find_number_line(fd, "default_values.txt", 1, "[LIST]");
	if (line_num == -1)
		return ;
	line_num++;
	close(fd_2);
	write_types_list(fd, filename, list);
}

void	register_struct_data(char *struct_name, t_typelist *list)
{
	char	*filename;
	int		fd;
	char	buffer[1];
	char	*save;

	filename = ft_strjoin(struct_name, ".txt");
	save = filename;
	filename = ft_strjoin("struct_data/", filename);
	if (save)
		free(save);
	if (!filename)
		return ;
	fd = open(filename, O_CREAT | O_RDWR, 0666);
	if (fd == -1)
		return ;
	if (read(fd, buffer, 1) < 0)
		return ;
	if (*buffer == 0)
	{
		print_default_data(fd, filename, list);
		write(fd, "\n\n", 2);
	}
	free(filename);
	close(fd);
}

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
	t_typelist	*save;

	save = list;
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
	register_struct_data(struct_name, save);
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
