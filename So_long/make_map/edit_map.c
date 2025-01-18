/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:21:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 16:02:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	sort_coordinates(t_solution *solution, t_random *random, int *x, int *y)
{
	static int	rand_index;
	int			rand_value;
	int			game_size;

	if ((!solution) || (!random))
	{
		rand_index = 0;
		return (0);
	}
	game_size = (solution->game_size_w) * (solution->game_size_h);
	while ("Loop until you have found a free square")
	{
		rand_value = random->values[rand_index];
		*y = rand_value / (solution->game_size_w);
		*x = rand_value % (solution->game_size_w);
		if ((rand_value != -1) && (rand_value != game_size) \
		&& (solution->position[*x][*y].value == '0'))
		{
			++rand_index;
			break ;
		}
		if (rand_index++ == game_size)
			return (1);
	}
	return (0);
}

void	fourt_step_exit(t_solution *solution, t_random *random)
{
	int	x;
	int	y;
	
	if (sort_coordinates(solution, random, &x, &y) == 1)
		return ;
	solution->position[x][y].value = 'E';
	sort_coordinates(NULL, NULL, NULL, NULL);
}

void	third_step_player(t_solution *solution, t_random *random)
{
	int	x;
	int	y;
	
	if (sort_coordinates(solution, random, &x, &y) == 1)
		return ;
	solution->position[x][y].value = 'P';
	sort_coordinates(NULL, NULL, NULL, NULL);
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
	if ((size_x < 2) || (size_y < 2))
		return (l_printf("x e y devono essere >= 3\n"), 1);
	if ((solution->free_spaces < 0))
		return (l_printf\
		("Una board di %d per %d ha %d spazi liberi: P, E, C non entrano", \
		solution->game_size_w, solution->game_size_h, solution->free_spaces\
		 + 3));
	secon_step_fillwall(solution, size_x, size_y);
	third_step_player(solution, random);
	if (random->variable_3_enemy_num > solution->free_spaces)
		return (l_printf("Gli spazi liberi sono %d, i nemici inseriti %d\n", \
		solution->free_spaces, random->variable_3_enemy_num));
	fourt_step_exit(solution, random);
	if (random->switch_3_choose_map_entities_num == ON)
		if (solution->void_spaces < 0)
			return (l_printf("Non c'e abbastanza spazio per tutto.\n"));
	fifth_step_enemy(solution, random);
	sixth_step_colet(solution, random);
	last_step_walls(solution, random);
	return (0);
}
