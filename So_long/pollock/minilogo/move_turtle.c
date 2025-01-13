/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_turtle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:28:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/13 18:14:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilogo.h"

static void	move(int amount, t_turtle *turtle, int back_or_forward);
static void	update_coordinates(t_turtle *turtle, int angle);
static void	print_pixel(t_turtle *turtle, int mode);

void	forward(int amount, t_turtle *turtle)	
{
	move(amount, turtle, FORWARD);
}

void	back(int amount, t_turtle *turtle)
{
	move(amount, turtle, BACK);
}

static void	update_coordinates(t_turtle *turtle, int angle)
{
	if (angle == 0)
		turtle->y_pos += 1;
	else if (angle == 180)
		turtle->y_pos -= 1;
	else if (angle == 90)
		turtle->x_pos += 1;
	else if (angle == 270)
		turtle->x_pos -= 1;
	else
		ft_printf("\nERROR: angle %d not turtle->pos_yet implemented.\n", angle);
	if (turtle->y_pos == 360)
		turtle->y_pos = 0;
	if (turtle->y_pos == -1)
		turtle->y_pos = 359;
	if (turtle->x_pos == 360)
		turtle->x_pos = 0;
	if (turtle->x_pos == -1)
		turtle->x_pos = 359;
}

static void	print_pixel(t_turtle *turtle, int mode)
{
	static int 	color = 0XFF00FF;
	int			p;
	int			x;
	int			y;

	p = turtle->pensize;
	x = turtle->x_pos;
	y = turtle->y_pos;
	if ((turtle->angle == 0) || (turtle->angle == 180))
	{
		while (p--)
		{
			mlx_pixel_put(turtle->connection, turtle->window, x + p, y, 0XFFFFFF);
			mlx_pixel_put(turtle->connection, turtle->window, x - p, y, 0XFFFFFF);
		}
	}
	if ((turtle->angle == 90) || (turtle->angle == 270))
	{
		while (p--)
		{
			mlx_pixel_put(turtle->connection, turtle->window, x, y + p, 0XFFFFFF);
			mlx_pixel_put(turtle->connection, turtle->window, x, y + p, 0XFFFFFF);
		}
	}
	(void)mode;
}

static void	move(int amount, t_turtle *turtle, int back_or_forward)
{
	int	angle;
	
	angle = turtle->angle;
	if (back_or_forward == BACK)
		angle -= 180;
	if (angle < 0)
		angle %= -360;
	while (amount--)
	{
		if (turtle->penup == OFF)
			print_pixel(turtle, 0);
		update_coordinates(turtle, angle);
	}
}
