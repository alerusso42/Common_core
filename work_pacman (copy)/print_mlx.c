/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:56:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/10 14:13:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static int	update_one(t_all *all, int x, int y, int dialga);
void		*pic(t_all *all, int x, int y, int dialga);

void	update_screen(t_all *all, int dialga)
{
	int	x;
	int	y;

	y = 0;
	while (y != all->map->game_size_h)
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
		++y;
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
	{
		return (which_enemy(all, x, y));
	}
	return (NULL);
}
