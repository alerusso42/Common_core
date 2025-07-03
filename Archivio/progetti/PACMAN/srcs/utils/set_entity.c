/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:59:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/03 18:15:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static int	alloc_enemies(t_data *data, int enemy_num);

void	set_player(t_data *data)
{
	int	x;
	int	y;

	find_stuff(data, S_PLAYER, &x, &y);
	data->player.pos[X] = x;
	data->player.pos[Y] = y;
	data->player.lifes = 3;
	data->player.frame = 0;
	data->player.last_frame = 3;
	data->player.type = PLAYER;
	update_speed(&data->player, 500, 10);
}

void	set_exit(t_data *data)
{
	int	x;
	int	y;

	find_stuff(data, S_EXIT, &x, &y);
	data->exit.pos[X] = x;
	data->exit.pos[Y] = y;
	data->exit.lifes = -1;
	data->exit.frame = 0;
	data->exit.type = EN_DOGGO;
	update_speed(&data->exit, 0, 2);
}

int	set_enemies(t_data *data)
{
	int	enemy_num;
	int	i;

	if (data->enemy)
		return (0);
	enemy_num = count_stuff(data, S_ENEMY);
	data->enemy = ft_calloc(enemy_num + 1, sizeof(t_entity));
	if (!data->enemy)
		return (error(data, ER_MALLOC));
	if (enemy_num <= 0)
		return (0);
	if (alloc_enemies(data, enemy_num) != 0)
		return (data->last_error);
	i = 0;
	while (data->enemy[i].type != enemy_num)
	{
		data->enemy[i].type = _random(TOTAL_ENEMIES);
		data->enemy[i].lifes = 1;
		data->enemy[i].triggered = false;
		data->enemy[i].spawn_time = 0;
		data->enemy[i].frame = 0;
		update_speed(&data->enemy[i], 1, 2);
		++i;
	}
	data->enemy[i].type = EN_LAST;
	return (0);
}

static int	alloc_enemies(t_data *data, int enemy_num)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	while (data->map[++y][1].val)
	{
		x = 0;
		while (data->map[y][++x].val)
		{
			if (data->map[y][x].val == S_ENEMY)
			{
				data->enemy[i].pos[X] = x;
				data->enemy[i].pos[Y] = y;
			}
			data->map[y][x].distance = ft_calloc(enemy_num + 1, sizeof(char));
			if (!data->map[y][x].distance)
				return (error(data, ER_MALLOC));
		}
	}
	return (0);
}

void	update_speed(t_entity *entity, int move_speed, int anim_speed)
{
	entity->speed = move_speed;
	entity->move.interval = (MIN_SPEED * DELTA_TIME) / move_speed;
	entity->anim.interval = (MIN_SPEED * DELTA_TIME) / anim_speed;
}
