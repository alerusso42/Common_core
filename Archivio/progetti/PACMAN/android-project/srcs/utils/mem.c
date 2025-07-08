/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:27:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:42:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

t_data	*getter(t_data *newdata, bool update)
{
	static t_data	*data;

	if (update == true)
		data = newdata;
	return (data);
}

int	alloc_map(t_data *data)
{
	int	i;

	data->map = ft_calloc(data->game.map_size[Y] + 3, sizeof(t_map *));
	data->old_map = ft_calloc(data->game.map_size[Y] + 3, sizeof(t_map *));
	if (!data->map || !data->old_map)
		return (error(data, ER_MALLOC));
	i = -1;
	while (++i != data->game.map_size[Y] + 2)
	{
		data->map[i] = ft_calloc(data->game.map_size[X] + 3, sizeof(t_map));
		data->old_map[i] = ft_calloc(data->game.map_size[X] + 3, sizeof(t_map));
		if (!data->map[i] || !data->old_map[i])
			return (error(data, ER_MALLOC));
	}
	return (0);
}

void	*free_map(t_map **map)
{
	int	y;
	int	x;

	if (!map)
		return (NULL);
	y = 0;
	while (map[y])
	{
		x = 1;
		while (map[y][x].distance)
		{
			FREE(map[y][x].distance);
			map[y][x].distance = NULL;
			++x;
		}
		FREE(map[y]);
		map[y] = NULL;
		++y;
	}
	FREE(map);
	return (NULL);
}
