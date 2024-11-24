/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/07 10:44:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESET_MEMORY_H
# define RESET_MEMORY_H
# include "types.h"
# include <stdarg.h>

int			full_reset(int struct_num, ...);
int			reset_memory_input(t_input **input);
int			reset_memory_sol(t_solution **solution, t_onebyte game_size);
int			reset_memory_list(t_solution **solution, t_onebyte game_size);
int			reset_memory_randlist(t_random **random);

/* 	La funzione variadica full_reset accetta come argomento il numero
	di strutture che vuoi liberare, e le strutture stesse.
	Resetta sempre nell'ordine input, solution, random:
	Perciò se volessi modificare il programma, presta molta attenzione
	a questo dettaglio, per evitare sgradite sorprese.
*/
int	full_reset(int struct_num, ...)
{
	va_list		ptr;
	t_input		**input;
	t_solution	**solution;
	t_random	**random;
	t_onebyte	game_size;

	va_start(ptr, struct_num);
	input = va_arg(ptr, t_input **);
	game_size = (*input)->game_size;
	reset_memory_input(input);
	if (struct_num < 2)
		va_end(ptr);
	if (struct_num < 2)
		return (1);
	solution = va_arg(ptr, t_solution **);
	reset_memory_list(solution, game_size);
	reset_memory_sol(solution, game_size);
	if (struct_num < 3)
		va_end(ptr);
	if (struct_num < 3)
		return (2);
	random = va_arg(ptr, t_random **);
	reset_memory_randlist(random);
	va_end(ptr);
	return (3);
}

int	reset_memory_input(t_input **input)
{
	if ((*input) != NULL)
	{
		if ((*input)->colup.x != NULL)
			free((*input)->colup.x);
		if ((*input)->coldown.x != NULL)
			free((*input)->coldown.x);
		if ((*input)->rowright.y != NULL)
			free((*input)->rowright.y);
		if ((*input)->rowleft.y != NULL)
			free((*input)->rowleft.y);
		(*input)->colup.x = NULL;
		(*input)->coldown.x = NULL;
		(*input)->rowright.y = NULL;
		(*input)->rowleft.y = NULL;
		free((*input));
		(*input) = NULL;
	}
	return (0);
}

int	reset_memory_list(t_solution **solution, t_onebyte game_size)
{
	t_solution	*p;
	int			col;
	int			row;

	p = (*solution);
	col = -1;
	row = -1;
	while ((++row != game_size + 1))
	{
		while ((++col != game_size + 1))
		{
			if (p->position[col][row].black_list != NULL)
			{
				free(p->position[col][row].black_list);
				p->position[col][row].black_list = NULL;
			}
		}
		col = -1;
	}
	return (0);
}

int	reset_memory_sol(t_solution **solution, t_onebyte game_size)
{
	int			index;
	t_solution	*p;

	index = 0;
	p = (*solution);
	while ((p->position[index] != NULL)
		&& (index <= ((game_size) + 1)))
	{
		free(p->position[index]);
		p->position[index] = NULL;
		++index;
	}
	if (p->position != NULL)
	{
		free(p->position);
		p->position = NULL;
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	return (0);
}

int	reset_memory_randlist(t_random **random)
{
	if ((*random)->values != NULL)
	{
		free((*random)->values);
		(*random)->values = NULL;
	}
	if ((*random) != NULL)
	{
		free(*random);
		*random = NULL;
	}
	return (0);
}

#endif
