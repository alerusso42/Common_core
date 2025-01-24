/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:02:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 16:22:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "z_function_list.h"
#define HEIGHT 5
#define WIDTH 5

static void	search(t_position **position, int x, int y, int e[2], int distance)
{
	if (((position[x][y].distance < distance) && \
	(position[x][y].distance != 0)) || (position[x][y].value == '1'))
		return ;
	if (distance == 0)
		position[x][y].distance = -1;
	else
		position[x][y].distance = distance;
	search(position, x + 1, y, e, distance + 1);
	search(position, x - 1, y, e, distance + 1);
	search(position, x, y + 1, e, distance + 1);
	search(position, x, y - 1, e, distance + 1);
}

void	bfs(t_map *map, int start[2], int end[2])
{
	search(map->position, start[0], start[1], end, 0);
	return ;
}

void	print_path(t_position **position, int s_x, int s_y)
{
	static int	x;
	static int	y;
	
	if ((position[s_x][s_y].distance == -1) || \
	(position[s_x][s_y].value == '1'))
		return ;
	x = s_x;
	y = s_y;
	if ((position[x][y].distance > position[s_x + 1][s_y].distance) && \
	(position[s_x + 1][s_y].distance != 0))
	{
		x = s_x + 1;
		y = s_y;
	}
	if ((position[x][y].distance > position[s_x - 1][s_y].distance) && \
	(position[s_x - 1][s_y].distance != 0))
	{
		x = s_x - 1;
		y = s_y;
	}
	if ((position[x][y].distance > position[s_x][s_y + 1].distance) && \
	(position[s_x][s_y + 1].distance != 0))
	{
		x = s_x;
		y = s_y + 1;
	}
	if ((position[x][y].distance > position[s_x][s_y - 1].distance) && \
	(position[s_x][s_y - 1].distance != 0))
	{
		x = s_x;
		y = s_y - 1;
	}
	l_printf("%d, %d\n", x, y);
	print_path(position, x, y);
}

void	print_shortest_path(t_map *map, int end[2])
{
	l_printf("The shortest path between P and $ is:\n");
	print_path(map->position, end[0], end[1]);
}

*/
