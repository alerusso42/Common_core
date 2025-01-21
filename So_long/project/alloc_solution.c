/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:34:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 11:48:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int		alloc_sol(t_input **input, t_map **map);
int		full_reset(int struct_num, ...);
int		alloc_bwlist(t_input **input, t_map **map);

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
int	alloc_sol(t_input **input, t_map **map)
{
	int	index;
	int	size_h;
	int	size_w;

	size_w = (((*input)->game_size_w) + 2);
	size_h = ((*input)->game_size_h) + 2;
	(*map) = malloc(sizeof(t_map));
	if ((*map) != NULL)
		(*map)->position = ft_calloc((size_w), sizeof(t_position));
	if (((*map) == NULL) || ((*map)->position) == NULL)
		return (full_reset(2, input, map), 3);
	index = -1;
	while (++index != (*input)->game_size_w + 1)
	{
		(*map)->position[index] = ft_calloc((size_h),\
		 sizeof(char *) * 2);
		if ((*map)->position[index] == NULL)
			return (full_reset(2, input, map), 3);
	}
	(*map)->game_size = (*input)->game_size;
	(*map)->game_size_w = (*input)->game_size_w;
	(*map)->game_size_h = (*input)->game_size_h;
	return (0);
}

void	fill_map(t_map **map, int row_n, int col_n)
{
	int			col;
	int			row;

	row = -1;
	col = -1;
	while ((++row != row_n + 1))
	{
		while ((++col != col_n + 1))
		{
			(*map)->position[col][row].value = 48;
		}
		col = -1;
	}
}
