/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:30:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:20:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

int	commands(int keycode);

/*
	ON_DESTROY is [X]
	1L << 1 is ON_RELEASE
*/
void	get_key_settings(t_all *all)
{
	void	*p;

	p = (void *)&all;
	storage_structs(all, UPDATE);
	mlx_hook(all->mlx->window, ON_DESTROY, 1L << 1, end, p);
	mlx_hook(all->mlx->window, ON_KEYDOWN, 1L << 0, commands, p);
}

/*
	Bonus prints on window, not bonus on terminal.
*/
static int	moves_number_printer(t_all *all, int counter)
{
	char		*str;
	static int	first_print;
	static void	*floor;

	str = ft_itoa(counter);
	if (!str)
		return (1);
	if (all->map->player_first_move == OFF)
		all->map->player_first_move = ON;
	if (all->input->switch_1_bonus == ON)
	{
		if (first_print == 0)
		{
			floor = all->mlx->sprite->floor;
			mlx_string_put(all->mlx->con, all->mlx->window, 0, 10, WHITE, \
			"Numero mossa: ");
		}
		mlx_put_image_to_window(all->mlx->con, all->mlx->window, floor, 76, 0);
		mlx_string_put(all->mlx->con, all->mlx->window, 80, 10, WHITE, str);
	}
	else
		l_printf("Mossa numero %s\n", str);
	return (free(str), 0);
}

/*
	ESC:	start quit process;
	u:		update screen;
	->/d:	right;
	<-/a:	left;
	ECC.
*/
int	commands(int keycode)
{
	static t_all	*all;
	static int		counter;
	int				valid_move;

	if (all == NULL)
		all = storage_structs(NULL, GET);
	if (all->input->kill_pac == ON)
		return (0);
	if ((keycode == XK_Escape) || (all->input->quit_process == ON))
		quit(keycode, all);
	if ((keycode == XK_u) || (keycode == XK_U))
		return (clear_screen(all), 0);
	valid_move = NO;
	if ((keycode == XK_Right) || (keycode == XK_d) || (keycode == XK_D))
		valid_move = move_player(all->map, RIGHT);
	else if ((keycode == XK_Down) || (keycode == XK_s) || (keycode == XK_S))
		valid_move = move_player(all->map, DOWN);
	else if ((keycode == XK_Left) || (keycode == XK_a) || (keycode == XK_A))
		valid_move = move_player(all->map, LEFT);
	else if ((keycode == XK_Up) || (keycode == XK_w) || (keycode == XK_W))
		valid_move = move_player(all->map, UP);
	if (valid_move == NO)
		return (0);
	return (moves_number_printer(all, ++counter));
}
