/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 16:02:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	check_map(t_input *input, t_solution *solution, int size_x, int size_y);
int	sixth_chk_colet(t_solution *solution, int size_x, int size_y);
int	fifth_chk_enemy(t_solution *solution, int size_x, int size_y);

int	count_stuff(t_solution *solution, t_onebyte character, \
int size_x, int size_y)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (y != size_y)
	{
		x = 0;
		while (x != size_x)
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

int	check_map(t_input *input, t_solution *solution, int size_x, int size_y)
{
	if ((size_x < 2) || (size_y < 2))
		return (l_printf("x e y devono essere >= 3\n"), 1);
	if (first_chk_char(input, solution) == 1)
		return (l_printf("GAME OVER1\n"));
	if (secon_chk_fillwall(solution, size_x, size_y) == 1)
		return (l_printf("GAME OVER2\n"));
	if (third_chk_player(solution, size_x, size_y) == 1)
		return (l_printf("GAME OVER3\n"));
	if (fourt_chk_exit(solution, size_x, size_y) == 1)
		return (l_printf("GAME OVER4\n"));
	if (fifth_chk_enemy(solution, size_x, size_y) == 1)
		return (l_printf("GAME OVER5\n"));
	if (sixth_chk_colet(solution, size_x, size_y) == 1)
		return (l_printf("GAME OVER6\n"));
	if (last_chk_path(input, solution) == 1)
		return (l_printf("GAME OVER7\n"));
	return (0);
}
