/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:41:41 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/13 16:22:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"

char	*get_n_line(int fd, int n);
int		write_fucking_line(int fd, int line_num, int position, char *string);
int		reset_fd(int fd, char *name);
char	*find_line(int flag, ...);
void	initiate_file(int fd, char *num);

void initiate_file(int fd, char *num)
{
	int	counter;
	int	temp;
	
	counter = MIDWORDS_LEN * 6;
	temp = MIDWORDS_LEN * 6;
	write(fd, "[PLAYER_", 8);
	write(fd, num, ft_strlen(num));
	write(fd, "]", 1);
	write(fd, "\n\n", 2);
	write(fd, "Name = ", 7);
	while (counter--)
		write(fd, " ", 1);
	counter = temp;
	write(fd, "\n", 1);
	write(fd, "Age = ", 7);
	while (counter--)
		write(fd, " ", 1);
	counter = temp;
	write(fd, "\n", 1);
	write(fd, "Class = ", 8);
	while (counter--)
		write(fd, " ", 1);
	counter = temp;
	write(fd, "\n", 1);
	write(fd, "Friends = ", 10);
	while (counter--)
		write(fd, " ", 1);
	counter = temp;
	write(fd, "\n", 1);
	write(fd, "[ENDPLAYER_1]\n", 14);
	write(fd, "EOF\n", 4);
	free(num);
}

int		write_fucking_line(int fd, int line_num, int position, char *string)
{
	char	buffer[1];
	int		counter;
	char	*temp;

	if ((fd == -1) || (!string))
		return (-1);
	/*close(fd);
	fd = open("updated_pokedex.txt", O_RDWR);
	if (fd == -1)
		return (-1);*/
	temp = get_n_line(fd, line_num - 1);
	if (!temp)
		return (-1);
	free(temp);
	if (read(fd, buffer, 1) <= 0)
		return (-1);
	while ((buffer[0] != ' ') && (buffer[0] != '\n') && (buffer[0] != '\0'))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
	}
	if ((buffer[0] == '\n') || (buffer[0] == '\0'))
	{
		return (-1);
	}
	while ((position--))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
		while ((buffer[0] != ' ') && (buffer[0] != '\n') && (buffer[0] != '\0'))
		{
			if (read(fd, buffer, 1) <= 0)
				return (-1);
		}
		if ((buffer[0] == '\n') || (buffer[0] == '\0'))
		{
			return (-1);
		}
	}
	counter = 0;
	while (counter != MIDWORDS_LEN)
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
	write (fd, ", ", 1);
	while ((buffer[0] == '\n') || (buffer[0] == '\0'))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
	}
	return (line_num);
}

char	*find_line(int flag, ...)
{
	va_list	list;
	char	*string;
	char	*search;
	int		fd;
	int		counter;

	va_start(list, flag);
	fd = (int)va_arg(list, int);
	counter = 1;
	string = get_next_line(fd, 0);
	if (!string)
	{
		va_end(list);
		return (NULL);
	}
	search = va_arg(list, char *);
	while ((search) && (string))
	{
		while (ft_strnstr(string, search, INT_MAX) == NULL)
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
	free(string);
	if (flag == FIND)
		return (ft_itoa(counter));
	if (flag == GET)
		return (get_n_line(fd, counter));
	if (flag == MOVE)
		return (get_n_line(fd, counter - 1));
	return ("Metti le flag ammodo, mongoloide");
}

char	*get_n_line(int fd, int n)
{
	char	*line;

	line = NULL;
	while (n--)
	{
		if (line)
			free(line);
		line = get_next_line(fd, 0);
		if (!line)
			break ;
	}
	return (line);
}

int	reset_fd(int fd, char *name)
{
	get_next_line(fd, RESET);
	close(fd);
	fd = open(name, O_RDWR);
	return (0);
}

int	main()
{
	char	*string;
	int		fd;
	int		counter;
	int		line_num;

	counter = 5;
	fd = open("updated_pokedex.txt", O_RDWR);
	if (fd == -1)
		return (1);
	while (counter--)
	{
		string = get_next_line(fd, 0);
		//printf("%s", string);
		if (string)
		{
			free(string);
		}
		else
			break ;
	}
	reset_fd(fd, "updated_pokedex.txt");
	string = find_line(FIND, 3, "CHARMANDER", "Weight", NULL);
	printf("%s\n", string);
	line_num = atoi(string);
	free(string);
	string = get_next_line(fd, 0);
	printf("%s\n", string);
	//printf("%s", string);
	free(string);
	write_fucking_line(fd, line_num, 1, "777");
	fd = open("dati_personaggio.txt", O_RDWR);
	if (fd == -1)
	{
		fd = open("dati_personaggio.txt", O_RDWR | O_CREAT);
		if (fd == -1)
			return (1);
		initiate_file(fd, ft_itoa(1));
	}
	reset_fd(fd, "dati_personaggio.txt");
	string = find_line(FIND, fd, "PLAYER_1", "Name", NULL);
	line_num = atoi(string);
	free(string);
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num++, 1, "Marco");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num++, 1, "27");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num++, 1, "Bard");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num, 1, "Gino");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num, 2, "Beppe");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num, 1, "Marco");
	return (0);
}
