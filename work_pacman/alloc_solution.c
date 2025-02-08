/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:34:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 11:48:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

int			alloc_sol(t_input **input, t_map **map);
static int	alloc_copy(t_input **input, t_map **map, int size_w, int size_h);

int	alloc_sol(t_input **input, t_map **map)
{
	int	index;
	int	size_h;
	int	size_w;

	size_w = (((*input)->game_size_w) + 2);
	size_h = ((*input)->game_size_h) + 2;
	(*map) = ft_calloc(1, sizeof(t_map));
	if ((*map) != NULL)
		(*map)->position = ft_calloc((size_w), sizeof(t_position));
	if (((*map) == NULL) || ((*map)->position) == NULL)
		return (full_reset(2, input, map), 3);
	index = -1;
	while (++index != (*input)->game_size_w + 1)
	{
		(*map)->position[index] = ft_calloc((size_h), \
		sizeof(char *) * 2);
		if ((*map)->position[index] == NULL)
			return (full_reset(2, input, map), 3);
	}
	(*map)->game_size = (*input)->game_size;
	(*map)->game_size_w = (*input)->game_size_w;
	(*map)->game_size_h = (*input)->game_size_h;
	return (alloc_copy(input, map, (*map)->game_size_w, (*map)->game_size_h));
}

static int	alloc_copy(t_input **input, t_map **map, int size_w, int size_h)
{
	int	index;

	(*map)->old_pos = ft_calloc(size_w + 2, sizeof(t_position));
	if (((*map)->old_pos) == NULL)
		return (full_reset(2, input, map), 3);
	index = -1;
	while (++index != size_w + 1)
	{
		(*map)->old_pos[index] = ft_calloc(size_h + 2, \
		sizeof(char *) * 2);
		if ((*map)->old_pos[index] == NULL)
			return (full_reset(2, input, map), 3);
	}
	return (0);
}

int	alloc_enemies(t_map *map)
{
	int	en_num;
	int	x;
	int	y;

	en_num = map->variable_3_enemy_num;
	map->enemy = (t_enemy *)ft_calloc(en_num + 1, sizeof(t_enemy));
	if (!map->enemy)
		return (1);
	y = 0;
	while (y != map->game_size_h)
	{
		x = 0;
		while (x != map->game_size_w)
		{
			map->position[x][y].distance = \
			(char *)ft_calloc(en_num + 1, sizeof(char));
			if (map->position[x][y].distance == NULL)
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}

void	fill_map(t_map **map, int row_n, int col_n)
{
	int			col;
	int			row;

	row = -1;
	col = -1;
	while ((++row != row_n + 1))
	{
		while ((++col != col_n + 1))
		{
			(*map)->position[col][row].value = 48;
		}
		col = -1;
	}
}

void	copy_map(t_map **map, int row_n, int col_n)
{
	int			col;
	int			row;

	row = -1;
	col = -1;
	while ((++row != row_n + 1))
	{
		while ((++col != col_n + 1))
		{
			(*map)->old_pos[col][row].value = 0;
		}
		col = -1;
	}
}
