/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_a_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:38:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/19 12:44:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

char	*get_static_buffer(int fd, bool reset, bool reset_all);

char	*gnl(void)
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