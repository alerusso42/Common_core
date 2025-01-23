/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/22 17:16:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

// 
int	main(int argc, char *argv[])
{
	t_all	*all;
	
	if (argc == 1)
		return (error(ERROR_BAD_ARGC), 1);
	if (change_mod(argv, argc) == 1)
		return (1);
	all = get_data(GET, 0, 0, argv[1]);
	if (!all)
		return (1);
	get_key_settings(all);
	mlx_loop_hook(all->mlx->con, update_screen, NULL);
	mlx_loop(all->mlx->con);
	full_reset(4, &all->input, &all->map, &all->random, &all->mlx);
	free(all);
	all = NULL;
	return (0);
}

void	*get_data(int change_mode, int width, int heigth, char fn[])
{
	static int	mode;
	static int	game_size[2];

	if (change_mode != GET)
	{
		game_size[0] = width;
		game_size[1] = heigth;
		mode = change_mode;
		return (NULL);
	}
	if (mode == READ)
		return (alloc_data(game_size, 0, READ, fn));
	else if (mode == CREATE)
		return (alloc_data(game_size, 0, CREATE, NULL));
	else
		return (NULL);
}

