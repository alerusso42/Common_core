/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_gnl_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:37:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/17 22:11:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

static char	*set_terminator(char *str, int index);

char	*read_from_buffer(char buff[BUFFER_SIZE + 1], SDL_RWops *fd, int bytes)
{
	int		len;
	char	*bytes_read;
	int		index;

	bytes_read = (char *)ft_calloc((bytes + 2), sizeof(char));
	if ((!bytes_read) || (!bytes))
		return (NULL);
	len = 0;
	while (buff[len] != 0)
		++len;
	index = 0;
	if ((!len) && (bytes--) && (SDL_RWread(fd, bytes_read + index++, 1) < 1))
		return (SDL_free(bytes_read), NULL);
	while ((bytes) && (len--))
	{
		bytes_read[index] = buff[index];
		++index;
		--bytes;
	}
	while (bytes--)
		if (read(fd, bytes_read + index++, 1) < 1)
			break ;
	return (set_terminator(bytes_read, index));
}

static char	*set_terminator(char *str, int index)
{
	str[index] = 0;
	return (str);
}
