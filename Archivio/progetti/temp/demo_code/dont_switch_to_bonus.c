/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dont_switch_to_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:53:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 15:50:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

/*
	Turn off every switch and variable related to bonus.
*/
int	switch_to_bonus(t_input *input, t_map *map, t_random *random)
{
	(void)input;
	map->switch_1_bonus = NO;
	(void)random;
	return (NO);
}
