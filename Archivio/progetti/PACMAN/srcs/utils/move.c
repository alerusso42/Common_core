/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:43:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/13 00:49:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	update_dir(t_entity *entity, int x, int y);
static int	move_player(t_data *data, t_entity *entity, int x, int y);

void	move(t_data *data, t_entity *entity, int x, int y)
{
	char	tile;

	update_dir(entity, x, y);
	tile = data->map[y][x].val;
	entity->move.last = SDL_GetTicks();
	if (entity->type == PLAYER)
	{
		if (move_player(data, entity, x, y) == true)
			return ;
	}
	else if (tile == S_PLAYER)
		data->run = false;
	else if (tile == S_ENEMY || tile == S_EXIT || \
	tile == S_WALL || tile == S_HARD_WALL)
		return ;
	swap(entity, x, y);
	entity->pos[X] = x;
	entity->pos[Y] = y;
}

static int	move_player(t_data *data, t_entity *entity, int x, int y)
{
	if (data->map[y][x].val == S_ENEMY)
		data->run = false;
	else if (data->map[y][x].val == S_COL)
	{
		replace(entity, x, y);
		update_enemy_path(data);
		data->game.collectables -= 1;
	}
	else if (data->map[y][x].val == S_EXIT)
	{
		if (data->exit.triggered == true)
			data->run = false;
	}
	else if (data->map[y][x].val == S_FLOOR)
	{
		update_enemy_path(data);
		return (false);
	}
	return (true);
}

/*
	Takes two values on the map (dest and src).
	Dest is set to src.
	Src is set to '0' (floor).
*/
void	replace(t_entity *entity, int x, int y)
{
	t_data	*data;

	data = getter(NULL, false);
	data->map[y][x].val = data->map[entity->pos[Y]][entity->pos[X]].val;
	data->map[entity->pos[Y]][entity->pos[X]].val = S_FLOOR;
	data->old_map[entity->pos[Y]][entity->pos[X]].val = -1;
	entity->pos[X] = x;
	entity->pos[Y] = y;
	animate_one(data, entity);
}

/*
	Takes two values on the map (dest and src).
	They are swapped.
*/
void	swap(t_entity *entity, int x, int y)
{
	t_data	*data;
	char	temp;

	data = getter(NULL, false);
	temp = data->map[y][x].val;
	data->map[y][x].val = data->map[entity->pos[Y]][entity->pos[X]].val;
	data->map[entity->pos[Y]][entity->pos[X]].val = temp;
	data->old_map[entity->pos[Y]][entity->pos[X]].val = -1;
	entity->pos[X] = x;
	entity->pos[Y] = y;
	animate_one(data, entity);
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
