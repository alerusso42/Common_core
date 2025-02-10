/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:52:12 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/10 10:47:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static void	get_one(t_map *map, int x, int y, int enemy_num);

int	get_enemies_position(t_map *map, char search)
{
	int	x;
	int	y;
	int	enemy_num;

	y = 0;
	enemy_num = 0;
	while (y != map->game_size_h)
	{
		x = 0;
		while (x != map->game_size_w)
		{
			if (map->position[x][y].value == search)
			{
				get_one(map, x, y, enemy_num);
				enemy_num++;
			}
			++x;
		}
		++y;
	}
	return (0);
}

static void	get_one(t_map *map, int x, int y, int enemy_num)
{
	map->enemy[enemy_num].x = x;
	map->enemy[enemy_num].y = y;
	map->enemy[enemy_num].x_start = x;
	map->enemy[enemy_num].y_start = y;
	map->enemy[enemy_num].color = randomize_color(x, y, enemy_num);
	map->enemy[enemy_num].dir = FRONT;
}

int	id_enemy(t_map *map, int x, int y)
{
	int	n;

	n = 0;
	while (n != map->variable_3_enemy_num)
	{
		if ((map->enemy[n].x == x) && (map->enemy[n].y == y))
			return (n);
		++n;
	}
	return (-1);
}