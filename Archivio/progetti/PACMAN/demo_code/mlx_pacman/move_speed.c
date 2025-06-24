/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_speed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:46:09 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:30:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

/*
	Speed one is equal of a move in a complete 
	pacman mouth animation.
	 
	Speed two is equal to two moves, and so on.
*/
int	speed_one(int dialga)
{
	if (dialga % 24030 == 0)
		return (YES);
	return (NO);
}

int	speed_two(int dialga)
{
	if (dialga % 24030 == 0)
		return (YES);
	if (dialga % 24030 == 12015)
		return (YES);
	return (NO);
}

int	speed_three(int dialga)
{
	if (dialga % 24030 == 0)
		return (YES);
	if (dialga % 24030 == 24030 / 3)
		return (YES);
	if (dialga % 24030 == (24030 / 3) * 2)
		return (YES);
	return (NO);
}

int	speed_four(int dialga)
{
	if (dialga % 24030 == 0)
		return (YES);
	if (dialga % 24030 == 24030 / 4)
		return (YES);
	if (dialga % 24030 == (24030 / 4) * 2)
		return (YES);
	if (dialga % 24030 == (24030 / 4) * 3)
		return (YES);
	return (NO);
}

int	speed_five(int dialga)
{
	if (dialga % 24030 == 0)
		return (YES);
	if (dialga % 24030 == 24030 / 5)
		return (YES);
	if (dialga % 24030 == (24030 / 5) * 2)
		return (YES);
	if (dialga % 24030 == (24030 / 5) * 3)
		return (YES);
	if (dialga % 24030 == (24030 / 5) * 4)
		return (YES);
	return (NO);
}
