/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:45:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:29:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

static int	change_player_position(t_map *map, int x, int y);

int	move_player(t_map *map, int direction)
{
	map->p_mov = YES;
	map->p_dir = direction;
	if (direction == RIGHT)
		return (change_player_position(map, map->p_x + 1, map->p_y));
	if (direction == DOWN)
		return (change_player_position(map, map->p_x, map->p_y + 1));
	if (direction == LEFT)
		return (change_player_position(map, map->p_x - 1, map->p_y));
	if (direction == UP)
		return (change_player_position(map, map->p_x, map->p_y - 1));
	return (NO);
}

static void	decrease_coll(int x, int y)
{
	t_all	*all;

	all = storage_structs(NULL, GET);
	all->input->col.x[x] -= 1;
	all->input->row.y[y] -= 1;
}

/*
	Easy to read.
*/
static int	change_player_position(t_map *map, int x, int y)
{
	if (map->position[x][y].value == '1')
		return (NO);
	if (map->position[x][y].value == 'E')
	{
		if ((map->is_solved == YES) && (map->variable_2_printdata == ON))
			print_str_win(20, 0XFFFF00, "YOU WIN!", NODATA);
		if (map->is_solved == YES)
			end();
		return (NO);
	}
	if (map->position[x][y].value == '$')
		kill_pac();
	if (map->position[x][y].value == 'C')
	{
		map->collectable_num--;
		decrease_coll(x, y);
		if (map->collectable_num == 0)
			map->is_solved = 1;
		replace(x, y, map->p_x, map->p_y);
	}
	else
		swap(x, y, map->p_x, map->p_y);
	map->p_x = x;
	map->p_y = y;
	return (YES);
}
