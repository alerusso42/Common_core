/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:22:38 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:13:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

/*
void	print_bfs(t_map *map, int enemy_num)
{
	int		x;
	int		y;
	char	c;

	x = -1;
	y = 0;
	printf("\nMap values: \n y = %d:\n", y);
	while ((++x) || (1))
	{
		if (x == map->game_size_w)
		{
			printf("\ny= %d:\n", y);
			if (y == map->game_size_h - 1)
				break ;
			y++;
			x = 0;
		}
		c = map->position[x][y].value;
		if (c == '0')
			printf("\033[1;37m%c\033[0m | ", c);
		else if (c == '1')
			printf("\033[1;35m%c\033[0m | ", c);
		else if (c == '$')
			printf("\033[1;31m%c\033[0m | ", c);
		else
			printf("\033[1;32m%c\033[0m | ", c);
		//\033[1;31mThis is red text\033[0m
	}
	x = 0;
	y = 0;
	printf("\n\n\nMap distances: \n\n");
	while ((++x) || (1))
	{
		if (x == map->game_size_w)
		{
			printf("\n\n");
			if (y == map->game_size_h - 1)
				break ;
			y++;
			x = 0;
		}
		if (map->position[x][y].distance[enemy_num] == -1)
			printf("\033[1;33m%2d\033[0m | ", \
			map->position[x][y].distance[enemy_num]);
		else if (map->position[x][y].distance[enemy_num] == -2)
			printf("\033[1;31m%2d\033[0m | ", \
			map->position[x][y].distance[enemy_num]);
		else if (map->position[x][y].distance[enemy_num] == -3)
			printf("\033[1;32m%2d\033[0m | ", \
			map->position[x][y].distance[enemy_num]);
		else
			printf("%2d | ", map->position[x][y].distance[enemy_num]);
	}
}
	*/