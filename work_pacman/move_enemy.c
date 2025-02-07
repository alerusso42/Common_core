/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:00:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/07 12:40:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static int	check_current_frame(int dialga)
{
	if (dialga % 24030 == 0)
		return (YES);
	if (dialga % 24030 == 4005)
		return (YES);
	if (dialga % 24030 == 8010)
		return (YES);
	if (dialga % 24030 == 12015)
		return (YES);
	if (dialga % 24030 == 16020)
		return (YES);
	if (dialga % 24030 == 20025)
		return (YES);
	return (NO);
}

static void	change_enemy_position(t_map *map, int x, int y)
{
	if (map->position[x][y].value == '1')
		return ;
	if (map->position[x][y].value == 'E')
	{
		return ;
	}
	if (map->position[x][y].value == '$')
		return ;
	else
		swap(x, y, map->p_x, map->p_y);
	map->p_x = x;
	map->p_y = y;
	return ;
}

static void	move_enemy(t_map *map, int en_x, int en_y)
{
	if (map->position[en_x - 1][en_y].distance != 0)
		change_enemy_position(map, en_x - 1, en_y);
	else if (map->position[en_x + 1][en_y].distance != 0)
		change_enemy_position(map, en_x + 1, en_y);
	else if (map->position[en_x][en_y - 1].distance != 0)
		change_enemy_position(map, en_x, en_y - 1);
	else if (map->position[en_x][en_y + 1].distance != 0)
		change_enemy_position(map, en_x, en_y + 1);
}

static void	move_random(t_map *map, int en_x, int en_y)
{
	
}

void	move_enemies(t_all *all, int dialga)
{
	static int	trigger;

	if ((trigger == 0) && (triggered() == YES))
	{
		trigger = 1;
	}
	if (trigger == 1)
	{
		if (check_current_frame(dialga) == YES)
		{
			get_best_path(all->map);
			move_enemy(all->map, all->map->e_x, all->map->e_y);
		}
	}
	else if (check_current_frame(dialga) == YES)
		move_random(all->map, all->map->e_x, all->map->e_y);
}