/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/10 12:11:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

// Forzando is_solved e is_correct, si fa terminare i tentativi
// prima del previsto.
t_bool	switches(t_input *input, t_map *map, t_random *random)
{
	(void)input;
	map->is_solved = NO;
	input->switch_1_bonus = switch_to_bonus(input, map, random);
	map->switch_2_printonterminal = OFF;
	random->switch_1_showseed = OFF;
	random->switch_2_showrandomvalues = OFF;
	random->switch_3_choose_map_entities_num = ON;
	return (0);
}
