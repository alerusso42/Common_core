/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:48:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/16 13:06:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilogo/minilogo.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[i++])
		++src_len;
	if (size == 0)
	{
		return (src_len);
	}
	i = 0;
	while ((src[i]) && (i < (size - 1)))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return ((size_t)src_len);
}

// TEST_START

static void	ft_move(int amount, t_turtle *turtle, int back_or_forward);
static void	ft_update_coordinates(t_turtle *turtle, int angle);
static void	ft_print_pixel(t_turtle *turtle, int mode);

void	ft_forward(int amount, t_turtle *turtle)	
{
	ft_move(amount, turtle, FORWARD);
}

void	ft_back(int amount, t_turtle *turtle)
{
	ft_move(amount, turtle, BACK);
}

static void	ft_update_coordinates(t_turtle *turtle, int angle)
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

static void	ft_print_pixel(t_turtle *turtle, int mode)
{
	static int 	color = 0XFFFFFF;
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
			mlx_pixel_put(turtle->connection, turtle->window, x + p, y, color);
			mlx_pixel_put(turtle->connection, turtle->window, x - p, y, color);
		}
	}
	if ((turtle->angle == 90) || (turtle->angle == 270))
	{
		while (p--)
		{
			mlx_pixel_put(turtle->connection, turtle->window, x, y + p, color);
			mlx_pixel_put(turtle->connection, turtle->window, x, y + p, color);
		}
	}
	(void)mode;
}

static void	ft_move(int amount, t_turtle *turtle, int back_or_forward)
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
			ft_print_pixel(turtle, 0);
		ft_update_coordinates(turtle, angle);
	}
}

// TEST_END

// cc -g -Wall -Wextra -Werror main.c minilogo/minilogo.a -Lminilibx -lmlx -lX11 -lXext -lm
int	main()
{
	int			counter;
	t_turtle	*turtle;
	t_minilibx	*libx;

	turtle = NULL;
	if (init_minilibx(&libx, SIZE_X_WINDOW, SIZE_Y_WINDOW, "PAC_MAN") == 1)
		return (2);
	if (init_turtle(&turtle, SIZE_X_WINDOW, SIZE_Y_WINDOW, libx) == 1)
		return (2);
	pendown(turtle);
	counter = 4;
	pensize(1, turtle);
	while (counter--)
	{
		ft_forward(50, turtle);
		right(90, turtle);
	}
	clearscreen(turtle);
	mlx_loop(libx->connection);
	free(turtle);
	free_minilibx(&libx);
	return (0);
}