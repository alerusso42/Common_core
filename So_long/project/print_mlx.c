/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:56:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/22 17:11:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

static int	update_one(t_all *all, int x, int y);
static void	*pic(t_all *all, int x, int y);

int	update_screen(void *param)
{
	int				x;
	int				y;
	static t_all	*all;

	(void)param;
	if (all == NULL)
		all = storage_structs(NULL, GET);
	y = all->map->game_size_h;
	while (y != -1)
	{
		x = 0;
		while (x != all->map->game_size_w)
		{
			if (all->map->position[x][y].value != \
			all->map->old_pos[x][y].value)
			{
				update_one(all, x, y);
			}
			++x;
		}
		--y;
	}
	return (0);
}

static int	update_one(t_all *all, int x, int y)
{
	static int	size;
	void		*picture;

	if (size == 0)
		size = all->mlx->variable_1_sprite_size * 1;
	picture = pic(all, x, y);
	all->map->old_pos[x][y].value = all->map->position[x][y].value;
	x *= size;
	y *= (size + 3);
	mlx_put_image_to_window(all->mlx->con, all->mlx->window, picture, x, y);
	return (0);
}

static void	*pic(t_all *all, int x, int y)
{
	if (all->map->position[x][y].value == '1')
		return (all->mlx->sprite->wall_total);
	if (all->map->position[x][y].value == '0')
		return (all->mlx->sprite->floor);
	if (all->map->position[x][y].value == 'P')
		return (all->mlx->sprite->pac_open_right);
	if (all->map->position[x][y].value == 'C')
		return (all->mlx->sprite->dot);
	if (all->map->position[x][y].value == 'E')
		return (all->mlx->sprite->close_exit);
	if (all->map->position[x][y].value == '$')
		return (all->mlx->sprite->red_front);
	return (NULL);                                                                                                                                                                                                                                                                                                                                          
}