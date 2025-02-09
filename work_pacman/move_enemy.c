/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:00:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/09 12:58:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static int	check_current_frame(t_all *all, int dialga)
{
	(void)all;
	if (all->input->en_speed == 1)
		return (speed_one(dialga));
	if (all->input->en_speed == 2)
		return (speed_two(dialga));
	if (all->input->en_speed == 3)
		return (speed_three(dialga));
	if (all->input->en_speed == 4)
		return (speed_four(dialga));
	if (all->input->en_speed == 5)
		return (speed_five(dialga));
	return (NO);
}

/*
	-	If where tou need to go, there's one of "1E$",
		return that you cannot move there.
	-	If there is the player, kill it, and close the game.
	-	If there is anything else, swap it with the enemy,
		replace the current distance value of the enemy with 0,
		and update the enemy position.
*/
static int	change_enemy_position(t_map *map, int x, int y, int n)
{
	int	new[2];
	int	old[2];

	if (map->position[x][y].value == '1')
		return (NO);
	if (map->position[x][y].value == 'E')
	{
		return (NO);
	}
	if (map->position[x][y].value == '$')
		return (NO);
	if (map->position[x][y].value == 'P')
		end(0);
	else
	{
		swap(x, y, map->enemy[n].x, map->enemy[n].y);
		new[0] = x;
		new[1] = y;
		old[0] = map->enemy[n].x;
		old[1] = map->enemy[n].y;
		replace_bfs(new, old, n);
	}
	map->enemy[n].x = x;
	map->enemy[n].y = y;
	return (YES);
}

/*
	-	Find if there is a location, near the enemy,
		 where it can go (where there's a mark).
	-	Checks left, right, down, up.
	-	When you find one, update it, and stop.
*/
static void	move_enemy(t_map *map, int n)
{
	int	en_x;
	int	en_y;

	en_x = map->enemy[n].x;
	en_y = map->enemy[n].y;
	if (map->position[en_x - 1][en_y].distance[n] != 0)
		change_enemy_position(map, en_x - 1, en_y, n);
	else if (map->position[en_x + 1][en_y].distance[n] != 0)
		change_enemy_position(map, en_x + 1, en_y, n);
	else if (map->position[en_x][en_y - 1].distance[n] != 0)
		change_enemy_position(map, en_x, en_y - 1, n);
	else if (map->position[en_x][en_y + 1].distance[n] != 0)
		change_enemy_position(map, en_x, en_y + 1, n);
}

/*
	-	Randomize a spot to place the enemy.
	-	Checks left, right, down, up.
	-	When you find one, update it, and stop.
	-	If you cannot go somewhere, try to move to the
		following position.
*/
static void	move_random(t_all *all, int dialga, int n)
{
	int	random;
	int	can_move;
	int	en_x;
	int	en_y;

	random = dialga % all->map->game_size;
	random = all->random->values[random];
	en_x = all->map->enemy[n].x;
	en_y = all->map->enemy[n].y;
	can_move = YES;
	if (random % 4 == LEFT)
		can_move = change_enemy_position(all->map, en_x - 1, en_y, n);
	if ((can_move == NO) || (random % 4 == RIGHT))
		can_move = change_enemy_position(all->map, en_x + 1, en_y, n);
	if ((can_move == NO) || (random % 4 == DOWN))
		can_move = change_enemy_position(all->map, en_x, en_y - 1, n);
	if ((can_move == NO) || (random % 4 == UP))
		can_move = change_enemy_position(all->map, en_x, en_y + 1, n);
}

void	move_enemies(t_all *all, int dialga)
{
	static int	trigger;
	int			n;

	n = -1;
	while (++n != all->map->variable_3_enemy_num)
	{
		if ((trigger == 0) && \
		(triggered(all, all->map->enemy[n].x, all->map->enemy[n].y) == YES))
		{
			trigger = 1;
		}
		if (trigger == 1)
		{
			if (all->map->p_mov == YES)
			{
				get_best_path(all->map, n);
				//print_bfs(all->map, n);
			}
			if (check_current_frame(all, dialga) == YES)
				move_enemy(all->map, n);
		}
		else if (check_current_frame(all, dialga) == YES)
			move_random(all, dialga, n);
	}
}