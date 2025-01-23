/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:56:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/23 15:55:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

static int	update_one(t_all *all, int x, int y, int dialga);
void	*pic(t_all *all, int x, int y, int dialga);

void	update_screen(t_all *all, int dialga)
{
	int				x;
	int				y;

	y = all->map->game_size_h;
	while (y != -1)
	{
		x = 0;
		while (x != all->map->game_size_w)
		{
			if (all->map->position[x][y].value != \
			all->map->old_pos[x][y].value)
			{
				update_one(all, x, y, dialga);
			}
			++x;
		}
		--y;
	}
}

static int	update_one(t_all *all, int x, int y, int dialga)
{
	static int	size;
	void		*picture;

	if (size == 0)
		size = all->mlx->variable_1_sprite_size;
	picture = pic(all, x, y, dialga);
	all->map->old_pos[x][y].value = all->map->position[x][y].value;
	x *= size;
	y *= size;
	y += (size * 3);
	mlx_put_image_to_window(all->mlx->con, all->mlx->window, picture, x, y);
	return (0);
}

static void	*which_pac_man(t_all *all, int dialga)
{
	if (all->map->p_dir == RIGHT)
	{
		if (dialga % 2400 <= 800)
			return (all->mlx->sprite->pac_open_right);
		if ((dialga % 2400 > 800) && (dialga % 2400 < 1600))
			return (all->mlx->sprite->pac_half_right);
		if (dialga % 2400 >= 1600)
			return (all->mlx->sprite->pac_close_right);
	}
	if (all->map->p_dir == DOWN)
	{
		if (dialga % 2400 <= 800)
			return (all->mlx->sprite->pac_open_down);
		if ((dialga % 2400 > 800) && (dialga % 2400 < 1600))
			return (all->mlx->sprite->pac_half_down);
		if (dialga % 2400 >= 1600)
			return (all->mlx->sprite->pac_close_down);
	}
	if (all->map->p_dir == LEFT)
	{
		if (dialga % 2400 <= 800)
			return (all->mlx->sprite->pac_open_left);
		if ((dialga % 2400 > 800) && (dialga % 2400 < 1600))
			return (all->mlx->sprite->pac_half_left);
		if (dialga % 2400 >= 1600)
			return (all->mlx->sprite->pac_close_left);
	}
	if (all->map->p_dir == UP)
	{
		if (dialga % 2400 <= 800)
			return (all->mlx->sprite->pac_open_up);
		if ((dialga % 2400 > 800) && (dialga % 2400 < 1600))
			return (all->mlx->sprite->pac_half_up);
		if (dialga % 2400 >= 1600)
			return (all->mlx->sprite->pac_close_up);
	}
	return (NULL);
}

void	*pic(t_all *all, int x, int y, int dialga)
{
	if (all->map->position[x][y].value == '1')
		return (all->mlx->sprite->wall_total);
	if (all->map->position[x][y].value == '0')
		return (all->mlx->sprite->floor);
	if (all->map->position[x][y].value == 'P')
	{
		return (which_pac_man(all, dialga));
	}
	if (all->map->position[x][y].value == 'C')
		return (all->mlx->sprite->dot);
	if (all->map->position[x][y].value == 'E')
		return (all->mlx->sprite->close_exit);
	if (all->map->position[x][y].value == '$')
		return (all->mlx->sprite->red_front);
	return (NULL);                                                                                                                                                                                                                                                                                                                                          
}