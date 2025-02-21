/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_get_n_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:41:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 12:20:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

/*
	Richiama get_next_line n volte.
	
	Torna NULL se non trova la linea o se fallisce.
	Altrimenti, torna la linea richiesta.

	If fd == -1, Takes the fd from the stock.
*/
char	*get_n_line(int fd, int n)
{
	char	*line;

	if (fd == -1)
		get_filedata(&fd, NULL);
	if (fd < 1)
		return (NULL);
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
