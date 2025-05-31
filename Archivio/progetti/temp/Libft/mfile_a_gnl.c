/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_a_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:38:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 13:41:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

char	*get_static_buffer(int fd, bool reset, bool reset_all);
char	*read_empty_buffer(char *buffer, t_fd fd);
char	*read_until_newline(char *buffer, t_fd fd, int i);
char	*extract_ready_line(char *buffer, t_fd fd, int i);
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
char	*ggnl(void)
{
	char	*buffer;
	t_fd	fd;
	int		i;

	if (!get_filedata(&fd, NULL))
		return (NULL);
	buffer = get_static_buffer(fd.n, 0, 0);
	if (!buffer[0])
		return (read_empty_buffer(buffer, fd));
	i = sub_strlen(buffer, "\n", EXCLUDE);
	if (!buffer[i])
		return (read_until_newline(buffer, fd, i));
	return (extract_ready_line(buffer, fd, i));
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

char	*read_empty_buffer(char *buffer, t_fd fd)
{
	int		bytes_read;
	int		line_size;
	int		diff;

	bytes_read = 0;
	diff = 0;
	while (ft_strchr(buffer + bytes_read, '\n') == NULL)
	{
		bytes_read += readfd(fd.p, BUFFER_SIZE);
		diff = bytes_read - diff;
		if (diff == -1)
			return (NULL);
		if (diff != BUFFER_SIZE)
			break ;
		buffer[bytes_read] = 0;
	}
	line_size = sub_strlen(buffer, "\n", EXCLUDE);
	return (read_until_newline(buffer, fd, line_size));
}

char	*read_until_newline(char *buffer, t_fd fd, int i)
{
	char	*new_line;

	new_line = ft_calloc(i + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	sub_strcpy(new_line, buffer, "\n", EXCLUDE);
	cut_string(buffer, 0, i);
	return (new_line);
}

char	*extract_ready_line(char *buffer, t_fd fd, int i)
{
	char	*new_content;
	char	*old_content;
	char	*new_line;

	old_content = read_until_newline(buffer, fd, i);
	if (!old_content)
		return (NULL);
	new_content = read_empty_buffer(buffer, fd);
	if (!new_content)
		return (SDL_free(old_content), NULL);
	new_line = ft_strjoin_free(old_content, new_content);
	if (!new_line)
		return (SDL_free(old_content), SDL_free(new_content), NULL);
	return (new_line);
}

int	main(void)
{
	char	*line;
	t_fd	fd;

	fd = openfd("mfile_a_gnl.c", "r");
	if (fd.n == 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = ggnl();
	while (line != NULL)
	{
		printf("%s\n", line);
		SDL_free(line);
		line = ggnl();
	}
	del_filedata();
	return (0);
}
