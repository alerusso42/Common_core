/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automatic_input.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/14 23:20:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATIC_INPUT_H
# define AUTOMATIC_INPUT_H
# define MIN_INT_VALUE -2147483648
# define MAX_INT_VALUE 2147483647
# include "types.h"
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
# include <unistd.h>
# include <fcntl.h>

t_bool	automatic_input(int argc, char *argv[], int *game_size, int seed);
t_bool	parsing(int argc, char *argv[], int **game_size, int *seed);
t_bool	auto_input2(t_input **input, t_solution **solution, t_random *random);
t_bool	cheat(t_input **input, t_solution **solution, t_random **random);
int		ft_start(t_input **input, t_solution **solution, t_random *random);

t_bool	automatic_input(int argc, char *argv[], int game_size[2], int seed)
{
	t_input		*input;
	t_solution	*solution;
	t_random	*random;

	input = NULL;
	solution = NULL;
	random = NULL;
	if (parsing(argc, argv, &game_size, &seed) != 0)
		return (ERROR_BAD_ARGC);
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
	random->seed = seed + switches(&input, &solution, &random);
	variables(&input, &solution, &random);
	solution->game_size = (t_onebyte)*game_size;
	return (auto_input2(&input, &solution, random));
}

t_bool	parsing(int argc, char *argv[], int *game_size[2], int *seed)
{
	if ((argc == 3) || (argc > 5))
		return (error(ERROR_BAD_ARGC));
	(*game_size)[0] = ft_atoi(argv[2]);
	(*game_size)[1] = ft_atoi(argv[3]);
	if (((*game_size)[0] < 1) || ((*game_size)[1] < 1) || \
	((*game_size)[0] == (*game_size[1])))
		return (error(ERROR_BAD_ARGC));
	if (argv[4] != NULL)
	{
		*seed = (ft_atoi(argv[4]));
		if (*seed < 0)
			*seed *= -1;
		else if (*seed == MIN_INT_VALUE)
			*seed = MAX_INT_VALUE;
		else if (*seed == 0)
			*seed = 1;
		*seed = (*seed % 100) + 1;
	}
	else
		*seed = 1;
	return (0);
}

void	temp_set_input(t_input **input)
{
	int	stop_row;
	int	stop_col;

	stop_row = 0;
	stop_col = 0;
	while (stop_row != (*input)->game_size_h + 2)
	{
		(*input)->row.y[stop_row] = 0;
		++stop_row;
	}
	while (stop_col != (*input)->game_size_w + 2)
	{
		(*input)->col.x[stop_col] = 0;
		++stop_col;
	}
}

t_bool	auto_input2(t_input **input, t_solution **solution, t_random *random)
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
	switches(input, solution, &random);
	variables(input, solution, &random);
	temp_set_input(input);
	edit_map(*solution, (*input)->game_size_w, (*input)->game_size_h, random);
	//print_solution(*input, *solution, 0, 0);
	save_map(*solution, (*input)->game_size_w, (*input)->game_size_h);
	full_reset(3, input, solution, &random);
	return (0);
}

#endif