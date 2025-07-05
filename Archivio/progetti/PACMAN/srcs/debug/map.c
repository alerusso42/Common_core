/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:59:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 10:02:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	print_map(t_map **map, t_map **old_map)
{
	int	y;
	int	x;

	if (!map || DEBUG == false)
		return ;
	y = 0;
	while (map[y])
	{
		x = 1;
		while (map[y][x].val)
		{
			printf("%c", map[y][x].val);
			++x;
		}
		printf("\t");
		x = 0;
		while (old_map && old_map[y][++x].val)
			printf("%c", map[y][x].val);
		printf("\n");
		++y;
	}
	
}