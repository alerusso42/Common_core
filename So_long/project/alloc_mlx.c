/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:06:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/21 18:25:02 by alerusso         ###   ########.fr       */
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
	mlx->connection = mlx_init();
	if (!mlx->connection)
		return (1);
	mlx->window = mlx_new_window(mlx->connection, x, y, dname);
	//get_images(mlx);
	return (0);
}