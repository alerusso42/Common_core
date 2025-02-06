/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:06:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 16:29:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	alloc_mlx(t_mlx **mlx)
{
	*mlx = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	if (!(*mlx))
		return (1);
	(*mlx)->sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!(*mlx)->sprite)
		return (1);
	return (0);
}

int	get_mlx(t_mlx *mlx, int x, int y, char *dname)
{
	mlx->con = mlx_init();
	if (!mlx->con)
		return (1);
	mlx->window = mlx_new_window(mlx->con, x, y, dname);
	if (!mlx->window)
		return (1);
	mlx_settings(mlx);
	if (get_images(mlx, &mlx->variable_1_sprite_size, NULL) == 1)
		return (1);
	return (0);
}
