/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_control.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:54:09 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/04 22:59:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_CONTROL_H
# define SOLVE_CONTROL_H
# include "types.h"

t_bool	check_sol(t_input *input, t_solution *solution);
t_bool	colup_control(t_input *input, t_solution *solution, int x, int y);
t_bool	coldown_control(t_input *input, t_solution *solution, int x, int y);
t_bool	rowleft_control(t_input *input, t_solution *solution, int x, int y);
t_bool	rowright_control(t_input *input, t_solution *solution, int x, int y);

/* 	Queste funzioni controllano che la soluzione calcolata dal
	programma, attraverso il metodo del sudoku, rispetti anche
	le regole dei grattacieli.
	Per fare questo, usa il metodo del record: per ogni colonna e riga,
	registra il primo numero che trova, e conta quante volte,
	scorrendo, trova un numero maggiore.
	Se il conteggio è uguale al numero dei grattacieli visibili, top,
	altrimenti schiaffi e si ricomincia.
*/
// Vedi solve_control.h.
t_bool	check_sol(t_input *input, t_solution *solution)
{
	t_bool	count_error;
	int		x;
	int		y;

	x = -1;
	y = -1;
	count_error = colup_control(input, solution, x, y);
	count_error += coldown_control(input, solution, x, y);
	count_error += rowleft_control(input, solution, x, y);
	count_error += rowright_control(input, solution, x, y);
	if (count_error == 0)
		return (YES);
	else
		return (NO);
}

t_bool	colup_control(t_input *input, t_solution *solution, int x, int y)
{
	t_onebyte	record;
	t_onebyte	r_count;

	x = -1;
	y = input->game_size;
	record = 0;
	r_count = 0;
	while (++x != input->game_size)
	{
		while (--y != -1)
		{
			if (solution->position[x][y].value >= record)
			{
				record = solution->position[x][y].value;
				++r_count;
			}
		}
		if (r_count != input->colup.x[x])
			return (1);
		y = input->game_size;
		record = 0;
		r_count = 0;
	}
	return (0);
}

t_bool	coldown_control(t_input *input, t_solution *solution, int x, int y)
{
	t_onebyte	record;
	t_onebyte	r_count;

	x = -1;
	y = -1;
	record = 0;
	r_count = 0;
	while (++x != input->game_size)
	{
		while (++y != input->game_size)
		{
			if (solution->position[x][y].value >= record)
			{
				record = solution->position[x][y].value;
				++r_count;
			}
		}
		if (r_count != input->coldown.x[x])
			return (1);
		y = -1;
		record = 0;
		r_count = 0;
	}
	return (0);
}

t_bool	rowleft_control(t_input *input, t_solution *solution, int x, int y)
{
	t_onebyte	record;
	t_onebyte	r_count;

	x = -1;
	y = -1;
	record = 0;
	r_count = 0;
	while (++y != input->game_size)
	{
		while (++x != input->game_size)
		{
			if (solution->position[x][y].value >= record)
			{
				record = solution->position[x][y].value;
				++r_count;
			}
		}
		if (r_count != input->rowleft.y[y])
			return (1);
		x = -1;
		record = 0;
		r_count = 0;
	}
	return (0);
}

t_bool	rowright_control(t_input *input, t_solution *solution, int x, int y)
{
	t_onebyte	record;
	t_onebyte	r_count;

	x = input->game_size;
	y = -1;
	record = 0;
	r_count = 0;
	while (++y != input->game_size)
	{
		while (--x != -1)
		{
			if (solution->position[x][y].value >= record)
			{
				record = solution->position[x][y].value;
				++r_count;
			}
		}
		if (r_count != input->rowright.y[y])
			return (1);
		x = input->game_size;
		record = 0;
		r_count = 0;
	}
	return (0);
}

#endif