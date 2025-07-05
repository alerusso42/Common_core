/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:08:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 11:56:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	move_one(t_data *data, t_entity *enemy);
static void	move_random(int where, int coord[2]);

void	move_enemies(t_data *data)
{
	int	i;

	i = 0;
	while (data->enemy[i].type != EN_LAST)
	{
		if (triggered(data, data->enemy[i].pos[X], data->enemy[i].pos[Y]))
		{
			if (DEBUG == true)
				printf("\033[m40Enemy %d has seen you!\n\033[m0", data->enemy[i].id);
			data->enemy[i].triggered = true;
		}
		move_one(data, &data->enemy[i]);
		++i;
	}
}

static void	move_one(t_data *data, t_entity *enemy)
{
	int	coord[2];

	if (elapsed_time(enemy->move.last) < enemy->move.interval)
		return ;
	coord[X] = enemy->pos[X];
	coord[Y] = enemy->pos[Y];
	move_random(_random(TOTAL_MOVEMENT), coord);
	move(data, enemy, coord[X], coord[Y]);
}

static void	move_random(int where, int coord[2])
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
