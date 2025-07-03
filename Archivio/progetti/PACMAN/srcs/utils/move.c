/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:43:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/03 17:21:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	update_dir(t_entity *entity, int x, int y);
static int	move_player(t_data *data, t_entity *entity, int x, int y);

void	move(t_data *data, t_entity *entity, int x, int y)
{
	if (elapsed_time(entity->move.last) < entity->move.interval)
		return ;
	entity->move.last = SDL_GetTicks64();
	if (entity->type == PLAYER)
	{
		if (move_player(data, entity, x, y) == true)
			return ;
	}
	else if (data->map[y][x].val == S_PLAYER)
		data->run = false;
	else if (data->map[y][x].val == S_WALL || data->map[y][x].val == S_EXIT\
	 || 	data->map[y][x].val != S_HARD_WALL)
		return ;
	update_dir(entity, x, y);
	swap(entity->pos[X], entity->pos[Y], x, y);
	entity->pos[X] = x;
	entity->pos[Y] = y;
}

static int	move_player(t_data *data, t_entity *entity, int x, int y)
{
	if (data->map[y][x].val == S_ENEMY)
		data->run = false;
	else if (data->map[y][x].val == S_COL)
	{
		update_dir(entity, x, y);
		replace(entity->pos[X], entity->pos[Y], x, y);
		data->game.collectables -= 1;
	}
	else if (data->map[y][x].val == S_EXIT)
	{
		if (data->exit.triggered == true)
			data->run = false;
	}
	else if (data->map[y][x].val == S_FLOOR)
	{
		return (false);
	}
	return (true);
}

/*
	Takes two values on the map (dest and src).
	Dest is set to src.
	Src is set to '0' (floor).
*/
void	replace(int dest_x, int dest_y, int src_x, int src_y)
{
	t_data	*data;

	data = getter(NULL, false);
	data->map[dest_y][dest_x].val = data->map[src_y][src_x].val;
	data->map[src_y][src_x].val = S_FLOOR;
}

/*
	Takes two values on the map (dest and src).
	They are swapped.
*/
void	swap(int x1, int y1, int x2, int y2)
{
	t_data	*data;
	char	temp;

	data = getter(NULL, false);
	temp = data->map[y1][x1].val;
	data->map[y1][x1].val = data->map[y2][x2].val;
	data->map[y2][x2].val = temp;
}

/*
	Takes two distances (enemy pathfinding values) 
	on the map (dest and src).
	They are swapped.
*//*
void	replace_bfs(int new[2], int old[2], int n)
{
	static t_all	*all;
	static t_map	*map;

	if (all == NULL)
		all = storage_structs(NULL, GET);
	if (map == NULL)
		map = all->map;
	map->position[new[0]][new[1]].distance[n] = \
	map->position[old[0]][old[1]].distance[n];
	map->position[old[0]][old[1]].distance[n] = 0;
}*/

void	update_dir(t_entity *entity, int x, int y)
{
	if (x == entity->pos[X] && y == entity->pos[Y])
		entity->dir = FRONT;
	else if (x < entity->pos[X])
		entity->dir = LEFT;
	else if (x > entity->pos[X])
		entity->dir = RIGHT;
	else if (y < entity->pos[Y])
		entity->dir = UP;
	else if (y > entity->pos[Y])
		entity->dir = DOWN;
}
