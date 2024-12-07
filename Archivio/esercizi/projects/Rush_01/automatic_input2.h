/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automatic_input2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:24:30 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/05 15:43:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATIC_INPUT2_H
# define AUTOMATIC_INPUT2_H
# include "types.h"
# include "general_ft.h"
# include "atoi.h"
# include "error_message.h"
# include "alloc_t_input.h"
# include "alloc_t_solution.h"
# include "alloc_t_random.h"
# include "random_numbers.h"

t_bool	fill_input(t_input **input, t_solution *solution);
t_bool	colup_fill(t_input **input, t_solution *solution, int x, int y);
t_bool	coldown_fill(t_input **input, t_solution *solution, int x, int y);
t_bool	rowleft_fill(t_input **input, t_solution *solution, int x, int y);
t_bool	rowright_fill(t_input **input, t_solution *solution, int x, int y);

t_bool	fill_input(t_input **input, t_solution *solution)
{
	t_bool	count_error;
	int		x;
	int		y;

	x = -1;
	y = -1;
	count_error = colup_fill(input, solution, x, y);
	count_error += coldown_fill(input, solution, x, y);
	count_error += rowleft_fill(input, solution, x, y);
	count_error += rowright_fill(input, solution, x, y);
	if (count_error == 0)
		return (YES);
	else
		return (NO);
}

t_bool	colup_fill(t_input **input, t_solution *solution, int x, int y)
{
	t_onebyte	record;
	t_onebyte	r_count;

	x = -1;
	y = (*input)->game_size;
	record = 0;
	r_count = 0;
	while (++x != (*input)->game_size)
	{
		while (--y != -1)
		{
			if (solution->position[x][y].value >= record)
			{
				record = solution->position[x][y].value;
				++r_count;
			}
		}
		(*input)->colup.x[x] = r_count;
		y = (*input)->game_size;
		record = 0;
		r_count = 0;
	}
	(*input)->colup.x[x] = 0;
	return (0);
}

t_bool	coldown_fill(t_input **input, t_solution *solution, int x, int y)
{
	t_onebyte	record;
	t_onebyte	r_count;

	x = -1;
	y = -1;
	record = 0;
	r_count = 0;
	while (++x != (*input)->game_size)
	{
		while (++y != (*input)->game_size)
		{
			if (solution->position[x][y].value >= record)
			{
				record = solution->position[x][y].value;
				++r_count;
			}
		}
		(*input)->coldown.x[x] = r_count;
		y = -1;
		record = 0;
		r_count = 0;
	}
	(*input)->coldown.x[x] = 0;
	return (0);
}

t_bool	rowleft_fill(t_input **input, t_solution *solution, int x, int y)
{
	t_onebyte	record;
	t_onebyte	r_count;

	x = -1;
	y = -1;
	record = 0;
	r_count = 0;
	while (++y != (*input)->game_size)
	{
		while (++x != (*input)->game_size)
		{
			if (solution->position[x][y].value >= record)
			{
				record = solution->position[x][y].value;
				++r_count;
			}
		}
		(*input)->rowleft.y[y] = r_count;
		x = -1;
		record = 0;
		r_count = 0;
	}
	(*input)->rowleft.y[y] = 0;
	return (0);
}

t_bool	rowright_fill(t_input **input, t_solution *solution, int x, int y)
{
	t_onebyte	record;
	t_onebyte	r_count;

	x = (*input)->game_size;
	y = -1;
	record = 0;
	r_count = 0;
	while (++y != (*input)->game_size)
	{
		while (--x != -1)
		{
			if (solution->position[x][y].value >= record)
			{
				record = solution->position[x][y].value;
				++r_count;
			}
		}
		(*input)->rowright.y[y] = r_count;
		x = (*input)->game_size;
		record = 0;
		r_count = 0;
	}
	(*input)->rowright.y[y] = 0;
	return (0);
}

#endif