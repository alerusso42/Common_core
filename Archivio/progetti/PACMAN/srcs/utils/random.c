/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:34:29 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/03 15:00:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

//REVIEW - 	random
/*
	Random number generator.
	Uses SDL_GetTicks64 with microseconds.
	Good for single assignment, bad for multiple assignment in an array.
*/
uint32_t	_random(int size)
{
	uint32_t	clock;
	
	clock = SDL_GetTicks();
	return (clock % size);
}

int	random_color(void)
{
	int	r;
	int	g;
	int	b;

	r = _random(256) * 16e4;
	g = _random(256) * 16e2;
	b = _random(256) * 16e0;
	return (r + g + b);
}
