/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:23:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 16:31:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static int	check_pic2(t_mlx *mlx);
static int	check_pic3(t_mlx *mlx);
static int	check_pic4(t_mlx *mlx);

/*
	If some picture are missing, we print it.
	This file helped me a lot during the first configuration.
*/
int	check_pic(t_mlx *mlx)
{
	if (!mlx->sprite->blue)
		return (l_printf("\nBlue not found.\n"));
	if (!mlx->sprite->cian_down)
		return (l_printf("\ncian_down not found.\n"));
	if (!mlx->sprite->cian_front)
		return (l_printf("\ncian_front not found.\n"));
	if (!mlx->sprite->cian_left)
		return (l_printf("\ncian_left not found.\n"));
	if (!mlx->sprite->cian_right)
		return (l_printf("\ncian_right not found.\n"));
	if (!mlx->sprite->cian_up)
		return (l_printf("\ncian_up not found.\n"));
	if (!mlx->sprite->close_exit)
		return (l_printf("\nclose_exit not found.\n"));
	if (!mlx->sprite->dead)
		return (l_printf("\ndead not found.\n"));
	if (!mlx->sprite->dot)
		return (l_printf("\ndot not found.\n"));
	if (!mlx->sprite->exit)
		return (l_printf("\nexit not found.\n"));
	if (!mlx->sprite->floor)
		return (l_printf("\nfloor not found.\n"));
	if (!mlx->sprite->orange_down)
		return (l_printf("\norange_down not found.\n"));
	return (check_pic2(mlx));
}

static int	check_pic2(t_mlx *mlx)
{
	if (!mlx->sprite->orange_front)
		return (l_printf("\norange_front not found.\n"));
	if (!mlx->sprite->orange_left)
		return (l_printf("\norange_left not found.\n"));
	if (!mlx->sprite->orange_right)
		return (l_printf("\norange_right not found.\n"));
	if (!mlx->sprite->orange_up)
		return (l_printf("\norange_up not found.\n"));
	if (!mlx->sprite->pac_close_down)
		return (l_printf("\npac_close_down not found.\n"));
	if (!mlx->sprite->pac_close_left)
		return (l_printf("\npac_close_left not found.\n"));
	if (!mlx->sprite->pac_close_right)
		return (l_printf("\npac_close_right not found.\n"));
	if (!mlx->sprite->pac_close_up)
		return (l_printf("\npac_close_up not found.\n"));
	if (!mlx->sprite->pac_dead_1)
		return (l_printf("\npac_dead_1 not found.\n"));
	if (!mlx->sprite->pac_dead_2)
		return (l_printf("\npac_dead_2 not found.\n"));
	if (!mlx->sprite->pac_dead_3)
		return (l_printf("\npac_dead_3 not found.\n"));
	if (!mlx->sprite->pac_dead_4)
		return (l_printf("\npac_dead_4 not found.\n"));
	return (check_pic3(mlx));
}

static int	check_pic3(t_mlx *mlx)
{
	if (!mlx->sprite->pac_half_down)
		return (l_printf("\npac_half_down not found.\n"));
	if (!mlx->sprite->pac_half_left)
		return (l_printf("\npac_half_left not found.\n"));
	if (!mlx->sprite->pac_half_right)
		return (l_printf("\npac_half_right not found.\n"));
	if (!mlx->sprite->pac_half_up)
		return (l_printf("\npac_half_up not found.\n"));
	if (!mlx->sprite->pac_open_down)
		return (l_printf("\npac_open_down not found.\n"));
	if (!mlx->sprite->pac_open_left)
		return (l_printf("\npac_open_left not found.\n"));
	if (!mlx->sprite->pac_open_right)
		return (l_printf("\npac_open_right not found.\n"));
	if (!mlx->sprite->pac_open_up)
		return (l_printf("\npac_open_up not found.\n"));
	if (!mlx->sprite->purple_down)
		return (l_printf("\npurple_down not found.\n"));
	if (!mlx->sprite->purple_front)
		return (l_printf("\npurple_front not found.\n"));
	if (!mlx->sprite->purple_left)
		return (l_printf("\npurple_left not found.\n"));
	if (!mlx->sprite->purple_right)
		return (l_printf("\npurple_right not found.\n"));
	return (check_pic4(mlx));
}

static int	check_pic4(t_mlx *mlx)
{
	if (!mlx->sprite->purple_up)
		return (l_printf("\npurple_up not found.\n"));
	if (!mlx->sprite->red_down)
		return (l_printf("\nred_down not found.\n"));
	if (!mlx->sprite->red_front)
		return (l_printf("\nred_front not found.\n"));
	if (!mlx->sprite->red_left)
		return (l_printf("\nred_left not found.\n"));
	if (!mlx->sprite->red_right)
		return (l_printf("\nred_right not found.\n"));
	if (!mlx->sprite->red_up)
		return (l_printf("\nred_up not found.\n"));
	if (!mlx->sprite->special_dot)
		return (l_printf("\nspecial dot not found.\n"));
	if (!mlx->sprite->wall_down)
		return (l_printf("\nwall_down not found.\n"));
	if (!mlx->sprite->wall_left)
		return (l_printf("\nwall_left not found.\n"));
	if (!mlx->sprite->wall_right)
		return (l_printf("\nwall_right not found.\n"));
	if (!mlx->sprite->wall_total)
		return (l_printf("\nwall_total not found.\n"));
	if (!mlx->sprite->wall_up)
		return (l_printf("\nwall_up not found.\n"));
	return (0);
}
