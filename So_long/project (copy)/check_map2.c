/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 12:07:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	count_stuff(t_solution *solution, t_onebyte character, \
int size_x, int size_y);
int	first_chk_char(t_input *input, t_solution *solution);
int	find_stuff(t_solution *solution, t_onebyte c, int *x, int *y);
int	last_chk_path(t_input *input, t_solution *solution);

int	check_floodfill_result(t_input *input, t_solution *solution)
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;

	x = 0;
	y = 0;
	size_x = input->game_size_w;
	size_y = input->game_size_h;
	while (y != size_y)
	{
		x = 0;
		while (x != size_x)
		{
			if (!ft_strchr("X01", solution->position[x][y].value))
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}

void	floodfill(t_solution *solution, int x, int y)
{
	if ((solution->position[x][y].value == '1') || \
	(solution->position[x][y].value == 'X'))
		return ;
	solution->position[x][y].value = 'X';
	floodfill(solution, x + 1, y);
	floodfill(solution, x - 1, y);
	floodfill(solution, x, y + 1);
	floodfill(solution, x, y - 1);
}

int	last_chk_path(t_input *input, t_solution *solution)
{
	int	x;
	int	y;

	find_stuff(solution, 'P', &x, &y);
	floodfill(solution, x, y);
	if (check_floodfill_result(input, solution) == 1)
		return (1);
	return (0);
}

int	find_stuff(t_solution *solution, t_onebyte c, int *x, int *y)
{
	int	size_x;
	int	size_y;

	*y = 0;
	size_x = solution->game_size_w;
	size_y = solution->game_size_h;
	while (*y != size_y)
	{
		*x = 0;
		while (*x != size_x)
		{
			if (c == solution->position[*x][*y].value)
				return (0);
			(*x)++;
		}
		(*y)++;
	}
	return (1);
}

int	sixth_chk_colet(t_solution *solution, int size_x, int size_y)
{
	if (count_stuff(solution, 'E', size_x, size_y) < 1)
		return (1);
	return (0);
}

int	fifth_chk_enemy(t_solution *solution, int size_x, int size_y)
{
	int	enemy_num;

	enemy_num = solution->variable_3_enemy_num;
	if (count_stuff(solution, '$', size_x, size_y) != enemy_num)
		return (1);
	return (0);
}

int	first_chk_char(t_input *input, t_solution *solution)
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;

	x = 0;
	y = 0;
	size_x = input->game_size_w;
	size_y = input->game_size_h;
	while (y != size_y)
	{
		x = 0;
		while (x != size_x)
		{
			if (!ft_strchr(input->valid_signs, solution->position[x][y].value))
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}
