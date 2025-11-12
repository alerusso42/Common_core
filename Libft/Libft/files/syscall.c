/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_rw_support.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:23:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/12 23:22:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

int	read_curr(t_manage_fds	*data, int count)
{
	char	*buff;

	buff = data->buffer[data->curr_fd.n];
	return (SDL_RWread(data->curr_fd.p, buff, sizeof(char), count));
}

int	readfd(t_fd	fd, char *buff, int count)
{
	return (SDL_RWread(fd.p, buff, sizeof(char), count));
}

int	writefd(SDL_RWops *fd, const char *s, size_t size, size_t len)
{
	return (SDL_RWwrite(fd, s, size, len));
}
