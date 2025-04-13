/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_memory2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:00:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

void	reset_enemies(t_map *map, int index, int y_size)
{
	int	y;

	y = 0;
	while (y != y_size)
	{
		free(map->position[index][y].distance);
		map->position[index][y].distance = NULL;
		++y;
	}
	free(map->enemy);
	map->enemy = NULL;
}
