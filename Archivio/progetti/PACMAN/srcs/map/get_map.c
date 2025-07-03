/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:07:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/03 16:34:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static int	read_map(t_data *data, t_fd fd);
static int	check_map(t_data *data);

int	get_map(t_data *data, int map_id)
{
	char	**maps;
	t_fd	fd;

	data->map = free_map(data->map);
	data->old_map = free_map(data->old_map);
	if (map_id == RANDOM)
		map_id = _random(TOTAL_MAPS);
	else if (map_id < 0 || map_id >= TOTAL_MAPS)
		return (error(data, ER_MAP_ID));
	maps = daft_get("maps");
	if (!maps)
		return (error(data, ER_DAFT));
	if (check_extension_file(maps[map_id], ".ber") == 1)
		return (error(data, ER_MAP_EXTENSION));
	fd = openfd(maps[map_id], "r");
	if (!fd.n)
		return (error(data, ER_OPEN));
	file_size(data->game.map_size, fd);
	if (data->game.map_size[X] < MIN_MAP || data->game.map_size[Y] < MIN_MAP)
		return (error(data, ER_MAP_LITTLE));
	if (data->game.map_size[X] > MAX_MAP || data->game.map_size[Y] > MAX_MAP)
		return (error(data, ER_MAP_BIG));
	if (alloc_map(data) != 0 || read_map(data, fd) != 0 || check_map(data) != 0)
		return (data->last_error);
	return (print_map(data->map), 0);
}

static int	read_map(t_data *data, t_fd fd)
{
	int		y;
	int		x;
	char	*line;

	y = 1;
	line = gnl();
	while (line && *line && *line != '\n')
	{
		x = -1;
		while (line[++x])
		{
			data->map[y][x + 1].val = line[x];
			//update_global_values(data, line[x]);
		}
		SDL_free(line);
		line = gnl();
		++y;
	}
	SDL_free(line);
	closefd(fd);
	copy_map(data->old_map, data->map);
	data->game.collectables = count_stuff(data, S_COL);
	return (0);
}

static int	check_map(t_data *data)
{
	if (count_stuff(data, S_PLAYER) != 1)
		return (error(data, ER_MAP_PLAYER));
	else if (count_stuff(data, S_EXIT) != 1)
		return (error(data, ER_MAP_EXIT));
	else if (valid_path(data) == false)
		return(error(data, ER_MAP_FLOODFILL));
	return (0);
}
