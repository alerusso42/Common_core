/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/21 17:56:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

t_bool	alloc_data3(t_input *input, t_map *map, t_random *random);
t_bool	alloc_data2(t_input **input, t_map **map, t_random *random);
t_bool	alloc_data(int game_size[2], int seed, int create_or_read, char *fn);
t_bool	create_map(t_input *input, t_map *map, t_random *random);
t_bool	read_map(t_input *input, t_map *map);
void	temp_set_input(t_input **input);

t_bool	alloc_data(int game_size[2], int seed, int create_or_read, char *fn)
{
	t_input		*input;
	t_map	*map;
	t_random	*random;

	input = NULL;
	map = NULL;
	random = NULL;
	if (alloc_user_input(&input, game_size) != 0)
		return (full_reset(1, &input), ERROR_FULL_MEMORY);
	if (alloc_sol(&input, &map) != 0)
		return (full_reset(2, &input, &map), ERROR_FULL_MEMORY);
	if (alloc_randomlist(&random, input->game_size) != 0)
		return (full_reset(3, &input, &map, &random), ERROR_FULL_MEMORY);
	if (fn)
		input->filename = ft_strdup(fn);
	if (!fn)
		input->filename = ft_strdup("map.ber");
	if (!input->filename)
		return (full_reset(3, &input, &map, &random));
	input->create_map = create_or_read;
	random->seed = seed + switches(input, map, random);
	variables(input, map, random);
	return (alloc_data2(&input, &map, random));
}

t_bool	alloc_data2(t_input **input, t_map **map, t_random *random)
{
	int	seed;

	seed = random->seed;
	fill_random(&random, *input);
	fill_map(map, (*map)->game_size_h,\
	 (*map)->game_size_w);
	temp_set_input(input);
	if (((*input)->create_map == CREATE) && \
	(create_map(*input, *map, random) == 1))
		return (full_reset(3, input, map, &random), 1);
	if (((*input)->create_map == READ) && \
	(read_map(*input, *map) == 1))
		return (full_reset(3, input, map, &random), 1);
	if ((*map)->switch_4_printonterminal == ON)
		print_map(*input, *map, 0, 0);
	if (check_map(*input, *map, (*map)->game_size_w, \
	(*map)->game_size_h) == 1)
		return (1);
	if (read_map(*input, *map) == 1)
		return (full_reset(3, input, map, &random), 1);
	if (alloc_data3(*input, *map, random) == 1)
		return (1);
	return (0);
}

t_bool	alloc_data3(t_input *input, t_map *map, t_random *random)
{
	t_all	*all;
	t_mlx	*mlx;

	all = NULL;
	mlx = NULL;
	all = (t_all *)ft_calloc(1, sizeof(t_all));
	if (!all)
		return (full_reset(3, &input, &map, &random), 0);
	free(all);
	if (alloc_mlx(&mlx) != 0)
		return (full_reset(4, &input, &map, &random, &mlx), 0);
	if (get_mlx(mlx, map->variable_6_window_width, \
	map->variable_7_window_heigth, map->display_name) == 1)
		return (full_reset(4, &input, &map, &random, &mlx), 0);
	return (full_reset(4, &input, &map, &random, &mlx), 0);
}

t_bool	create_map(t_input *input, t_map *map, t_random *random)
{
	edit_map(map, input->game_size_w, input->game_size_h, random);
	save_map(map, input->game_size_w, input->game_size_h);
	return (0);
}
