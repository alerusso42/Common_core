/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:56:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/06 16:14:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static int	find_shortest_route(t_position **position, int x, int y)
{
	int	record;

	record = INT_MAX;
	if (position[x + 1][y].distance > 0)
		record = position[x + 1][y].distance;
	if ((position[x - 1][y].distance > 0) && \
	(position[x - 1][y].distance < record))
		record = position[x - 1][y].distance;
	if ((position[x][y + 1].distance > 0) && \
	(position[x][y + 1].distance < record))
		record = position[x][y + 1].distance;
	if ((position[x][y - 1].distance > 0) && \
	(position[x][y - 1].distance < record))
		record = position[x][y - 1].distance;
	if (record == position[x + 1][y].distance)
		return (1);
	if (record == position[x - 1][y].distance)
		return (2);
	if (record == position[x][y + 1].distance)
		return (3);
	if (record == position[x][y - 1].distance)
		return (4);
	return (-1);
}

static int	found_end(int x, int y, int stop_x, int stop_y)
{
	if ((x + 1 == stop_x) && (y == stop_y))
		return (1);
	if ((x - 1 == stop_x) && (y == stop_y))
		return (1);
	if ((x == stop_x) && (y + 1 == stop_y))
		return (1);
	if ((x == stop_x) && (y - 1 == stop_y))
		return (1);
	return (0);
}

static void	update_one(t_position **position, int *x, int *y, int rec)
{
		if (rec == 1)
		{
			position[*x + 1][*y].distance = -1;
			(*x)++;
		}
		if (rec == 2)
		{
			position[*x - 1][*y].distance = -1;
			(*x)--;
		}
		if (rec == 3)
		{
			position[*x][*y + 1].distance = -1;
			(*y)++;
		}
		if (rec == 4)
		{
			position[*x][*y - 1].distance = -1;
			(*y)--;
		}
}

static void	normalize_path(t_position **position, int map_x, int map_y)
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y != map_y + 1)
	{
		x = -1;
		while (++x != map_x + 1)
		{
			if (position[x][y].distance > 0)
				position[x][y].distance = 0;
		}
	}
}

int	draw_path(t_bfs *bfs)
{
	int	stop_x;
	int	stop_y;
	int	record;

	bfs->x = bfs->p_x;
	bfs->y = bfs->p_y;
	stop_x = bfs->en_x;
	stop_y = bfs->en_y;
	bfs->position[bfs->x][bfs->y].distance = -3;
	if (find_shortest_route(bfs->position, bfs->x, bfs->y) == -1)
	{
		return (normalize_path(bfs->position, bfs->map_x, bfs->map_y), NO);
	}
	while ((bfs->x != stop_x) || (bfs->y != stop_y))
	{
		if (found_end(bfs->x, bfs->y, stop_x, stop_y) == YES)
		{
			bfs->position[bfs->en_x][bfs->en_y].distance = -2;
			break ;
		}
		record = find_shortest_route(bfs->position, bfs->x, bfs->y);
		update_one(bfs->position, &bfs->x, &bfs->y, record);
	}
	return (normalize_path(bfs->position, bfs->map_x, bfs->map_y), YES);
}