/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:00:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 15:52:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

void	p_event_triggered(t_map *map, int enemy_num)
{
	if (map->variable_2_printdata == NO)
		return ;
	if (map->enemy[enemy_num].color == RED)
		print_str_win(20, 0XFF0000, "Enemy RED has seen you!", NODATA);
	else if (map->enemy[enemy_num].color == PURPLE)
		print_str_win(20, 0X800080, "Enemy PURPLE has seen you!", NODATA);
	else if (map->enemy[enemy_num].color == CIAN)
		print_str_win(20, 0X008090, "Enemy CIAN has seen ya!", NODATA);
	else if (map->enemy[enemy_num].color == ORANGE)
		print_str_win(20, 0XDD6000, "Enemy ORANGE has seen ya!", NODATA);
}

void	p_event_lost(t_map *map, int enemy_num)
{
	if (map->variable_2_printdata == NO)
		return ;
	if (map->enemy[enemy_num].color == RED)
		print_str_win(20, 0XFF0000, "Enemy RED has lost you!", NODATA);
	else if (map->enemy[enemy_num].color == PURPLE)
		print_str_win(20, 0X800080, "Enemy PURPLE has lost you!", NODATA);
	else if (map->enemy[enemy_num].color == CIAN)
		print_str_win(20, 0X008090, "Enemy CIAN has lost you!", NODATA);
	else if (map->enemy[enemy_num].color == ORANGE)
		print_str_win(20, 0XDD6000, "Enemy ORANGE has lost you!", NODATA);
}

void	p_event_collectables_left(t_all *all)
{
	static char	warning_few_left;

	if (all->map->variable_2_printdata == NO)
		return ;
	print_str_win(10, 0XFFFFFF, "Col. to take:", all->map->collectable_num);
	if ((warning_few_left == 0) && (all->map->collectable_num == 1))
	{
		warning_few_left = 1;
		print_str_win(30, 0XFFFF00, "ONE COL. LEFT!!!", NODATA);
	}
	if ((warning_few_left == 1) && (all->map->collectable_num == 0))
	{
		warning_few_left = 2;
		print_str_win(30, 0XFFFF00, "THE EXIT IS OPEN...", NODATA);
	}
}

	/*left = 0;
	find_invisibles(all, &left, 1, 0);
	print_str_win(30, 0XFFFFFF, "Col. left:", left);
	left = 0;
	find_invisibles(all, &left, 2, 0);
	print_str_win(31, 0XFFFFFF, "Col. right:", left);
	left = 0;
	find_invisibles(all, &left, 3, 0);
	print_str_win(32, 0XFFFFFF, "Col. down:", left);
	left = 0;
	find_invisibles(all, &left, 4, 0);
	print_str_win(33, 0XFFFFFF, "Col. up:", left);*/
/*
static void	find_invisibles(t_all *all, int *left, int mode, int x)
{
	int	y;

	if (mode == 1)
	{
		x = all->map->p_x - 14;
		while ((x++ != all->map->p_x) && (x >= 0))
			*left += all->input->col.x[x];	
	}
	if (mode == 2)
	{
		x = all->map->p_x + 14;
		while ((x-- != all->map->p_x) && (x < all->input->game_size_h))
			*left += all->input->col.x[x];
	}
	if (mode == 3)
	{
		y = all->map->p_y - 14;
		while ((y++ != all->map->p_y) && (y >= 0))
			*left += all->input->row.y[y];
	}
	if ((mode == 1) || (mode == 2) || (mode == 3))
		return ;
	y = all->map->p_y + 14;
	while ((y-- != all->map->p_y) && (y < all->input->game_size_w))
		*left += all->input->row.y[y];	
}
*/