/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/23 16:16:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

// Forzando is_solved e is_correct, si fa terminare i tentativi
// prima del previsto.
t_bool	switches(t_input *input, t_map *map, t_random *random)
{
	input->switch_1_bonus = ON;
	map->is_solved = NO;
	map->switch_1_showtries = ON;
	map->switch_2_showcycles = ON;
	map->switch_3_showblacklist = OFF;
	map->switch_4_printonterminal = OFF;
	random->switch_1_showseed = OFF;
	random->switch_2_showrandomvalues = OFF;
	random->switch_3_choose_map_entities_num = ON;
	return (0);
}
