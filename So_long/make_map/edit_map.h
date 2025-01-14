/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:21:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/14 23:00:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDIT_MAP_H
# define EDIT_MAP_H
# include "types.h"
# include "ft_printf.h"

void	third_step_player(t_solution *solution, int size_x, int size_y, \
t_random *random)
{
	int	rand_index;
	int	rand_value;
	int	game_size;
	int	x;
	int	y;

	rand_index = 0;
	game_size = (size_y * size_x);
	while ("Loop while you have placed a player in a non wall square")
	{
		rand_value = random->values[rand_index];
		y = game_size / rand_value;
		x = rand_value % size_x;
		if (solution->position[x][y].value == '0')
			break ;
		++rand_index;
		if (rand_index == game_size)
			return ;
	}
	solution->position[x][y].value = 'P';
}

void	secon_step_fillwall(t_solution *solution, int size_x, int size_y)
{
	int	y;
	int	x;

	x = 0;
	y = size_y;
	while (x != size_x - 1)
	{
		solution->position[x][y - 1].value = '1';
		solution->position[x][0].value = '1';
		++x;
	}
	while (y != 0)
	{
		--y;
		solution->position[0][y].value = '1';
		solution->position[size_x - 1][y].value = '1';
	}
}

int	edit_map(t_solution *solution, int size_x, int size_y, t_random *random)
{
	if ((size_x < 2) || (size_y < 2) || (size_x == size_y))
		return (ft_printf("x e y devono essere diversi, e >= 3\n"), 1);
	secon_step_fillwall(solution, size_x, size_y);
	third_step_player(solution, size_x, size_y, random);
}

#endif