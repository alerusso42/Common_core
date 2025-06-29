/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:27:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/29 19:31:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

int	alloc_map(t_data *data)
{
	int	i;

	data->map = ft_calloc(data->game.map_size[Y] + 3, sizeof(t_map *));
	if (!data->map)
		return (error(data, ER_MALLOC));
	i = -1;
	while (++i != data->game.map_size[Y] + 2)
	{
		data->map[i] = ft_calloc(data->game.map_size[X] + 3, sizeof(t_map));
		if (!data->map[i])
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
		x = 0;
		while (map[y][x].val)
		{
			SDL_free(map[y][x].distance);
			map[y][x].distance = NULL;
			++x;
		}
		SDL_free(map[y]);
		map[y] = NULL;
		++y;
	}
	SDL_free(map);
	return (NULL);
}