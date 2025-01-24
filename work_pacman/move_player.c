/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:45:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 15:40:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

static void	change_player_position(t_map *map, int x, int y);

void	replace(int dest_x, int dest_y, int src_x, int src_y)
{
	static t_all	*all;
	static t_map	*map;

	if (all == NULL)
		all = storage_structs(NULL, GET);
	if (map == NULL)
		map = all->map;
	map->position[dest_x][dest_y].value = map->position[src_x][src_y].value;
	map->position[src_x][src_y].value = '0';
}

void	swap(int x1, int y1, int x2, int y2)
{
	static t_all	*all;
	static t_map	*map;
	unsigned char	temp;

	if (all == NULL)
		all = storage_structs(NULL, GET);
	if (map == NULL)
		map = all->map;
	temp = map->position[x1][y1].value;
	map->position[x1][y1].value = map->position[x2][y2].value;
	map->position[x2][y2].value = temp;
}

void	move_player(t_map *map, int direction)
{
	map->p_dir = direction;
	if (direction == RIGHT)
		change_player_position(map, map->p_x + 1, map->p_y);
	if (direction == DOWN)
		change_player_position(map, map->p_x, map->p_y + 1);
	if (direction == LEFT)
		change_player_position(map, map->p_x - 1, map->p_y);
	if (direction == UP)
		change_player_position(map, map->p_x, map->p_y - 1);
}

static void	change_player_position(t_map *map, int x, int y)
{
	if (map->position[x][y].value == '1')
		return ;
	if (map->position[x][y].value == 'E')
	{
		if (map->is_solved == YES)
			end(0);
		return ;
	}
	if (map->position[x][y].value == '$')
		end(0);
	if (map->position[x][y].value == 'C')
	{
		map->collectable_num--;
		if (map->collectable_num == 0)
			map->is_solved = 1;
		replace(x, y, map->p_x, map->p_y);
	}
	else
		swap(x, y, map->p_x, map->p_y);
	map->p_x = x;
	map->p_y = y;
	return ;
}
