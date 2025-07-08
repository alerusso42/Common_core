/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_reset_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:41:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:49:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

/*
	reset_fd reimposta read all'inizio del file, e contemporaneamente
	resetta il buffer di get_next_line.
    Se nello stock di fd era presente l'fd, lo aggiorna.
*/
int	reset_fd(t_fd fd)
{
	get_static_buffer(fd.n, 1, 0);
	return (SEEK(fd.p, 0, RW_SEEK_SET));
}
