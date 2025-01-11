/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tries2.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:59:16 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/05 12:14:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_TRIES2_H
# define SOLVE_TRIES2_H
# include "types.h"

void	place_to_fill(t_solution *solution, int *end_cycle);

/* 	Aggiorna end_cycle della funzione cycle
	di solve_tries.h.
*/
void	place_to_fill(t_solution *solution, int *end_cycle)
{
	int			x;
	int			y;

	y = -1;
	x = -1;
	while ((++y != solution->game_size))
	{
		while ((++x != solution->game_size))
		{
			if (solution->position[x][y].value == 0)
				*end_cycle += 1;
		}
		x = -1;
	}
}

#endif