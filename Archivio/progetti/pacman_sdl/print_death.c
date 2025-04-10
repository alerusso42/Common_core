/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:52:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/10 19:37:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif
//NOTE SDL!!!
/*
	Slowly shows player death.
*/
static void	death_frame(t_all *all, int frame)
{
	void	*pic;
	int		x;
	int		y;
	int		size;

	if (frame == 1)
		pic = all->mlx->sprite->pac_dead_1;
	else if (frame == 2)
		pic = all->mlx->sprite->pac_dead_2;
	else if (frame == 3)
		pic = all->mlx->sprite->pac_dead_3;
	else if (frame == 4)
		pic = all->mlx->sprite->pac_dead_4;
	else if (frame == 5)
		pic = all->mlx->sprite->floor;
	else
		return ;
	size = all->mlx->variable_1_sprite_size;
	x = (all->map->p_x - all->mlx->start_x) * size;
	y = (all->map->p_y - all->mlx->start_y) * size;
	y += (size * 3);
	mlx_put_image_to_window(all->mlx->con, all->mlx->window, pic, x, y);
}

void	kill_pac(void)
{
	t_all			*all;
	static int		fun_loop;	

	all = storage_structs(NULL, GET);
	all->input->freeze = ON;
	all->input->kill_pac = ON;
	if (fun_loop == 0)
		print_str_win(20, 0XFFFF00, "GAME OVER!", NODATA);
	if (fun_loop == 24030 * 1)
		death_frame(all, 1);
	if (fun_loop == 24030 * 2)
		death_frame(all, 2);
	if (fun_loop == 24030 * 3)
		death_frame(all, 3);
	if (fun_loop == 24030 * 4)
		death_frame(all, 4);
	if (fun_loop == 24030 * 5)
		death_frame(all, 5);
	if (fun_loop == 24030 * 6)
		end();
	++fun_loop;
}
