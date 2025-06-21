/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:18:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 10:25:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rewrite_file(t_data *data, char *filedest, char *filesrc)
{
	int		fd_dest;
	int		fd_src;
	char	*line;

	fd_dest = open(filedest, P_CREATE, 0777);
	if (fd_dest < 0)
		error(data, ER_OPEN);
	fd_src = open(filesrc, P_EXIST, 0777);
	if (fd_src < 0)
	{
		close(fd_dest);
		return ;
	}
	line = get_next_line(fd_src, false);
	while (line)
	{
		fd_printf(fd_dest, "%s", line);
		free(line);
		line = get_next_line(fd_src, false);
	}
	close(fd_src);
	close(fd_dest);
}
