/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:51:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 10:24:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	save_map(t_solution *solution, int size_x, int size_y)
{
	int	fd;
	int	x;
	int	y;

	fd = open("map.ber", O_CREAT | O_TRUNC | O_RDWR, 0666);
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
