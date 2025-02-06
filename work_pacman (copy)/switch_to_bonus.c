/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_to_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:53:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 17:00:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	switch_to_bonus(t_input *input, t_map *map, t_random *random)
{
	(void)input;
	map->switch_1_bonus = YES;
	(void)random;
	return (YES);
}
