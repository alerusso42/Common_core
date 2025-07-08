/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_rw_support.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:23:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 17:00:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

int	read_curr(t_manage_fds	*data, int count)
{
	char	*buff;

	buff = data->buffer[data->curr_fd.n];
	return (SDL_ReadIO(data->curr_fd.p, buff, count));
}

int	readfd(t_fd	fd, char *buff, int count)
{
	return (SDL_ReadIO(fd.p, buff, count));
}

int	writefd(SDL_IOStream *fd, const char *s, size_t size, size_t len)
{
	(void)size;
	return (SDL_WriteIO(fd, s, len));
	return (len);
}
