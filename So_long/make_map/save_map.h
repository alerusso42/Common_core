/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:51:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/15 10:14:23 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_MAP_H
# define SAVE_MAP_H
# include "types.h"
# include <unistd.h>
# include <fcntl.h>	

int	save_map(t_solution *solution, int size_x, int size_y)
{
	int	fd;
	int	x;
	int	y;

	fd = open("map.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (fd == -1)
		return (1);
	y = size_y - 1;
	while (y != -1)
	{
		x = 0;
		while (x != size_x)
		{
			if (write(fd, &solution->position[x][y].value, 1) == -1)
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

#endif