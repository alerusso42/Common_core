/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/11 16:52:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

void	*storage_structs(t_all *update, int mode)
{
	static t_all	*all;

	if (mode == UPDATE)
	{
		all = update;
		return (NULL);
	}
	else
		return (all);
}

void	quit(int keycode, t_all *all)
{
	static char	start_quit_process;

	if (all->input->switch_3_confirm_before_exit == OFF)
		end();
	if (keycode == XK_Escape)
	{
		if (start_quit_process == ON)
			return ;
		write(1, "\nARE YOU SURE TO EXIT?[y][any else]", 37);
		print_str_win(22, 0XFF00FF, "ARE YOU SURE TO EXIT?[y]", NODATA);
		start_quit_process = ON;
		all->input->freeze = ON;
		all->input->quit_process = ON;
		return ;
	}
	else if ((keycode == XK_y) || (keycode == XK_Y))
	{
		if (start_quit_process == OFF)
			return ;
		else
			end();
	}
	print_str_win(20, 0XFF00FF, "", NODATA);
	all->input->freeze = OFF;
	start_quit_process = OFF;
}

int	end()
{
	t_all	*all;

	all = (t_all *)storage_structs(NULL, GET);
	full_reset(4, &all->input, &all->map, &all->random, &all->mlx);
	free(all);
	all = NULL;
	exit(0);
}
