/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/21 14:11:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

t_bool	alloc_data3(t_input *input, t_solution *solution, t_random *random);
t_bool	alloc_data2(t_input **input, t_solution **solution, t_random *random);
t_bool	alloc_data(int game_size[2], int seed, int create_or_read, char *fn);
t_bool	create_map(t_input *input, t_solution *solution, t_random *random);
t_bool	read_map(t_input *input, t_solution *solution);
void	temp_set_input(t_input **input);

t_bool	alloc_data(int game_size[2], int seed, int create_or_read, char *fn)
{
	t_input		*input;
	t_solution	*solution;
	t_random	*random;

	input = NULL;
	solution = NULL;
	random = NULL;
	if (alloc_user_input(&input, game_size) != 0)
		return (full_reset(1, &input), ERROR_FULL_MEMORY);
	if (alloc_sol(&input, &solution) != 0)
		return (full_reset(2, &input, &solution), ERROR_FULL_MEMORY);
	if (alloc_randomlist(&random, input->game_size) != 0)
		return (full_reset(3, &input, &solution, &random), ERROR_FULL_MEMORY);
	if (fn)
		input->filename = ft_strdup(fn);
	if (!fn)
		input->filename = ft_strdup("map.ber");
	if (!input->filename)
		return (full_reset(3, &input, &solution, &random));
	input->create_map = create_or_read;
	random->seed = seed + switches(input, solution, random);
	variables(input, solution, random);
	return (alloc_data2(&input, &solution, random));
}

t_bool	alloc_data2(t_input **input, t_solution **solution, t_random *random)
{
	int	seed;

	seed = random->seed;
	fill_random(&random, *input);
	fill_solution(solution, (*solution)->game_size_h,\
	 (*solution)->game_size_w);
	temp_set_input(input);
	if (((*input)->create_map == CREATE) && \
	(create_map(*input, *solution, random) == 1))
		return (full_reset(3, input, solution, &random), 1);
	if (((*input)->create_map == READ) && \
	(read_map(*input, *solution) == 1))
		return (full_reset(3, input, solution, &random), 1);
	if ((*solution)->switch_4_printonterminal == ON)
		print_solution(*input, *solution, 0, 0);
	if (check_map(*input, *solution, (*solution)->game_size_w, \
	(*solution)->game_size_h) == 1)
		return (1);
	if (read_map(*input, *solution) == 1)
		return (full_reset(3, input, solution, &random), 1);
	if (alloc_data3(*input, *solution, random) == 1)
		return (1);
	return (0);
}

t_bool	alloc_data3(t_input *input, t_solution *solution, t_random *random)
{
	
	return (full_reset(3, &input, &solution, &random), 0);
}

t_bool	create_map(t_input *input, t_solution *solution, t_random *random)
{
	edit_map(solution, input->game_size_w, input->game_size_h, random);
	save_map(solution, input->game_size_w, input->game_size_h);
	return (0);
}
