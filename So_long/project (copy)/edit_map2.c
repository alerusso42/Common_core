/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:21:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/21 14:41:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	sort_coordinates(t_map *map, t_random *random, int *x, int *y);

void	last_step_walls(t_map *map, t_random *random)
{
	int	x;
	int	y;
	int	internal_walls;
	int	game_size;
	int	random_shuffle;

	game_size = map->game_size_w * map->game_size_h;
	random_shuffle = 0;
	internal_walls = random->variable_5_internal_wall_num;
	while (internal_walls--)
	{
		if (sort_coordinates(map, random, &x, &y) == 1)
			return ;
		map->position[x][y].value = '1';
		++random_shuffle;
		if (random_shuffle == 10)
		{
			random_shuffle = 0;
			twist_random(&random, game_size);
			sort_coordinates(NULL, NULL, NULL, NULL);
		}
	}
	sort_coordinates(NULL, NULL, NULL, NULL);
}

void	sixth_step_colet(t_map *map, t_random *random)
{
	int	x;
	int	y;
	int	collectable_num;

	collectable_num = random->variable_4_collectable_num;
	while (collectable_num--)
	{
		if (sort_coordinates(map, random, &x, &y) == 1)
			return ;
		map->position[x][y].value = 'C';
	}
	sort_coordinates(NULL, NULL, NULL, NULL);
}

void	fifth_step_enemy(t_map *map, t_random *random)
{
	int	x;
	int	y;
	int	enemy_num;

	enemy_num = random->variable_3_enemy_num;
	while (enemy_num--)
	{
		if (sort_coordinates(map, random, &x, &y) == 1)
			return ;
		map->position[x][y].value = '$';
	}
	sort_coordinates(NULL, NULL, NULL, NULL);
}
