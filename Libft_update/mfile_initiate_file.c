/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_initiate_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:58:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 16:06:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

/*
initiate_file riceve:
1) fd;
2) il nome del giocatore.
	
	initiate_file inizializza il file del giocatore.

	initiate_file non torna niente.
*/
void	initiate_file(int fd, char *name)
{
	int	counter;
	
	counter = MIDWORDS_LEN * 10;
	write(fd, "[PLAYER_", 8);
	write(fd, name, strlen(name));
	write(fd, "]", 1);
	write(fd, "\n\n", 2);
	write(fd, "Name = ", 7);
	hold_space(counter, fd);
	write(fd, "Age = ", 6);
	hold_space(counter, fd);
	write(fd, "Class = ", 8);
	hold_space(counter, fd);
	write(fd, "Species = ", 10);
	hold_space(counter, fd);
	write(fd, "Friends = ", 10);
	hold_space(counter, fd);
	write(fd, "[_ENDPLAYER_1]\n", 15);
	write(fd, "EOF\n", 4);
}