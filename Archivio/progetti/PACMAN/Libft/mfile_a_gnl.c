/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_a_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:38:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 22:59:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

char		*get_static_buffer(int fd, bool reset, bool reset_all);
static void	read_from_file(char *buffer, t_fd fd, char **new_line);
static int	read_from_buff(char *buffer, char **old_content);
/*
//TODO - 
			1)	strlen fatto bene;
			2)	strstr fatto bene;
			3)	strstr che calcoli lunghezza (sub_strlen);
			4)	strstr che copi (sub_strcpy);
			5)	una funzione che legga e che aggiorni l'fd;
			6)	una integrazione di queste funzioni con gli fd;
			7)	read_line riceverà l'offset di dove trovare le info nel buffer;
			8)	Algoritmo di hashing e ricerca.
*/
char	*gnl(void)
{
	char	*buffer;
	t_fd	fd;
	char	*old_content;
	char	*new_line;

	old_content = NULL;
	if (!get_filedata(&fd, NULL))
		return (NULL);
	buffer = get_static_buffer(fd.n, 0, 0);
	if (read_from_buff(buffer, &old_content) == 1)
		return (old_content);
	read_from_file(buffer, fd, &new_line);
	new_line = ft_strjoin_which(old_content, new_line, 3);
	return (new_line);
}

char	*get_static_buffer(int fd, bool reset, bool reset_all)
{
	t_manage_fds	*data;
	int				i;

	data = fd_database(0);
	if (reset_all)
	{
		i = 1;
		while (i != data->last + 1)
		{
			get_static_buffer(i, 1, 0);
			++i;
		}
	}
	else if (reset)
	{
		i = 0;
		while (i != BUFFER_SIZE + 1)
		{
			data->buffer[fd][i] = 0;
			i++;
		}
	}
	return (data->buffer[fd]);
}

static int	read_from_buff(char *buffer, char **old_content)
{
	int		i;
	char	*s;

	if (buffer[0] == '\0')
		return (0);
	i = sub_strlen(buffer, "\n", EXCLUDE);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (0);
	sub_strcpy(s, buffer, "\n", EXCLUDE);
	if (*old_content)
		*old_content = ft_strjoin_which(*old_content, s, 3);
	else
		*old_content = s;
	if (buffer[i] == '\n')
		return (cut_string(buffer, 0, i), 1);
	cut_string(buffer, 0, i);
	return (0);
}

static void	read_from_file(char *buffer, t_fd fd, char **new_line)
{
	int		bytes_read;
	int		diff;

	bytes_read = 0;
	diff = 0;
	*new_line = NULL;
	while (ft_strchr(buffer, '\n') == NULL)
	{
		if (*buffer)
			*new_line = ft_strjoin_which(*new_line, buffer, 1);
		if (*buffer && *new_line)
			(*new_line)[bytes_read] = 0;
		bytes_read += readfd(fd, buffer, BUFFER_SIZE);
		diff = bytes_read - diff;
		if (diff != BUFFER_SIZE)
		{
			cut_string(buffer, diff, BUFFER_SIZE);
			break ;
		}
		diff = bytes_read;
		buffer[bytes_read] = 0;
	}
	read_from_buff(buffer, new_line);
}

#define POKEDEX "../tests/s.supp"

int	main(void)
{
	char	*line;
	t_fd	fd;

	fd = openfd(POKEDEX, "r");
	if (fd.n == 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = gnl();
	int c = 1;
	while (line != NULL)
	{
		printf("%s\n", line);
		SDL_free(line);
		line = gnl();
		c++;
		if (c == -1)
			break ;
	}
	del_filedata();
	return (0);
}
