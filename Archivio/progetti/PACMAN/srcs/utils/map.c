/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:52:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/03 11:55:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	floodfill(t_map **map, int x, int y, int *collectables);

/*
	We found where something is on the map.
*/
int	find_stuff(t_data *data, char c, int *x, int *y)
{
	*y = 1;
	while (data->map[*y][1].val)
	{
		*x = 1;
		while (data->map[*y][*x].val)
		{
			if (c == data->map[*y][*x].val)
				return (true);
			(*x)++;
		}
		(*y)++;
	}
	return (false);
}

/*
	Counts how much time a char is put in the map.
*/
int	count_stuff(t_data *data, char c)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 1;
	while (data->map[y][1].val)
	{
		x = 1;
		while (data->map[y][x].val)
		{
			if (c == data->map[y][x].val)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

/*
	Copies all data from old_map to another map.
	It takes for granted that the size allocated for old_map
	is equal or bigger than old_map.
*/
void	copy_map(t_map **map, t_map **old_map)
{
	int	y;
	int	x;

	y = 1;
	while (old_map[y][1].val)
	{
		x = 1;
		while (old_map[y][x].val)
		{
			map[y][x].val = old_map[y][x].val;
			sub_strcpy(map[y][x].distance, old_map[y][x].distance, "", EXCLUDE);
			x++;
		}
		y++;
	}
}

/*
	If the exit or a collectable are not reachable, CRACK.
	We use floodfill for this task.
*/
int	valid_path(t_data *data)
{
	int	x;
	int	y;
	int	col;

	find_stuff(data, S_PLAYER, &x, &y);
	col = count_stuff(data, S_COL);
	floodfill(data->map, x, y, &col);
	/*if ((input->create_map == CREATE) && (map->collectable_left != 0))
		return (1);*/
	y = 1;
	while (data->map[y][1].val)
	{
		x = 1;
		while (data->map[y][x].val)
		{
			if (!ft_strchr(VALID_CHAR_AFTER_FLOODFILL, data->map[y][x].val))
				return (false);
			x++;
		}
		y++;
	}
	copy_map(data->map, data->old_map);
	return (true);
}

/*
	We place X all around the map, starting from player.
	We don't place an X if we found \0 or VALID_CHAR_AFTER_FLOODFILL.
*/
static void	floodfill(t_map **map, int x, int y, int *collectables)
{
	if (map[y][x].val == S_EXIT)
	{
		map[y][x].val = S_FMARK;
		return ;
	}
	if (ft_strchr(VALID_CHAR_AFTER_FLOODFILL, map[y][x].val) || !map[y][x].val)
		return ;
	if (map[y][x].val == S_COL)
		*collectables -= 1;
	map[y][x].val = S_FMARK;
	floodfill(map, x + 1, y, collectables);
	floodfill(map, x - 1, y, collectables);
	floodfill(map, x, y + 1, collectables);
	floodfill(map, x, y - 1, collectables);
}
