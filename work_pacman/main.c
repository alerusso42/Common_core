/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/07 17:28:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

void	animations(t_all *all, int dialga)
{
	int		x;
	int		y;
	void	*p;
	int		size;

	size = all->mlx->variable_1_sprite_size;
	if (all->map->is_solved == YES)
	{
		x = (all->map->e_x * size);
		y = (all->map->e_y * size) + size * 3;
		mlx_put_image_to_window(all->mlx->con, all->mlx->window, \
		all->mlx->sprite->exit, x, y);
	}
	x = (all->map->p_x * size);
	y = (all->map->p_y * size) + size * 3;
	p = pic(all, all->map->p_x, all->map->p_y, dialga);
	mlx_put_image_to_window(all->mlx->con, all->mlx->window, p, x, y);
}

// Dialga is a static variable that represents time.
int	game_loop(void *param)
{
	static t_all	*all;
	static int		dialga;		

	(void)param;
	if (all == NULL)
		all = storage_structs(NULL, GET);
	update_screen(all, dialga);
	if (all->input->switch_1_bonus == ON)
		move_enemies(all, dialga);
	animations(all, dialga);
	++dialga;
	all->map->p_mov = 0;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_all	*all;

	if (argc == 1)
		return (error(ERROR_BAD_ARGC), 1);
	if (change_mod(argv, argc) == 1)
		return (1);
	all = get_data(GET, 0, 0, NULL);
	if (!all)
		return (1);
	get_key_settings(all);
	mlx_loop_hook(all->mlx->con, game_loop, NULL);
	//TEST
	find_stuff(all->map, '$', &all->map->e_x, &all->map->e_y);
	//END_TEST
	mlx_loop(all->mlx->con);
	full_reset(4, &all->input, &all->map, &all->random, &all->mlx);
	free(all);
	all = NULL;
	return (0);
}

void	*get_data(int change_mode, int width, int heigth, char *fn)
{
	static int	mode;
	static int	game_size[2];
	static char	*filename;

	if (change_mode != GET)
	{
		game_size[0] = width;
		game_size[1] = heigth;
		filename = fn;
		mode = change_mode;
		return (NULL);
	}
	if (game_size[0] * game_size[1] == 0)
		return (NULL);
	if (mode == READ)
		return (alloc_data(game_size, 0, READ, filename));
	else if (mode == CREATE)
		return (alloc_data(game_size, 0, CREATE, NULL));
	else
		return (NULL);
}
