/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:21:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 15:50:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

/*
	Does some random operations to find a free position ('0').
	
	To resets to zero random index, we pass NULL pointers.
	This is because, to fill multiple coordinates (for enemies,
	for collectables, ecc.) we call multiple times this ft.
	And we don't want to use the same coordinates!
	So, rand index is reset only at the end. 
*/
int	sort_coordinates(t_map *map, t_random *random, int *x, int *y)
{
	static int	rand_index;
	int			rand_value;
	int			game_size;

	if ((!map) || (!random))
	{
		rand_index = 0;
		return (0);
	}
	game_size = (map->game_size_w) * (map->game_size_h);
	while ("Loop until you have found a free square")
	{
		rand_value = random->values[rand_index];
		*y = rand_value / (map->game_size_w);
		*x = rand_value % (map->game_size_w);
		if ((rand_value != -1) && (rand_value != game_size) \
		&& (map->position[*x][*y].value == '0'))
		{
			++rand_index;
			break ;
		}
		if (rand_index++ == game_size)
			return (1);
	}
	return (0);
}

void	fourt_step_exit(t_map *map, t_random *random)
{
	int	x;
	int	y;

	if (sort_coordinates(map, random, &x, &y) == 1)
		return ;
	map->position[x][y].value = 'E';
	map->e_x = x;
	map->e_y = y;
	sort_coordinates(NULL, NULL, NULL, NULL);
}

void	third_step_player(t_map *map, t_random *random)
{
	int	x;
	int	y;

	if (sort_coordinates(map, random, &x, &y) == 1)
		return ;
	map->position[x][y].value = 'P';
	map->p_x = 0;
	map->p_y = 0;
	sort_coordinates(NULL, NULL, NULL, NULL);
}

void	secon_step_fillwall(t_map *map, int size_x, int size_y)
{
	int	y;
	int	x;

	x = 0;
	y = size_y;
	while (x != size_x - 1)
	{
		map->position[x][y - 1].value = '1';
		map->position[x][0].value = '1';
		++x;
	}
	while (y != 0)
	{
		--y;
		map->position[0][y].value = '1';
		map->position[size_x - 1][y].value = '1';
	}
}

/*
	After we have created the map, we edit it.
	Cool, right?
*/
int	edit_map(t_map *map, int size_x, int size_y, t_random *random)
{
	if ((size_x < 2) || (size_y < 2))
		return (l_printf("x e y devono essere >= 3\n"), 1);
	if ((map->free_spaces < 0))
		return (l_printf("\nNo space for P, E, C.\n"));
	secon_step_fillwall(map, size_x, size_y);
	third_step_player(map, random);
	if (random->variable_3_enemy_num > map->free_spaces)
		return (l_printf("Gli spazi liberi sono %d, i nemici inseriti %d\n", \
		map->free_spaces, random->variable_3_enemy_num));
	fourt_step_exit(map, random);
	if (random->switch_3_choose_map_entities_num == ON)
		if (map->void_spaces < 0)
			return (l_printf("Non c'e abbastanza spazio per tutto.\n"));
	fifth_step_enemy(map, random);
	sixth_step_colet(map, random);
	last_step_walls(map, random);
	return (0);
}
