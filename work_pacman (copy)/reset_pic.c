/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_pic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:55:09 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 16:30:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

static int	reset_pic2(t_mlx *mlx);
static int	reset_pic3(t_mlx *mlx);
static int	reset_pic4(t_mlx *mlx);
static void	*del(t_mlx *mlx, void *pic);

static void	*del(t_mlx *mlx, void *pic)
{
	mlx_destroy_image(mlx->con, pic);
	return (NULL);
}

int	reset_pic(t_mlx *mlx)
{
	if (mlx->sprite->blue)
		mlx->sprite->blue = del(mlx, mlx->sprite->blue);
	if (mlx->sprite->cian_down)
		mlx->sprite->cian_down = del(mlx, mlx->sprite->cian_down);
	if (mlx->sprite->cian_front)
		mlx->sprite->cian_front = del(mlx, mlx->sprite->cian_front);
	if (mlx->sprite->cian_left)
		mlx->sprite->cian_left = del(mlx, mlx->sprite->cian_left);
	if (mlx->sprite->cian_right)
		mlx->sprite->cian_right = del(mlx, mlx->sprite->cian_right);
	if (mlx->sprite->cian_up)
		mlx->sprite->cian_up = del(mlx, mlx->sprite->cian_up);
	if (mlx->sprite->close_exit)
		mlx->sprite->close_exit = del(mlx, mlx->sprite->close_exit);
	if (mlx->sprite->dead)
		mlx->sprite->dead = del(mlx, mlx->sprite->dead);
	if (mlx->sprite->dot)
		mlx->sprite->dot = del(mlx, mlx->sprite->dot);
	if (mlx->sprite->exit)
		mlx->sprite->exit = del(mlx, mlx->sprite->exit);
	if (mlx->sprite->floor)
		mlx->sprite->floor = del(mlx, mlx->sprite->floor);
	if (mlx->sprite->orange_down)
		mlx->sprite->orange_down = del(mlx, mlx->sprite->orange_down);
	return (reset_pic2(mlx));
}

static int	reset_pic2(t_mlx *mlx)
{
	if (mlx->sprite->orange_front)
		mlx->sprite->orange_front = del(mlx, mlx->sprite->orange_front);
	if (mlx->sprite->orange_left)
		mlx->sprite->orange_left = del(mlx, mlx->sprite->orange_left);
	if (mlx->sprite->orange_right)
		mlx->sprite->orange_right = del(mlx, mlx->sprite->orange_right);
	if (mlx->sprite->orange_up)
		mlx->sprite->orange_up = del(mlx, mlx->sprite->orange_up);
	if (mlx->sprite->pac_close_down)
		mlx->sprite->pac_close_down = del(mlx, mlx->sprite->pac_close_down);
	if (mlx->sprite->pac_close_left)
		mlx->sprite->pac_close_left = del(mlx, mlx->sprite->pac_close_left);
	if (mlx->sprite->pac_close_right)
		mlx->sprite->pac_close_right = del(mlx, mlx->sprite->pac_close_right);
	if (mlx->sprite->pac_close_up)
		mlx->sprite->pac_close_up = del(mlx, mlx->sprite->pac_close_up);
	if (mlx->sprite->pac_dead_1)
		mlx->sprite->pac_dead_1 = del(mlx, mlx->sprite->pac_dead_1);
	if (mlx->sprite->pac_dead_2)
		mlx->sprite->pac_dead_2 = del(mlx, mlx->sprite->pac_dead_2);
	if (mlx->sprite->pac_dead_3)
		mlx->sprite->pac_dead_3 = del(mlx, mlx->sprite->pac_dead_3);
	if (mlx->sprite->pac_dead_4)
		mlx->sprite->pac_dead_4 = del(mlx, mlx->sprite->pac_dead_4);
	return (reset_pic3(mlx));
}

static int	reset_pic3(t_mlx *mlx)
{
	if (mlx->sprite->pac_half_down)
		mlx->sprite->pac_half_down = del(mlx, mlx->sprite->pac_half_down);
	if (mlx->sprite->pac_half_left)
		mlx->sprite->pac_half_left = del(mlx, mlx->sprite->pac_half_left);
	if (mlx->sprite->pac_half_right)
		mlx->sprite->pac_half_right = del(mlx, mlx->sprite->pac_half_right);
	if (mlx->sprite->pac_half_up)
		mlx->sprite->pac_half_up = del(mlx, mlx->sprite->pac_half_up);
	if (mlx->sprite->pac_open_down)
		mlx->sprite->pac_open_down = del(mlx, mlx->sprite->pac_open_down);
	if (mlx->sprite->pac_open_left)
		mlx->sprite->pac_open_left = del(mlx, mlx->sprite->pac_open_left);
	if (mlx->sprite->pac_open_right)
		mlx->sprite->pac_open_right = del(mlx, mlx->sprite->pac_open_right);
	if (mlx->sprite->pac_open_up)
		mlx->sprite->pac_open_up = del(mlx, mlx->sprite->pac_open_up);
	if (mlx->sprite->purple_down)
		mlx->sprite->purple_down = del(mlx, mlx->sprite->purple_down);
	if (mlx->sprite->purple_front)
		mlx->sprite->purple_front = del(mlx, mlx->sprite->purple_front);
	if (mlx->sprite->purple_left)
		mlx->sprite->purple_left = del(mlx, mlx->sprite->purple_left);
	if (mlx->sprite->purple_right)
		mlx->sprite->purple_right = del(mlx, mlx->sprite->purple_right);
	return (reset_pic4(mlx));
}

static int	reset_pic4(t_mlx *mlx)
{
	if (mlx->sprite->purple_up)
		mlx->sprite->purple_up = del(mlx, mlx->sprite->purple_up);
	if (mlx->sprite->red_down)
		mlx->sprite->red_down = del(mlx, mlx->sprite->red_down);
	if (mlx->sprite->red_front)
		mlx->sprite->red_front = del(mlx, mlx->sprite->red_front);
	if (mlx->sprite->red_left)
		mlx->sprite->red_left = del(mlx, mlx->sprite->red_left);
	if (mlx->sprite->red_right)
		mlx->sprite->red_right = del(mlx, mlx->sprite->red_right);
	if (mlx->sprite->red_up)
		mlx->sprite->red_up = del(mlx, mlx->sprite->red_up);
	if (mlx->sprite->special_dot)
		mlx->sprite->special_dot = del(mlx, mlx->sprite->special_dot);
	if (mlx->sprite->wall_down)
		mlx->sprite->wall_down = del(mlx, mlx->sprite->wall_down);
	if (mlx->sprite->wall_left)
		mlx->sprite->wall_left = del(mlx, mlx->sprite->wall_left);
	if (mlx->sprite->wall_right)
		mlx->sprite->wall_right = del(mlx, mlx->sprite->wall_right);
	if (mlx->sprite->wall_total)
		mlx->sprite->wall_total = del(mlx, mlx->sprite->wall_total);
	if (mlx->sprite->wall_up)
		mlx->sprite->wall_up = del(mlx, mlx->sprite->wall_up);
	return (0);
}
