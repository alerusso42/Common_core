/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:08:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:41:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

/*
	seed_1: x position;

	seed_2: y position;

	seed_3: enemy num.
*/
int	randomize_color(int seed_1, int seed_2, int seed_3)
{
	int				seed;
	static t_all	*all;

	if (all == NULL)
		all = storage_structs(all, GET);
	seed = seed_1 * seed_2 * seed_3;
	seed %= all->map->game_size;
	seed = all->random->values[seed];
	if (seed % 4 == 0)
		return (RED);
	if (seed % 4 == 1)
		return (CIAN);
	if (seed % 4 == 2)
		return (ORANGE);
	if (seed % 4 == 3)
		return (PURPLE);
	return (RED);
}
