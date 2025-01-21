/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/21 14:42:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

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
			++x;
		}
		y--;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}
