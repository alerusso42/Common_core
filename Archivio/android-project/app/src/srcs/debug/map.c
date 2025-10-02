/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:59:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 00:22:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	__putchar(char c)
{
	char	buff[2] = " ";

	buff[0] = c;
	err(buff);
}

void	print_map(t_map **map, t_map **old_map)
{
	int		y;
	int		x;

	return ;
	if (!map || DEBUG == false)
		return ;
	y = 0;
	while (map[y])
	{
		x = 1;
		while (map[y][x].val)
		{
			__putchar(map[y][x].val);
			++x;
		}
		err("\t");
		x = 0;
		while (old_map && old_map[y][++x].val)
			__putchar(map[y][x].val);
		err("\n");
		++y;
	}
}

void	print_bfs(t_map **map, int i)
{
	int	y;
	int	x;

	return ;
	if (!map || DEBUG == false)
		return ;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][++x].distance)
			if (map[y][x].distance[i] < -1)
				err("\033[35mX\033[0m");
			else
				err("O");
		err("\n");
		++y;
	}
}
