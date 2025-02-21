/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_hold_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:17:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 11:40:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

/*
Hold_space riceve:
1) Il numero di spazi da inserire;
2) fd.
	
	Al termine, hold_space inserisce un carattere di nuova linea \n.

	Hold space non torna niente.
*/
void	hold_space(int counter, int fd)
{
	if ((counter < 0) || (fd < 0))
		return ;
	while (counter--)
		write(fd, " ", 1);
	write(fd, "\n", 1);
}
