/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/23 14:08:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

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

t_bool	read_map(t_input *input, t_map *map)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	y = input->game_size_h - 1;
	fd = open(input->filename, O_RDONLY, 0666);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		x = 0;
		while ((line[x]) && (line[x] != '\n'))
		{
			map->position[x][y].value = line[x];
			if ((line[x] == 'P') || (line[x] == 'E'))
				get_start_position(map, x, y, line[x]);
			++x;
		}
		y--;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}
