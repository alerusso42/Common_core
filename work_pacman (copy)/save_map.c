/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:51:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/06 16:11:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

int	save_map(t_map *map, int size_x, int size_y)
{
	int	fd;
	int	x;
	int	y;

	fd = open("maps/map.ber", O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (fd == -1)
		return (1);
	y = size_y - 1;
	while (y != -1)
	{
		x = 0;
		while (x != size_x)
		{
			if (write(fd, &map->position[x][y].value, 1) == -1)
				return (close(fd), 1);
			++x;
		}
		if (write(fd, "\n", 1) == -1)
			return (close(fd), 1);
		--y;
	}
	close(fd);
	return (0);
}
