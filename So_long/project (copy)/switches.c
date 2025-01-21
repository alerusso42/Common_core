/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/21 11:57:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

// Forzando is_solved e is_correct, si fa terminare i tentativi
// prima del previsto.
t_bool	switches(t_input *input, t_solution *solution, t_random *random)
{
	input->switch_1_showuserinput = OFF;
	input->switch_2_ispossibletowin = ON;
	solution->is_solved = NO;
	solution->switch_1_showtries = ON;
	solution->switch_2_showcycles = ON;
	solution->switch_3_showblacklist = OFF;
	solution->switch_4_printonterminal = OFF;
	random->switch_1_showseed = OFF;
	random->switch_2_showrandomvalues = OFF;
	random->switch_3_choose_map_entities_num = ON;
	return (0);
}
