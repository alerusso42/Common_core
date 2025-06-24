/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:52:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

/*
	USER SETTINGS:

	input1->bonus: 	activate the bonus (DON'T USE IT! USE SO_LONG_BONUS);
					enables enemies and vary cool stuff;
	
	input2->rechargemap->	if ON, map always recharge;
	input3->confirm... ->	asks the user if he wants to exit;

	map2->printonterminal->	if active, prints the map on terminal.
							deactivated: I didn't norminette it lol
	
	random1->showseed->		useless lol
	random2->showrand...->	prints the "random" values used
	random3->choose...->	if ON, user can choose the number of
							enemies and other stuff.
*/
t_bool	switches(t_input *input, t_map *map, t_random *random)
{
	(void)input;
	map->is_solved = NO;
	input->switch_1_bonus = switch_to_bonus(input, map, random);
	input->switch_2_rechargemap = ON;
	input->switch_3_confirm_before_exit = ON;
	map->switch_2_printonterminal = OFF;
	random->switch_1_showseed = OFF;
	random->switch_2_showrandomvalues = OFF;
	random->switch_3_choose_map_entities_num = ON;
	return (0);
}
