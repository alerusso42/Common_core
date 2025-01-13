/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_turtle2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:56:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/13 17:48:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilogo.h"

void	home(t_turtle *turtle)
{
	turtle->x_pos = turtle->screen_center_x;
	turtle->y_pos = turtle->screen_center_y;
}

void	setxy(int x, int y, t_turtle *turtle)
{
	turtle->x_pos = x;
	turtle->y_pos = y;
}

void	clearscreen(t_turtle *turtle)
{
	int	x;
	int	y;

	y = 0;
	while (y != turtle->screen_size_y)
	{
		x = 0;
		while (x != turtle->screen_size_x)
		{
			mlx_pixel_put(turtle->connection, turtle->window, x, y, \
			turtle->screen_color);
			++x;
		}
		++y;
	}
}
