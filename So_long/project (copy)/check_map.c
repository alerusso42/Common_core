/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/21 14:41:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	check_map(t_input *input, t_map *map, int size_x, int size_y);
int	sixth_chk_colet(t_map *map, int size_x, int size_y);
int	fifth_chk_enemy(t_map *map, int size_x, int size_y);

int	count_stuff(t_map *map, t_onebyte character, \
int size_x, int size_y)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (y != size_y)
	{
		x = 0;
		while (x != size_x)
		{
			if (character == map->position[x][y].value)
				++count;
			++x;
		}
		y++;
	}
	return (count);
}

int	fourt_chk_exit(t_map *map, int size_x, int size_y)
{
	if (count_stuff(map, 'E', size_x, size_y) != 1)
		return (1);
	return (0);
}

int	third_chk_player(t_map *map, int size_x, int size_y)
{
	if (count_stuff(map, 'P', size_x, size_y) != 1)
		return (1);
	return (0);
}

int	secon_chk_fillwall(t_map *map, int size_x, int size_y)
{
	int	y;
	int	x;

	x = 0;
	y = size_y;
	while (x != size_x - 1)
	{
		if (map->position[x][y - 1].value != '1')
			return (1);
		if (map->position[x][0].value != '1')
			return (1);
		++x;
	}
	while (y != 0)
	{
		--y;
		if (map->position[0][y].value != '1')
			return (1);
		if (map->position[size_x - 1][y].value != '1')
			return (1);
	}
	return (0);
}

int	check_map(t_input *input, t_map *map, int size_x, int size_y)
{
	if ((size_x < 2) || (size_y < 2))
		return (l_printf("x e y devono essere >= 3\n"), 1);
	if (first_chk_char(input, map) == 1)
		return (l_printf("GAME OVER1\n"));
	if (secon_chk_fillwall(map, size_x, size_y) == 1)
		return (l_printf("GAME OVER2\n"));
	if (third_chk_player(map, size_x, size_y) == 1)
		return (l_printf("GAME OVER3\n"));
	if (fourt_chk_exit(map, size_x, size_y) == 1)
		return (l_printf("GAME OVER4\n"));
	if (fifth_chk_enemy(map, size_x, size_y) == 1)
		return (l_printf("GAME OVER5\n"));
	if (sixth_chk_colet(map, size_x, size_y) == 1)
		return (l_printf("GAME OVER6\n"));
	if (last_chk_path(input, map) == 1)
		return (l_printf("GAME OVER7\n"));
	return (0);
}
