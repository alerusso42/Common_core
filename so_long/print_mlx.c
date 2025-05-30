/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:56:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:36:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

static int	update_one(t_all *all, int x, int y, int dialga);
static void	get_visible_screen(t_all *all);
void		*pic(t_all *all, int x, int y, int dialga);

/*
	CORE CONCEPT: 	the map is being replaced only if there is
					a difference between the map and a copy of
					the map.

	To update the map, I just delete on values on the map.
	Then, everything will be replaced.
*/
void	update_screen(t_all *all, int dialga)
{
	int	x;
	int	y;

	get_visible_screen(all);
	y = all->mlx->start_y;
	while ((y != all->map->game_size_h) && (y - all->mlx->start_y < 29))
	{
		x = all->mlx->start_x;
		while ((x != all->map->game_size_w) && (x - all->mlx->start_x < 29))
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

/*
	Calc the visible screen around the player (-15, 14: 29 size).
*/
static void	get_visible_screen(t_all *all)
{
	if ((all->mlx->start_x != 0) || (all->mlx->start_y != 0))
		return ;
	all->mlx->start_x = all->map->p_x - 15;
	if (all->mlx->start_x < 0)
		all->mlx->start_x = 0;
	all->mlx->start_y = all->map->p_y - 15;
	if (all->mlx->start_y < 0)
		all->mlx->start_y = 0;
}

/*
	Update the graphic of a single position.
*/
static int	update_one(t_all *all, int x, int y, int dialga)
{
	static int	size;
	void		*picture;

	if (size == 0)
		size = all->mlx->variable_1_sprite_size;
	picture = pic(all, x, y, dialga);
	all->map->old_pos[x][y].value = all->map->position[x][y].value;
	x = (x - all->mlx->start_x) * size;
	y = (y - all->mlx->start_y) * size;
	y += (size * 3);
	mlx_put_image_to_window(all->mlx->con, all->mlx->window, picture, x, y);
	return (0);
}

/*
	Gives back the picture of what there is in the position.
	For enemy and player, there are two function that further
	process data.
*/
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
	{
		if (all->map->is_solved == YES)
			return (all->mlx->sprite->exit);
		return (all->mlx->sprite->close_exit);
	}
	if (all->map->position[x][y].value == '$')
	{
		return (which_enemy(all, x, y));
	}
	return (NULL);
}

void	clear_screen(t_all *all)
{
	int				x;
	int				y;
	static int		size;

	if (size == 0)
		size = all->mlx->variable_1_sprite_size;
	y = 0;
	while (y != all->map->game_size_h)
	{
		x = 0;
		while (x != all->map->game_size_w)
		{
			all->map->old_pos[x][y].value = -1;
			++x;
		}
		++y;
	}
	all->mlx->start_x = 0;
	all->mlx->start_y = 0;
}
