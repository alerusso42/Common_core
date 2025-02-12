/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 17:08:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

t_all	*alloc_data3(t_input *input, t_map *map, t_random *random);
t_all	*alloc_data2(t_input **input, t_map **map, t_random *random);
t_all	*alloc_data(int game_size[2], int seed, int create_or_read, char *fn);
t_bool	create_map(t_input *input, t_map *map, t_random *random);
void	temp_set_input(t_input **input);

/*
	In the first phase of allocation:

	1)	We alloc data for the struct input, map, random;
	2)	We save the name of the map, or we give it a standard name;
	3)	We assign a value to the switches and variables used.
*/
t_all	*alloc_data(int game_size[2], int seed, int create_or_read, char *fn)
{
	t_input		*input;
	t_map		*map;
	t_random	*random;

	input = NULL;
	map = NULL;
	random = NULL;
	if (alloc_user_input(&input, game_size) != 0)
		return (full_reset(1, &input), error(ERROR_FULL_MEMORY), NULL);
	if (alloc_map(&input, &map) != 0)
		return (full_reset(2, &input, &map), error(ERROR_FULL_MEMORY));
	if (alloc_randomlist(&random, input->game_size) != 0)
		return (full_reset(3, &input, &map, &random), error(ERROR_FULL_MEMORY));
	if (fn)
		input->filename = fn;
	if (!fn)
		input->filename = ft_strdup("maps/map.ber");
	if (!input->filename)
		return (full_reset(3, &input, &map, &random), error(ERROR_FULL_MEMORY));
	input->create_map = create_or_read;
	random->seed = seed + switches(input, map, random);
	variables(input, map, random);
	return (alloc_data2(&input, &map, random));
}

/*
	In this phase:

	1)	Now we assign the data. We create or read the map, 
		basing on the mode;
	2)	We check if the map is valid. Lastly, we read it, to
		restore it after floodfill.
*/
t_all	*alloc_data2(t_input **input, t_map **map, t_random *random)
{
	fill_random(&random, *input);
	fill_map(map, (*map)->game_size_h, \
	(*map)->game_size_w);
	copy_map(map, (*map)->game_size_h, (*map)->game_size_w);
	temp_set_input(input);
	if (((*input)->create_map == CREATE) && \
	(create_map(*input, *map, random) == 1))
		return (full_reset(3, input, map, &random), NULL);
	if (((*input)->create_map == READ) && \
	(read_map(*input, *map) == 1))
		return (full_reset(3, input, map, &random), NULL);
	if ((*map)->switch_2_printonterminal == ON)
		print_map(*map);
	if (check_map(*input, *map, (*map)->game_size_w, \
	(*map)->game_size_h) == 1)
		return (full_reset(3, input, map, &random), NULL);
	if (read_map(*input, *map) == 1)
		return (full_reset(3, input, map, &random), NULL);
	random->variable_3_enemy_num = (*map)->variable_3_enemy_num;
	return (alloc_data3(*input, *map, random));
}

/*
	Lastly, we alloc and assign data to the mlx connection.
*/
t_all	*alloc_data3(t_input *input, t_map *map, t_random *random)
{
	t_all	*all;
	t_mlx	*mlx;

	all = NULL;
	mlx = NULL;
	all = (t_all *)ft_calloc(1, sizeof(t_all));
	if (!all)
		return (full_reset(3, &input, &map, &random), NULL);
	if (alloc_mlx(&mlx) != 0)
		return (full_reset(4, &input, &map, &random, &mlx), NULL);
	if (get_mlx(mlx, map->variable_6_window_width, \
	map->variable_7_window_heigth, map->display_name) == 1)
		return (full_reset(4, &input, &map, &random, &mlx), NULL);
	if (alloc_enemies(map) != 0)
		return (full_reset(4, &input, &map, &random, &mlx), NULL);
	all->input = input;
	all->map = map;
	all->random = random;
	all->mlx = mlx;
	return (all);
}

t_bool	create_map(t_input *input, t_map *map, t_random *random)
{
	edit_map(map, input->game_size_w, input->game_size_h, random);
	save_map(map, input->game_size_w, input->game_size_h);
	return (0);
}
