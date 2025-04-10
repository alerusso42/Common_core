/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/10 19:39:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif
//NOTE SDL!!!
/*
	With a static, it storage the all struct.
*/
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

/*
	1)	If the switch input n.3 is OFF, just end.
	2)	When pressed escape, start quit process: print stuff,
		freeze the game;
	3)	When you receive y, and the quit process is active, end.
	4)	If you receive something different from END, stop
		the process and defreeze the game.
*/
void	quit(int keycode, t_all *all)
{
	static char	start_quit_process;

	if (all->input->switch_3_confirm_before_exit == OFF)
		end();
	if (keycode == XK_Escape)
	{
		if (start_quit_process == ON)
			return ;
		write(1, "\nARE YOU SURE TO EXIT?[y][any else]", 35);
		print_str_win(23, 0XFFFF00, "ARE YOU SURE TO EXIT?[y]", NODATA);
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
	print_str_win(23, 0XFF00FF, "", NODATA);
	all->input->freeze = OFF;
	start_quit_process = OFF;
}

/*
	end the game.
*/
int	end(void)
{
	t_all	*all;

	all = (t_all *)storage_structs(NULL, GET);
	full_reset(4, &all->input, &all->map, &all->random, &all->mlx);
	free(all);
	all = NULL;
	exit(0);
}
