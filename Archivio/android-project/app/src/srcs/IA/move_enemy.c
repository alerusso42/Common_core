/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:08:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 01:31:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	move_one(t_data *data, t_entity *enemy, int i);
void	move_to_player(t_map **map, int coord[2], int i);

void	move_enemies(t_data *data)
{
	int	i;

	i = 0;
	while (data->enemy[i].type != EN_LAST)
	{
		move_one(data, &data->enemy[i], i);
		++i;
	}
	if (data->game.exit == true)
		move_one(data, &data->exit, data->game.enemy_num);
}

static void	move_one(t_data *data, t_entity *enemy, int i)
{
	int	coord[2];

	if (elapsed_time(enemy->move.last) < enemy->move.interval)
		return ;
	if (enemy->triggered == false)
	{
		if (triggered(data, enemy->pos[X], data->enemy->pos[Y]))
		{
			Mix_PlayChannel(-1, data->sdl.sound[SO_LUGIA], 0);
			enemy->triggered = true;
		}
	}
	coord[X] = enemy->pos[X];
	coord[Y] = enemy->pos[Y];
	if (enemy->triggered == true/* && enemy->update_path == true*/)
	{
		data->enemy[i].triggered = get_best_path(data, i);
		enemy->update_path = false;
	}
	if (enemy->triggered == true)
		move_to_player(data->map, coord, i);
	else
		move_to_random(_random(TOTAL_MOVEMENT), coord);
	move(data, enemy, coord[X], coord[Y]);
}

void	update_enemy_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->enemy[i].type != EN_LAST)
	{
		data->enemy[i].update_path = true;
		++i;
	}
}
