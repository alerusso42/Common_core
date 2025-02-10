/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:51:51 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/09 10:50:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

//
void	del_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

//////////////////////////////////////////////

//
t_typelist	*store_list(t_typelist *list, int mode)
{
	static t_typelist	*store_list;
	
	if (mode == 0)
	{
		store_list = list;
		return (NULL);
	}
	return (store_list);
}

/*
	Clear the path of the enemy.
*/
void	clean_bfs(t_map *map, int enemy_num)
{
	int	x;
	int	y;

	y = 0;
	while (y != map->game_size_h)
	{
		x = 0;
		while (x != map->game_size_w)
		{
			map->position[x][y].distance[enemy_num] = 0;
			++x;
		}
		++y;
	}
}