#include "header.h"

int	obtain_list(char *structure_name, t_typelist **list);
/*
void hold_space(int counter, int fd)
{
	while (counter--)
		write(fd, " ", 1);
	write(fd, "\n", 1);
}*/

int		write_line_gdb(int fd, char *filename, int line_num, int position, char *string)
{
	int		counter;
	char	*temp;
	int		maximum_word_len;

	if ((fd == -1) || (!string) || (position < 0) || (line_num < 0))
		return (-1);
	position -= 1;
	reset_fd(fd, filename);
	if (line_num != 1)
	{
		while ("move the cursor to the start of the line")
		{
			if (line_num == 1)
				break ;
			temp = get_next_line(fd, 1);
			if (!temp)
				return (-1);
			if (*temp == '\n')
				--line_num;
			free(temp);
		}
	}
	temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	while ((temp[0] != ' ') && (temp[0] != '\n') && (temp[0] != '\0'))
	{
		free(temp);
		temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	}
	if ((temp[0] == '\n') || (temp[0] == '\0'))
		return (free(temp), -1);
	free(temp);
	temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	while ((temp[0] != ' ') && (temp[0] != '\n') && (temp[0] != '\0'))
	{
		free(temp);
		temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	}
	if ((temp[0] == '\n') || (temp[0] == '\0'))//Scorre fino ad arrivare a "= "
		return (free(temp), -1);
	while ((position--))
	{
		free(temp);
		temp = get_next_line(fd, 1);
		if (!temp)
			return (-1);
		while ((temp[0] != ',') && (temp[0] != '\n') && (temp[0] != '\0'))
		{
			free(temp);
			temp = get_next_line(fd, 1);
			if (!temp)
				return (-1);
		}
		if ((temp[0] == '\n') || (temp[0] == '\0'))
			return (free(temp), -1);
	}
	counter = 0;
	maximum_word_len = set_maximum_word_len(-1);
	while (counter != maximum_word_len)
	{
		if (*string)
		{
			write(fd, string, 1);
			string++;
		}
		else
			write(fd, "_", 1);
		++counter;
	}
	write (fd, ",", 1);
	while ((temp[0] == '\n') || (temp[0] == '\0'))
	{
		free(temp);
		temp = get_next_line(fd, 1);
		if (!temp)
			return (-1);
	}
	free(temp);
	return (0);
}

// Se flag è == 1, chiude il file, se esiste.
int	check_type(char *type, int flag)
{
	static int		fd;
	int				line;

	if (flag == 1)
	{
		if (fd != 0)
			close(fd);
		return (0);
	}
	if (ft_strncmp(type, "END_", 4) == 0)
		return (1);
	if (fd == 0)
		fd = open("available_types.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = find_number_line(fd, "available_types.txt", 1, type);
	if (line < 0)
		return (1);
	return (0);
}

// Se flag è == 1, libera no_brackets, se è stato allocato.
int	check_brackets(char *type, char **no_brackets, int flag)
{
	int			manage_cases;
	static void	*pointer;

	if (flag == 1)
	{
		free(pointer);
		pointer = NULL;
		return (0);
	}
	manage_cases = move_square_br(&type, no_brackets, 0);
	if (manage_cases == 2)
	{
		*no_brackets = type;
		return (2);
	}
	if (manage_cases == 0)
	{
		pointer = *no_brackets;
		return (0);
	}
	if (manage_cases == 1)
		return (1);
	return (3);
}

int	write_default_value(int fd, char *filename, int line_to_write, int fd_2, char *type)
{
	int		line_num;
	char	**matrix;
	char	*line;
	int		index;

	line_num = find_number_line(fd_2, "default_values.txt", 2, "[LIST]", type);
	if (line_num == -1)
		return (1);
	if ((strstr(type, "int*")) || (strstr(type, "char**")))
	{
		matrix = read_all_line(fd_2, "default_values.txt", line_num);
		if (!matrix)
			return (1);
		index = 0;
		while (matrix[index])
		{
			write_line_gdb(fd, filename, line_to_write, index + 1, matrix[index]);
			++index;
		}
		free_matrix(matrix);
	}
	else
	{
		line = read_line(fd_2, "default_values.txt", line_num, 1);
		if (!line)
			return (1);
		write_line(fd, filename, line_to_write, 1, line);
		free(line);
	}
	return (0);
}

void	write_types_list(int fd, char *filename, int fd_2, t_typelist *list)
{
	int		counter;
	int		line_to_write;
	char	*temp;

	if ((fd == -1) || (fd_2 == -1) || (!filename) || (!list) || !(list->next))
		return ;
	counter = 120;
	list = list->next;
	line_to_write = 5;
	while ((list) && (list->next))
	{
		temp = NULL;
		if (check_brackets((char *)list->type, &temp, 0) == 1)
			break ;
		if (check_type(temp, 0) == 0)
		{
			move_cursor(fd, filename, line_to_write);
			write(fd, (char *)list->content, ft_strlen((char *)list->content));
			write(fd, " = ", 3);
			write_default_value(fd, filename, line_to_write, fd_2, temp);
			hold_space(counter, fd);
			line_to_write++;
		}
		check_brackets(NULL, NULL, 1);
		list = list->next;
	}
	check_type(NULL, 1); //DEL
}

void	print_data(int fd, char *filename, t_typelist *list, char *data_name)
{
	int		fd_2;

	if (fd == -1)
		return ;
	reset_fd(fd, filename);
	close(fd);
	open(filename, O_RDWR | O_APPEND);
	write(fd, "[", 1);
	write(fd, data_name, ft_strlen(data_name));
	write(fd, "]\n", 2);
	fd_2 = open("default_values.txt", O_RDONLY);
	if (fd_2 == -1)
	{
		write(fd, "missing file default_values.txt\n", 32);
		return ;
	}
	write_types_list(fd, filename, fd_2, list);
	close(fd_2);
}

void	register_struct_data(char *struct_name, t_typelist *list)
{
	char	*filename;
	int		fd;
	char	buffer[1];

	*buffer = 0;
	filename = ft_strjoin(struct_name, ".txt");
	del_pointer((void **)(&filename), 1);
	filename = ft_strjoin("struct_data/", filename);
	del_pointer((void **)(&filename), 1);
	if (!filename)
		del_pointer(NULL, 2);
	if (!filename)
		return ;
	fd = open(filename, O_CREAT | O_RDWR, 0666);
	if (fd == -1)
		del_pointer(NULL, 2);
	if (fd == -1)
		return ;
	if (read(fd, buffer, 1) < 0)
	{
		del_pointer(NULL, 2);
		return ;
	}
	if (*buffer == 0)
	{
		write(fd, "SPACE FOR STRUCT DATA.\nFEEL FREE TO CHANGE THE DATA.\n\n", 54);
		print_data(fd, filename, list, "DEFAULT");
		write(fd, "\n\n", 2);
	}
	del_pointer(NULL, 2);
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