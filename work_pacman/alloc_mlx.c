/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:06:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 15:47:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

/*
	Allocation for the mlx struct.
*/
int	alloc_mlx(t_mlx **mlx)
{
	*mlx = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	if (!(*mlx))
		return (l_printf("MALLOC FAIL IN s_mlx\n"), 1);
	(*mlx)->sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!(*mlx)->sprite)
		return (l_printf("MALLOC FAIL IN s_mlx\n"), 1);
	return (0);
}

/*
	mlx settings sets the size of the sprites.
*/
int	get_mlx(t_mlx *mlx, int x, int y, char *dname)
{
	mlx->con = mlx_init();
	if (!mlx->con)
		return (l_printf("CONNECTION FAILED...\n"), 1);
	mlx->window = mlx_new_window(mlx->con, x, y, dname);
	if (!mlx->window)
		return (l_printf("FAILED OPENING WINDOW\n"), 1);
	mlx_settings(mlx);
	if (get_images(mlx, &mlx->variable_1_sprite_size, NULL) == 1)
		return (1);
	return (0);
}
