/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:08:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/13 00:37:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	move_to_random(int where, int coord[2])
{
	if (where == DOWN)
		coord[Y] += 1;
	else if (where == UP)
		coord[Y] -= 1;
	else if (where == LEFT)
		coord[X] -= 1;
	else if (where == RIGHT)
		coord[X] += 1;
}

void	move_to_player(t_map **map, int coord[2], int i)
{
	map[coord[Y]][coord[X]].distance[i] = 0;
	if (map[coord[Y] + 1][coord[X]].distance[i] < 0)
		coord[Y] += 1;
	else if (map[coord[Y] - 1][coord[X]].distance[i] < 0)
		coord[Y] -= 1;
	else if (map[coord[Y]][coord[X] - 1].distance[i] < 0)
		coord[X] -= 1;
	else if (map[coord[Y]][coord[X] + 1].distance[i] < 0)
		coord[X] += 1;
}

void	run_from_player(t_map **map, int coord[2], int i)
{
	map[coord[Y]][coord[X]].distance[i] = 0;
	if (map[coord[Y] + 1][coord[X]].distance[i] < 0)
		coord[Y] -= 1;
	else if (map[coord[Y] - 1][coord[X]].distance[i] < 0)
		coord[Y] += 1;
	else if (map[coord[Y]][coord[X] - 1].distance[i] < 0)
		coord[X] += 1;
	else if (map[coord[Y]][coord[X] + 1].distance[i] < 0)
		coord[X] -= 1;
}
