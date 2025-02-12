/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 17:11:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static void	save_data(t_input *input, t_map *map, char c);

/*
	To save P and E position.
*/
static void	get_start_position(t_map *map, int x, int y, char entity)
{
	if (entity == 'P')
	{
		map->p_x = x;
		map->p_y = y;
	}
	else
	{
		map->e_x = x;
		map->e_y = y;
	}
}

/*
	Read the map from the file.
	We take the start position of P and E, and we save several
	data.
*/
t_bool	read_map(t_input *input, t_map *map)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	y = 0;
	fd = open(input->filename, O_RDONLY, 0666);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while ((line) && (y != input->game_size_h))
	{
		x = -1;
		while ((++x != input->game_size_w) && (line[x]) && (line[x] != '\n'))
		{
			map->position[x][y].value = line[x];
			if ((line[x] == 'P') || (line[x] == 'E'))
				get_start_position(map, x, y, line[x]);
			save_data(input, map, line[x]);
		}
		y++;
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), 0);
}

/*
	If the mode is READ, we count how many 
*/
static void	count_data(t_input *input, t_map *map, char c)
{
	static char	reset;

	if (reset == 0)
	{
		reset = 1;
		map->variable_3_enemy_num = 0;
		map->variable_4_collectable_num = 0;
		map->collectable_num = 0;
	}
	if (c == 'C')
	{
		map->variable_4_collectable_num++;
		map->collectable_num++;
	}
	if (input->switch_1_bonus == OFF)
		return ;
	if (c == '$')
		map->variable_3_enemy_num += 1;
}

static void	save_data(t_input *input, t_map *map, char c)
{
	static int	x;
	static int	y;

	if (y == map->game_size_h)
		return ;
	if (x == map->game_size_w)
	{
		x = 0;
		y += 1;
	}
	if (c == 'C')
		input->col.x[x] += 1;
	if (c == 'C')
		input->row.y[y] += 1;
	++x;
	count_data(input, map, c);
}
