/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_logic2.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:27:00 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/04 23:03:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_LOGIC2_H
# define SOLVE_LOGIC2_H
# include "types.h"
# include "solve_logic.h"
# include "blacklist_update.h"

void	rule4_colup(t_input *input, t_solution **solution, int x);
void	rule4_coldown(t_input *input, t_solution **solution, int x);
void	rule4_rowleft(t_input *input, t_solution **solution, int y);
void	rule4_rowright(t_input *input, t_solution **solution, int y);
void	ft_locknumbers(t_solution **solution);

void	rule4_colup(t_input *input, t_solution **solution, int x)
{
	int	n;
	int	m;
	int	gs;

	n = -1;
	m = -1;
	gs = input->game_size;
	while (++x != gs)
	{
		if ((input->colup.x[x] != 1) && (input->colup.x[x] != gs))
		{
			while (++m != input->colup.x[x] - 1)
			{
				while (++n != input->colup.x[x] - 1 - m)
					upbl_sure(solution, x, (gs - m - 1), (gs - n));
				n = -1;
			}
			m = -1;
		}
	}
}

void	rule4_coldown(t_input *input, t_solution **solution, int x)
{
	int	n;
	int	m;
	int	gs;

	n = -1;
	m = -1;
	gs = input->game_size;
	while (++x != gs)
	{
		if ((input->coldown.x[x] != 1) && (input->coldown.x[x] != gs))
		{
			while (++m != input->coldown.x[x] - 1)
			{
				while (++n != input->coldown.x[x] - 1 - m)
					upbl_sure(solution, x, m, (gs - n));
				n = -1;
			}
			m = -1;
		}
	}
}

void	rule4_rowleft(t_input *input, t_solution **solution, int y)
{
	int	n;
	int	m;
	int	gs;

	n = -1;
	m = -1;
	gs = input->game_size;
	while (++y != gs)
	{
		if ((input->rowleft.y[y] != 1) && (input->rowleft.y[y] != gs))
		{
			while (++m != input->rowleft.y[y] - 1)
			{
				while (++n != input->rowleft.y[y] - 1 - m)
					upbl_sure(solution, m, y, (gs - n));
				n = -1;
			}
			m = -1;
		}
	}
}

void	rule4_rowright(t_input *input, t_solution **solution, int y)
{
	int	n;
	int	m;
	int	gs;

	n = -1;
	m = -1;
	gs = input->game_size;
	while (++y != gs)
	{
		if ((input->rowright.y[y] != 1) && (input->rowright.y[y] != gs))
		{
			while (++m != input->rowright.y[y] - 1)
			{
				while (++n != input->rowright.y[y] - 1 - m)
					upbl_sure(solution, (gs - m - 1), y, (gs - n));
				n = -1;
			}
			m = -1;
		}
	}
}

/*	Una volta che vengono trovati i valori sicuri, questa funzione
	li locka, impostando il parametro .is_sure a 1.
*/
void	ft_locknumbers(t_solution **solution)
{
	int			col;
	int			row;
	t_onebyte	game_size;

	row = -1;
	col = -1;
	game_size = (*solution)->game_size;
	while ((++row != game_size + 1))
	{
		while ((++col != game_size + 1))
		{
			if ((*solution)->position[col][row].value != 0)
				(*solution)->position[col][row].is_sure = 1;
		}
		col = -1;
	}
}

#endif