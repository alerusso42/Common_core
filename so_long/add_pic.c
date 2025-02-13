/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 07:28:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 15:47:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

static void	get_images2(t_mlx *mlx, int *s, void *i);
static void	get_images3(t_mlx *mlx, int *s, void *i);
static void	get_images4(t_mlx *mlx, int *s, void *i);

/*
	We upload the images.
	
	s represents sprite both sprite size.
*/
int	get_images(t_mlx *mlx, int *s, void *i)
{
	i = mlx_xpm_file_to_image(mlx->con, "textures/Blue.xpm", s, s);
	mlx->sprite->blue = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Cian_down.xpm", s, s);
	mlx->sprite->cian_down = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Cian_front.xpm", s, s);
	mlx->sprite->cian_front = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Cian_left.xpm", s, s);
	mlx->sprite->cian_left = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Cian_right.xpm", s, s);
	mlx->sprite->cian_right = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Cian_up.xpm", s, s);
	mlx->sprite->cian_up = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Close_exit.xpm", s, s);
	mlx->sprite->close_exit = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Dead.xpm", s, s);
	mlx->sprite->dead = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Dot.xpm", s, s);
	mlx->sprite->dot = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Exit.xpm", s, s);
	mlx->sprite->exit = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Floor.xpm", s, s);
	mlx->sprite->floor = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Orange_down.xpm", s, s);
	mlx->sprite->orange_down = i;
	return (get_images2(mlx, s, i), check_pic(mlx));
}

static void	get_images2(t_mlx *mlx, int *s, void *i)
{
	i = mlx_xpm_file_to_image(mlx->con, "textures/Orange_front.xpm", s, s);
	mlx->sprite->orange_front = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Orange_left.xpm", s, s);
	mlx->sprite->orange_left = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Orange_right.xpm", s, s);
	mlx->sprite->orange_right = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Orange_up.xpm", s, s);
	mlx->sprite->orange_up = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_close_down.xpm", s, s);
	mlx->sprite->pac_close_down = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_close_left.xpm", s, s);
	mlx->sprite->pac_close_left = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_close_right.xpm", s, s);
	mlx->sprite->pac_close_right = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_close_up.xpm", s, s);
	mlx->sprite->pac_close_up = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_dead_1.xpm", s, s);
	mlx->sprite->pac_dead_1 = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_dead_2.xpm", s, s);
	mlx->sprite->pac_dead_2 = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_dead_3.xpm", s, s);
	mlx->sprite->pac_dead_3 = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_dead_4.xpm", s, s);
	mlx->sprite->pac_dead_4 = i;
	get_images3(mlx, s, i);
}

static void	get_images3(t_mlx *mlx, int *s, void *i)
{
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_half_down.xpm", s, s);
	mlx->sprite->pac_half_down = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_half_left.xpm", s, s);
	mlx->sprite->pac_half_left = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_half_right.xpm", s, s);
	mlx->sprite->pac_half_right = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_half_up.xpm", s, s);
	mlx->sprite->pac_half_up = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_open_down.xpm", s, s);
	mlx->sprite->pac_open_down = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_open_left.xpm", s, s);
	mlx->sprite->pac_open_left = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_open_right.xpm", s, s);
	mlx->sprite->pac_open_right = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Pac_open_up.xpm", s, s);
	mlx->sprite->pac_open_up = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Purple_down.xpm", s, s);
	mlx->sprite->purple_down = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Purple_front.xpm", s, s);
	mlx->sprite->purple_front = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Purple_left.xpm", s, s);
	mlx->sprite->purple_left = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Purple_right.xpm", s, s);
	mlx->sprite->purple_right = i;
	get_images4(mlx, s, i);
}

static void	get_images4(t_mlx *mlx, int *s, void *i)
{
	i = mlx_xpm_file_to_image(mlx->con, "textures/Purple_up.xpm", s, s);
	mlx->sprite->purple_up = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Red_down.xpm", s, s);
	mlx->sprite->red_down = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Red_front.xpm", s, s);
	mlx->sprite->red_front = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Red_left.xpm", s, s);
	mlx->sprite->red_left = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Red_right.xpm", s, s);
	mlx->sprite->red_right = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Red_up.xpm", s, s);
	mlx->sprite->red_up = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Special_dot.xpm", s, s);
	mlx->sprite->special_dot = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Wall_down.xpm", s, s);
	mlx->sprite->wall_down = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Wall_left.xpm", s, s);
	mlx->sprite->wall_left = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Wall_right.xpm", s, s);
	mlx->sprite->wall_right = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Wall_total.xpm", s, s);
	mlx->sprite->wall_total = i;
	i = mlx_xpm_file_to_image(mlx->con, "textures/Wall_up.xpm", s, s);
	mlx->sprite->wall_up = i;
}
