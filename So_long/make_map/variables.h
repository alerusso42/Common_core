/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/15 17:14:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H
# include "general_ft.h"
# include "types.h"

t_bool	variables(t_input **input, t_solution **solution, t_random **random);
void	update_var(t_solution **solution, t_random **random);

// Siccome importiamo anche input,
// impostiamo una switch inutile per
// zittire le flags.
// variable_2_randomizer aumenta o diminuisce il ricorso a numeri casuali.
// randomizer == 0 non vengono mai usati valori casuali;
// randomizer == 1 vengono usati solo una volta, dopo un ciclo senza modifiche;
// randomizer == 2 come 1, ma i numeri casuali cambiano ad ogni tentativo;
// randomizer == 3 si usano solo valori random.
// in genere, il programma è più efficace ed efficiente con randomizer == 1.
t_bool	variables(t_input **input, t_solution **solution, t_random **random)
{
	(*input)->variable_0_shutupcompiler = ON;
	(*solution)->variable_1_player_num = 1;
	(*random)->variable_1_setseed = 0;
	(*random)->variable_2_randomizer = 1;
	(*random)->variable_3_enemy_num = 2;
	(*random)->variable_4_collectable_num = 3;
	(*random)->variable_5_internal_wall_num = 0;
	update_var(solution, random);
	return (0);
}

void	update_var(t_solution **solution, t_random **random)
{
	if ((*random)->variable_1_setseed != 0)
		(*random)->seed = (*random)->variable_1_setseed;
	(*solution)->wall_number = 2 * (*solution)->game_size_w + \
	2 * ((*solution)->game_size_h - 2);
	(*solution)->free_spaces = \
	(*solution)->game_size - ((*solution)->wall_number + 3);
	if ((*random)->switch_3_choose_map_entities_num == ON)
	{
		(*solution)->void_spaces = \
		(*solution)->free_spaces - (*random)->variable_3_enemy_num - \
		(*random)->variable_4_collectable_num - \
		(*random)->variable_5_internal_wall_num;
	}
	else
		(*solution)->void_spaces = 0;
	if ((*random)->variable_5_internal_wall_num == 0)
		(*random)->variable_5_internal_wall_num = (*solution)->void_spaces / 6;
	(*solution)->variable_3_enemy_num = (*random)->variable_3_enemy_num;
	(*solution)->variable_4_collectable_num = \
	(*random)->variable_4_collectable_num;
	(*solution)->variable_5_internal_wall_num = \
	(*random)->variable_5_internal_wall_num;
}

#endif
