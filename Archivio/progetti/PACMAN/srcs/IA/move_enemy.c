/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:08:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/06 01:48:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	move_one(t_data *data, t_entity *enemy, int i);
static void	move_to_random(int where, int coord[2]);
static void	move_to_player(t_map **map, int coord[2], int i);

void	move_enemies(t_data *data)
{
	int	i;

	i = 0;
	while (data->enemy[i].type != EN_LAST)
	{
		move_one(data, &data->enemy[i], i);
		++i;
	}
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
			printf("NIGERUDAYO, SMOKEY[%d]!\n", enemy->id);
			enemy->triggered = true;
		}
	}
	coord[X] = enemy->pos[X];
	coord[Y] = enemy->pos[Y];
	if (enemy->triggered == true && enemy->update_path == true)
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

static void	move_to_random(int where, int coord[2])
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

static void	move_to_player(t_map **map, int coord[2], int i)
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

void	update_enemy_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->enemy[i].type)
	{
		data->enemy[i].update_path = true;
		++i;
	}
}
