/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 17:24:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

/*
	Animations changes the image of the exit, when the game is
	solved.

	It prints a picture for the player, based on the current
	frame (dialga).
*/
void	animations(t_all *all, int dialga)
{
	int		x;
	int		y;
	void	*p;
	int		size;

	size = all->mlx->variable_1_sprite_size;
	if (all->map->is_solved == YES)
	{
		x = (all->map->e_x - all->mlx->start_x) * size;
		y = (all->map->e_y - all->mlx->start_y) * size + (size * 3);
		mlx_put_image_to_window(all->mlx->con, all->mlx->window, \
		all->mlx->sprite->exit, x, y);
	}
	x = (all->map->p_x - all->mlx->start_x) * size;
	y = ((all->map->p_y - all->mlx->start_y) * size) + (size * 3);
	p = pic(all, all->map->p_x, all->map->p_y, dialga);
	mlx_put_image_to_window(all->mlx->con, all->mlx->window, p, x, y);
}

// Dialga is a static variable that represents time.
/*
	STEPS OF GAME LOOP

	1)	If the game is frozen, don't do anything;
	2)	If pacman has been killed, calls kill_pac;
	3)	If the switch to always update the screen is on, calls
		clear_screen. Then, update it;
	4)	If there are, move the enemies.
	5)	Animate pacman;
	6)	Every 20030 frame (complete pacman animation), print
		how many collectables are left;
	7)	Increase dialga, and resets the bool player_movement to
		zero.
*/
int	game_loop(void *param)
{
	static t_all	*all;
	static int		dialga;		

	(void)param;
	if (all == NULL)
		all = storage_structs(NULL, GET);
	if (all->input->freeze == ON)
	{
		if (all->input->kill_pac == ON)
			kill_pac();
		return (0);
	}
	if ((all->input->switch_2_rechargemap == ON) && (all->map->p_mov == YES))
		clear_screen(all);
	update_screen(all, dialga);
	if (all->map->variable_3_enemy_num)
		move_enemies(all, dialga);
	animations(all, dialga);
	if (dialga % 20030 == 0)
		p_event_collectables_left(all);
	++dialga;
	all->map->p_mov = NO;
	return (0);
}

/*
	1)	Parsing of argv (change_mod);
	2)	Get the data for running the program;
	3)	Give to minilibx the data of the commands;
	4)	Finds where the enemies are;
	5)	Run the loop;
	6)	reset the structs used.
*/
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
	get_enemies_position(all->map, '$');
	mlx_loop(all->mlx->con);
	full_reset(4, &all->input, &all->map, &all->random, &all->mlx);
	free(all);
	all = NULL;
	return (0);
}

/*
	-	This function gets data from the parsing process.
	-	The data taken will be used to influence the behaviour
		of the program.
*/
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
