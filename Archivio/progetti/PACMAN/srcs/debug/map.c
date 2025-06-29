/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:59:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/29 19:20:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	print_map(t_map **map)
{
	int	y;
	int	x;

	if (!map)
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
		printf("\n");
		++y;
	}
	
}