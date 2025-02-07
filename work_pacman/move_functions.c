/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:05:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/07 16:08:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

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

void	swap_bfs(int x1, int y1, int x2, int y2)
{
	static t_all	*all;
	static t_map	*map;
	unsigned char	temp;

	if (all == NULL)
		all = storage_structs(NULL, GET);
	if (map == NULL)
		map = all->map;
	temp = map->position[x1][y1].distance;
	map->position[x1][y1].distance = map->position[x2][y2].distance;
	map->position[x2][y2].distance = temp;
}
