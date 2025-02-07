/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dont_switch_to_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:53:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/07 14:44:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

int	switch_to_bonus(t_input *input, t_map *map, t_random *random)
{
	(void)input;
	map->switch_1_bonus = YES;
	(void)random;
	return (YES);
}
