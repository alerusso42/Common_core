/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/15 17:11:23 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H
# include "types.h"
# include "ft_printf.h"

int	count_stuff(t_solution *solution, t_onebyte character, \
int size_x, int size_y)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (y != size_y - 1)
	{
		x = 0;
		while (x != size_x - 1)
		{
			if (character == solution->position[x][y].value)
				++count;
			++x;
		}
		y++;
	}
	return (count);
}

int	fourt_chk_exit(t_solution *solution, int size_x, int size_y)
{
	if (count_stuff(solution, 'E', size_x, size_y) != 1)
		return (1);
	return (0);
}

int	third_chk_player(t_solution *solution, int size_x, int size_y)
{
	if (count_stuff(solution, 'P', size_x, size_y) != 1)
		return (1);
	return (0);
}

int	secon_chk_fillwall(t_solution *solution, int size_x, int size_y)
{
	int	y;
	int	x;

	x = 0;
	y = size_y;
	while (x != size_x - 1)
	{
		if (solution->position[x][y - 1].value != '1')
			return (1);
		if (solution->position[x][0].value != '1')
			return (1);
		++x;
	}
	while (y != 0)
	{
		--y;
		if (solution->position[0][y].value != '1')
			return (1);
		if (solution->position[size_x - 1][y].value != '1')
			return (1);
	}
	return (0);
}

int	check_map(t_solution *solution, int size_x, int size_y)
{
	if ((size_x < 2) || (size_y < 2) || (size_x == size_y))
		return (ft_printf("x e y devono essere diversi, e >= 3\n"), 1);
	if (secon_chk_fillwall(solution, size_x, size_y) == 1)
		return (ft_printf("GAME OVER\n"));
	third_chk_player(solution, size_x, size_y);
	
	return (0);
}

#endif