/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 16:31:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

/*
	If, on the map, there is something different than
	X01$, it means something is not reachable.
	Therefore, the map is invalid.
*/
int	check_floodfill_result(t_input *input, t_map *map)
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;

	x = 0;
	y = 0;
	size_x = input->game_size_w;
	size_y = input->game_size_h;
	while (y != size_y)
	{
		x = 0;
		while (x != size_x)
		{
			if (!ft_strchr("X01$", map->position[x][y].value))
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}

/*
	We place X all around the map, starting from player.
	We don't place an X if we found another X, $, or 1.
*/
void	floodfill(t_map *map, int x, int y)
{
	if (map->position[x][y].value == 'E')
	{
		map->position[x][y].value = 'X';
		return ;
	}
	if ((map->position[x][y].value == '1') || \
	(map->position[x][y].value == 'X') || \
	(map->position[x][y].value == '$'))
		return ;
	if (map->position[x][y].value == 'C')
		map->collectable_left -= 1;
	map->position[x][y].value = 'X';
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

/*
	If the exit or a collectable are not reachable, CRACK.
	We use floodfill for this task.
*/
int	last_chk_path(t_input *input, t_map *map)
{
	int	x;
	int	y;

	map->collectable_left = map->collectable_num;
	find_stuff(map, 'P', &x, &y);
	floodfill(map, x, y);
	if ((input->create_map == CREATE) && (map->collectable_left != 0))
		return (1);
	if (check_floodfill_result(input, map) == 1)
		return (1);
	return (0);
}
