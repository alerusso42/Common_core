/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 15:39:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	count_stuff(t_map *map, t_onebyte character, \
int size_x, int size_y);
int	first_chk_char(t_input *input, t_map *map);
int	find_stuff(t_map *map, t_onebyte c, int *x, int *y);
int	last_chk_path(t_input *input, t_map *map);

int	find_stuff(t_map *map, t_onebyte c, int *x, int *y)
{
	int	size_x;
	int	size_y;

	*y = 0;
	size_x = map->game_size_w;
	size_y = map->game_size_h;
	while (*y != size_y)
	{
		*x = 0;
		while (*x != size_x)
		{
			if (c == map->position[*x][*y].value)
				return (0);
			(*x)++;
		}
		(*y)++;
	}
	return (1);
}

int	sixth_chk_colet(t_map *map, int size_x, int size_y)
{
	if (count_stuff(map, 'E', size_x, size_y) < 1)
		return (1);
	return (0);
}

int	fifth_chk_enemy(t_map *map, int size_x, int size_y)
{
	int	enemy_num;

	enemy_num = map->variable_3_enemy_num;
	if (count_stuff(map, '$', size_x, size_y) != enemy_num)
		return (l_printf("\nAAA\n"), 1);
	return (0);
}

int	first_chk_char(t_input *input, t_map *map)
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
			if (!ft_strchr(input->valid_signs, map->position[x][y].value))
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}
