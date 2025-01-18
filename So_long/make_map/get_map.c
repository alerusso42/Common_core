/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/17 19:23:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H
# define MIN_INT_VALUE -2147483648
# define MAX_INT_VALUE 2147483647
# include "types.h"
# include "switches.h"
# include "variables.h"
# include "general_ft.h"
# include "atoi.h"
# include "error_message.h"
# include "alloc_t_input.h"
# include "alloc_t_solution.h"
# include "alloc_t_random.h"
# include "random_numbers.h"
# include "print_stuff.h"
# include "edit_map.h"
# include "check_map.h"
# include "save_map.h"
# include "get_map2.h"
# include <unistd.h>
# include <fcntl.h>

t_bool	alloc_data2(t_input **input, t_solution **solution, t_random *random);
int		ft_start(t_input **input, t_solution **solution, t_random *random);
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
		return (error(ERROR_FULL_MEMORY));
	if (alloc_sol(&input, &solution) != 0)
	{
		full_reset(2, &input, &solution);
		return (3);
	}
	if (alloc_randomlist(&random, input->game_size) != 0)
	{
		full_reset(2, input, solution);
		return (3);
	}
	if (fn)
		input->filename = fn;
	input->create_map = create_or_read;
	random->seed = seed + switches(&input, &solution, &random);
	variables(&input, &solution, &random);
	return (alloc_data2(&input, &solution, random));
}

t_bool	alloc_data2(t_input **input, t_solution **solution, t_random *random)
{
	int	seed;

	seed = random->seed;
	fill_random(&random, *input);
	while (seed-- == 0)
	{
		if (seed % 2 == 0)
			twist_random(&random, (*input)->game_size);
		else if (seed % 3 == 0)
			twist_random2(&random, (*input)->game_size);
		else if (seed % 7 == 0)
			twist_random3(&random, (*input)->game_size);
	}
	fill_solution(solution, (*solution)->game_size_h,\
	 (*solution)->game_size_w);
	temp_set_input(input);
	if (((*input)->create_map == CREATE) && \
	(create_map(*input, *solution, random) == 1))
		return (full_reset(3, input, solution, &random), 1);
	if (((*input)->create_map == READ) && \
	(read_map(*input, *solution) == 1))
		return (full_reset(3, input, solution, &random), 1);
	print_solution(*input, *solution, 0, 0);
	if (check_map(*input, *solution, (*solution)->game_size_w, \
	(*solution)->game_size_h) == 1)
		return (1);
	if (read_map(*input, *solution) == 1)
		return (full_reset(3, input, solution, &random), 1);
	full_reset(3, input, solution, &random);
	return (0);
}

t_bool	create_map(t_input *input, t_solution *solution, t_random *random)
{
	edit_map(solution, input->game_size_w, input->game_size_h, random);
	save_map(solution, input->game_size_w, input->game_size_h);
	return (0);
}

#endif