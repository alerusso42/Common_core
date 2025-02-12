/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:58:08 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 14:40:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

/*
	Allocation for the input struct.
*/
int	alloc_user_input(t_input **input, int game_size[2])
{
	int	size_heigth;
	int	size_width;

	(*input) = ft_calloc(1, sizeof(t_input));
	if ((*input) == NULL)
		return (2);
	size_width = (sizeof(int)) * ((game_size[0]) + 4);
	size_heigth = (sizeof(int)) * ((game_size[1]) + 4);
	(*input)->col.x = (t_onebyte *)ft_calloc(size_width, 1);
	(*input)->row.y = (t_onebyte *)ft_calloc(size_heigth, 1);
	(*input)->game_size = game_size[0] * game_size[1];
	(*input)->game_size_w = game_size[0];
	(*input)->game_size_h = game_size[1];
	if (((*input)->col.x == NULL) || ((*input)->row.y == NULL))
	{
		return (ERROR_FULL_MEMORY);
	}
	return (0);
}

/*
	Over the map, there are two ivisible layer of values.
	They are not used in this implementation.
*/
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
