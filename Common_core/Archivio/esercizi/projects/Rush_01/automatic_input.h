/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automatic_input.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/05 18:09:49 by alerusso         ###   ########.fr       */
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
# include "automatic_input2.h"
# include "solve_game.h"

t_bool	automatic_input(int argc, char *argv[], int game_size, int seed);
t_bool	parsing(int argc, char *argv[], int *game_size, int *seed);
t_bool	auto_input2(t_input **input, t_solution **solution, t_random *random);
t_bool	cheat(t_input **input, t_solution **solution, t_random **random);
int		initialize_input(t_input **input);
int		ft_start(t_input **input, t_solution **solution, t_random *random);

t_bool	automatic_input(int argc, char *argv[], int game_size, int seed)
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
	if (alloc_randomlist(&random) != 0)
	{
		full_reset(2, input, solution);
		return (3);
	}
	random->seed = seed + switches(&input, &solution, &random);
	variables(&input, &solution, &random);
	solution->game_size = game_size;
	return (auto_input2(&input, &solution, random));
}

t_bool	parsing(int argc, char *argv[], int *game_size, int *seed)
{
	if ((argc == 2) || (argc > 4))
		return (error(ERROR_BAD_ARGC));
	*game_size = ft_atoi(argv[2]);
	if ((*game_size < 1) || (*game_size > 9))
		return (error(ERROR_BAD_ARGC));
	if (argv[3] != NULL)
	{
		*seed = (ft_atoi(argv[3]));
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

t_bool	auto_input2(t_input **input, t_solution **solution, t_random *random)
{
	int	seed;

	seed = random->seed;
	fill_random(&random, *input);
	while (seed-- == 0)
	{
		if (seed % 2 == 0)
			twist_random(&random);
		else if (seed % 3 == 0)
			twist_random2(&random);
		else if (seed % 7 == 0)
			twist_random3(&random);
	}
	fill_solution(solution, (*solution)->game_size);
	initialize_input(input);
	cheat(input, solution, &random);
	solve_game(input, solution, random);
	switches(input, solution, &random);
	variables(input, solution, &random);
	fill_input(input, *solution);
	fill_solution(solution, (*solution)->game_size);
	return (error(ft_start(input, solution, random)));
}

int	initialize_input(t_input **input)
{
	int			in_index;
	t_onebyte	game_size;

	in_index = -1;
	game_size = (*input)->game_size;
	while (++in_index < game_size)
		(*input)->colup.x[in_index] = 0;
	in_index = -1;
	while (++in_index < game_size)
		(*input)->coldown.x[in_index] = 0;
	in_index = -1;
	while (++in_index < game_size)
		(*input)->rowleft.y[in_index] = 0;
	in_index = -1;
	while (++in_index < game_size)
		(*input)->rowright.y[in_index] = 0;
	(*input)->colup.x[(game_size)] = 0;
	(*input)->coldown.x[(game_size)] = 0;
	(*input)->rowright.y[(game_size)] = 0;
	(*input)->rowleft.y[(game_size)] = 0;
	return (0);
}

t_bool	cheat(t_input **input, t_solution **solution, t_random **random)
{
	(*input)->switch_1_showuserinput = OFF;
	(*input)->switch_2_ispossibletowin = OFF;
	(*solution)->is_solved = NO;
	(*solution)->is_correct = YES;
	(*solution)->switch_1_showtries = OFF;
	(*solution)->switch_2_showcycles = OFF;
	(*solution)->switch_3_showblacklist = OFF;
	(*random)->switch_1_showseed = OFF;
	(*random)->switch_2_showrandomvalues = OFF;
	(*random)->variable_2_randomizer = 1;
	return (0);
}

#endif