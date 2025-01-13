/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_t_solution.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:34:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/11 20:11:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_T_SOLUTION_H
# define ALLOC_T_SOLUTION_H
# include "alloc_t_input.h"
# include "types.h"
# include "ft_printf.h"

int		alloc_sol(t_input **input, t_solution **solution);
int		alloc_bwlist(t_input **input, t_solution **solution);
void	fill_solution(t_solution **solution, t_onebyte game_size);

/* 	Perchè allochiamo ((*input)->game_size) + 2)^2?
	Se la scacchiera è grande 3x3, ci servono 9 quadretti, quindi
	solo game_size^2.
	Ho deciso di allocare un byte in più per inserire 0 come valore
	di fine stringa al termine di ogni riga e di ogni colonna, per
	poter segnalare, in caso, la fine di una riga con uno zero,
	per evitare il segmentation fault.
	Quindi game_size + 1 alla seconda.
	Ma allora perchè game_size + 2? Perchè il compilatore vuole un
	byte in più per sicurezza. Altrimenti, fa le bizze.
	Provare per credere.
*/
int	alloc_sol(t_input **input, t_solution **solution)
{
	int	index;
	int	size_h;
	int	size_w;

	size_h = (((*input)->game_size_h) + 2) * (((*input)->game_size_w) + 2);
	(*solution) = malloc(sizeof(t_solution));
	if ((*solution) != NULL)
		(*solution)->position = malloc(sizeof(t_solution *) * (size_h));
	if (((*solution) == NULL) || ((*solution)->position) == NULL)
		return (full_reset(2, input, solution), 3);
	index = -1;
	while (++index != (*input)->game_size_h + 1)
	{
		(*solution)->position[index] = malloc(sizeof(t_position *) * (size_w));
		if ((*solution)->position[index] == NULL)
		{
			full_reset(2, input, solution);
			return (3);
		}
	}
	(*solution)->game_size = (*input)->game_size;
	alloc_bwlist(input, solution);
	return (0);
}

/* 	Perchè adesso allochiamo (game_size * 2) + 3? 
	La black_list è un array diviso in due parti: i valori che
	non cambiano, sicuri (segnalati dal carattere iniziale 101 e il
	carattere terminatore 102) e temporanei (segnalati tra 102 e 103);
	ogni range ha un numero di valori pari a game_size, pertanto
	è necessario allocare il doppio della dimensione di game_size,
	più 3 byte per i 3 caratteri terminatori.
*/
int	alloc_bwlist(t_input **input, t_solution **solution)
{
	int			col;
	int			row;
	int			size_memory;
	t_onebyte	game_size;

	game_size = (*input)->game_size;
	col = -1;
	row = -1;
	size_memory = sizeof(t_onebyte) * ((game_size * 2) + 3);
	while ((++row != game_size + 1))
	{
		while ((++col != game_size + 1))
		{
			(*solution)->position[col][row].black_list = malloc((size_memory));
			if ((*solution)->position[col][row].black_list == NULL)
			{
				full_reset(2, input, solution);
				return (3);
			}
		}
		col = -1;
	}
	return (0);
}

void	fill_solution(t_solution **solution, t_onebyte game_size)
{
	int			col;
	int			row;
	t_onebyte	counter;

	row = -1;
	col = -1;
	counter = 0;
	while ((++row != game_size + 1))
	{
		while ((++col != game_size + 1))
		{
			(*solution)->position[col][row].value = 0;
			(*solution)->position[col][row].is_sure = 0;
			(*solution)->position[col][row].u_score = game_size;
			(*solution)->position[col][row].black_list[0] = 101;
			while (++counter != game_size + 1)
				(*solution)->position[col][row].black_list[counter] = 0;
			(*solution)->position[col][row].black_list[counter] = 102;
			while (++counter != (game_size + 1) * 2)
				(*solution)->position[col][row].black_list[counter] = 0;
			(*solution)->position[col][row].black_list[counter] = 103;
			counter = 0;
		}
		col = -1;
	}
}

#endif