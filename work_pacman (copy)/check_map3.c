/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 16:11:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

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
			if (!ft_strchr("X01", map->position[x][y].value))
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}

void	floodfill(t_map *map, int x, int y)
{
	if ((map->position[x][y].value == '1') || \
	(map->position[x][y].value == 'X'))
		return ;
	map->position[x][y].value = 'X';
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

int	last_chk_path(t_input *input, t_map *map)
{
	int	x;
	int	y;

	find_stuff(map, 'P', &x, &y);
	floodfill(map, x, y);
	if (check_floodfill_result(input, map) == 1)
		return (1);
	return (0);
}
