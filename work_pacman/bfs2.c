/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:02:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/27 03:40:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"
#define MAP_X 20
#define MAP_Y 23
#define PRINT 0
#define WALL 2

int	en_x;
int	en_y;
int	p_x;
int	p_y;

int	find_shortest_route(t_position position[MAP_X][MAP_Y], int x, int y)
{
	int	record;

	record = 2000000;
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
/*		*/

int		found_end(int x, int y, int stop_x, int stop_y)
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

void	update_one(t_position position[MAP_X][MAP_Y], int *x, int *y, int rec)
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

void	normalize_path(t_position position[MAP_X][MAP_Y])
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y != MAP_Y + 1)
	{
		x = -1;
		while (++x != MAP_X + 1)
		{
			if (position[x][y].distance > 0)
				position[x][y].distance = 0;
		}
	}
}

int	draw_path(t_position position[MAP_X][MAP_Y])
{
	int	x;
	int	y;
	int	stop_x;
	int	stop_y;
	int	record;

	x = p_x;
	y = p_y;
	stop_x = en_x;
	stop_y = en_y;
	position[x][y].distance = -3;
	if (find_shortest_route(position, x, y) == -1)
	{
		return (normalize_path(position), NO);
	}
	while ((x != stop_x) || (y != stop_y))
	{
		if (found_end(x, y, stop_x, stop_y) == YES)
		{
			position[en_x][en_y].distance = -2;
			break ;
		}
		record = find_shortest_route(position, x, y);
		update_one(position, &x, &y, record);
		if (PRINT >= 4)
			print(position);
	}
	return (normalize_path(position), YES);
}
