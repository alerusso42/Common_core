/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:52:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 14:39:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	reset_map(t_map **map)
{
	int	y;
	int	x;

	y = 1;
	while (map[y][1].val)
	{
		x = 1;
		while (map[y][x].val)
		{
			map[y][x].val = S_RESET;
			x++;
		}
		y++;
	}
}
