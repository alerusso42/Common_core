/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_pacman.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 07:27:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 07:48:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

static void	*right_left(t_all *all, int dialga);
static void	*up_down(t_all *all, int dialga);
static int	register_frame_from_dialga(int dialga);

void	*which_pac_man(t_all *all, int dialga)
{
	if ((all->map->p_dir == RIGHT) || (all->map->p_dir == LEFT))
		return (right_left(all, dialga));
	else
		return (up_down(all, dialga));
}

static void	*right_left(t_all *all, int dialga)
{
	static int	frame;

	frame = register_frame_from_dialga(dialga);
	if (all->map->p_dir == RIGHT)
	{
		if (frame == OPEN)
			return (all->mlx->sprite->pac_open_right);
		if (frame == HALF)
			return (all->mlx->sprite->pac_half_right);
		if (frame == CLOSE)
			return (all->mlx->sprite->pac_close_right);
	}
	if (all->map->p_dir == LEFT)
	{
		if (frame == OPEN)
			return (all->mlx->sprite->pac_open_left);
		if (frame == HALF)
			return (all->mlx->sprite->pac_half_left);
		if (frame == CLOSE)
			return (all->mlx->sprite->pac_close_left);
	}
	return (NULL);
}

static void	*up_down(t_all *all, int dialga)
{
	static int	frame;

	frame = register_frame_from_dialga(dialga);
	if (all->map->p_dir == UP)
	{
		if (frame == OPEN)
			return (all->mlx->sprite->pac_open_up);
		if (frame == HALF)
			return (all->mlx->sprite->pac_half_up);
		if (frame == CLOSE)
			return (all->mlx->sprite->pac_close_up);
	}
	if (all->map->p_dir == DOWN)
	{
		if (frame == OPEN)
			return (all->mlx->sprite->pac_open_down);
		if (frame == HALF)
			return (all->mlx->sprite->pac_half_down);
		if (frame == CLOSE)
			return (all->mlx->sprite->pac_close_down);
	}
	return (NULL);
}

static int	register_frame_from_dialga(int dialga)
{
	if ((dialga % 24030 <= 5340) || (dialga % 24030 >= 21360))
		return (OPEN);
	if (((dialga % 24030 > 5340) && (dialga % 24030 < 13350)) || \
	((dialga % 24030 > 16020) && (dialga % 24030 < 21360)))
		return (HALF);
	if ((dialga % 24030 >= 13350) && (dialga % 24030 <= 16020))
		return (CLOSE);
	return (-1);
}
