/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:00:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:26:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

/*
	Move only if, for the frame is in, it should move.
*/
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
		return (NO);
	if (map->position[x][y].value == '$')
		return (NO);
	if (map->position[x][y].value == 'P')
		kill_pac();
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
	{
		change_enemy_position(map, en_x - 1, en_y, n);
		map->enemy[n].dir = LEFT;
	}
	else if (map->position[en_x + 1][en_y].distance[n] != 0)
	{
		change_enemy_position(map, en_x + 1, en_y, n);
		map->enemy[n].dir = RIGHT;
	}
	else if (map->position[en_x][en_y - 1].distance[n] != 0)
	{
		change_enemy_position(map, en_x, en_y - 1, n);
		map->enemy[n].dir = UP;
	}
	else if (map->position[en_x][en_y + 1].distance[n] != 0)
	{
		change_enemy_position(map, en_x, en_y + 1, n);
		map->enemy[n].dir = DOWN;
	}
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

	random = all->random->values[dialga % all->map->game_size];
	en_x = all->map->enemy[n].x;
	en_y = all->map->enemy[n].y;
	can_move = YES;
	if (random % 4 == LEFT)
		can_move = change_enemy_position(all->map, en_x - 1, en_y, n) * 3;
	if ((can_move == NO) || (random % 4 == DOWN))
		can_move = change_enemy_position(all->map, en_x, en_y - 1, n) * 2;
	if ((can_move == NO) || (random % 4 == RIGHT))
		can_move = change_enemy_position(all->map, en_x + 1, en_y, n);
	if ((can_move == NO) || (random % 4 == UP))
		can_move = change_enemy_position(all->map, en_x, en_y + 1, n) * 4;
	all->map->enemy[n].dir = can_move / 4;
}

/*
	1)	If player has not moved yet, return.
	
	FOR EVERY ENEMY:

	2)	If enemy is not already triggered, checks if it sees you.
		If it does, it triggers;
	3)	If it is triggered, and the player has moved, the game
		makes a pathfinding with bfs.
		If is fails, the enemy is no longer triggered.
		If it has success, the enemy will have the path to reach you;
	4)	If in the current frame the enemy must move, id does.
		If it sees you, it uses the shortest path;
		If it does not see you, it moves randomly.	
*/
void	move_enemies(t_all *all, int dialga)
{
	int			n;

	if (all->map->player_first_move == OFF)
		return ;
	n = -1;
	while (++n != all->map->variable_3_enemy_num)
	{
		if ((all->map->enemy[n].triggered == 0) && \
		(triggered(all, all->map->enemy[n].x, all->map->enemy[n].y) == YES))
		{
			all->map->enemy[n].triggered = ON;
			p_event_triggered(all->map, n);
		}
		if (all->map->enemy[n].triggered == ON)
		{
			if (all->map->p_mov == YES)
			{
				all->map->enemy[n].triggered = get_best_path(all->map, n);
			}
			if (check_current_frame(all, dialga) == YES)
				move_enemy(all->map, n);
		}
		else if (check_current_frame(all, dialga) == YES)
			move_random(all, dialga, n);
	}
}
