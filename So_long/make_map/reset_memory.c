/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 10:58:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int				full_reset(int struct_num, ...);
static int		reset_memory_input(t_input **input);
static int		reset_memory_sol(t_solution **solution, int game_size[2]);
//int		reset_memory_list(t_solution **solution, int game_size[2]);
static int		reset_memory_randlist(t_random **random);

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
	int			game_size[2];

	va_start(ptr, struct_num);
	input = va_arg(ptr, t_input **);
	game_size[0] = (*input)->game_size_w;
	game_size[1] = (*input)->game_size_h;
	reset_memory_input(input);
	if (struct_num < 2)
		va_end(ptr);
	if (struct_num < 2)
		return (1);
	solution = va_arg(ptr, t_solution **);
	//reset_memory_list(solution, game_size);
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

static int	reset_memory_input(t_input **input)
{
	if ((*input) != NULL)
	{
		if ((*input)->col.x != NULL)
			free((*input)->col.x);
		if ((*input)->row.y != NULL)
			free((*input)->row.y);
		(*input)->col.x = NULL;
		(*input)->row.y = NULL;
		free((*input));
		(*input) = NULL;
	}
	return (0);
}

/*
int	reset_memory_list(t_solution **solution, int game_size[2])
{
	t_solution	*p;
	int			col;
	int			row;

	p = (*solution);
	col = -1;
	row = -1;
	while ((++row != game_size[0] + 1))
	{
		while ((++col != game_size[1] + 1))
		{
			if (p->position[row][col].black_list != NULL)
			{
				free(p->position[row][col].black_list);
				p->position[row][col].black_list = NULL;
			}
			else
				return (0);
		}
		col = -1;
	}
	return (0);
}*/

static int	reset_memory_sol(t_solution **solution, int game_size[2])
{
	int			index;
	t_solution	*p;

	index = 0;
	p = (*solution);
	while ((p->position[index] != NULL)
		&& (index <= ((game_size[0]) + 1)))
	{
		free(p->position[index]);
		p->position[index] = NULL;
		++index;
	}
	index = 0;
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

static int	reset_memory_randlist(t_random **random)
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
