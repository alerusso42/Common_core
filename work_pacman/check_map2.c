/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 16:28:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

int	count_stuff(t_map *map, t_onebyte character, \
int size_x, int size_y);
int	first_chk_char(t_input *input, t_map *map);
int	find_stuff(t_map *map, t_onebyte c, int *x, int *y);
int	last_chk_path(t_input *input, t_map *map);

/*
	We found where something is on the map.
*/
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

/*
	If there are not enough collectables, CRACK.
*/
int	sixth_chk_colet(t_map *map, int size_x, int size_y)
{
	if (count_stuff(map, 'C', size_x, size_y) < 1)
		return (1);
	return (0);
}

/*
	If the number of enemy is wrong, CRACK.
	In NON bonus so_long, this number is forced to zero.
*/
int	fifth_chk_enemy(t_map *map, int size_x, int size_y)
{
	int	enemy_num;

	enemy_num = map->variable_3_enemy_num;
	if (count_stuff(map, '$', size_x, size_y) != enemy_num)
		return (1);
	return (0);
}

/*
	If there is an invalid sign (see variables.c file), CRACK.
*/
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
