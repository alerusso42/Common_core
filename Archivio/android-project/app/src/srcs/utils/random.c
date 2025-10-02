/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:34:29 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 10:35:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

//REVIEW - 	random
/*
	rand is used seeding it with srand() and time() in main().
*/
uint32_t	_random(int size)
{
	return (rand() % size);
}

//REVIEW - 	random_color
/*
	Colors are hexadecimal values, that needs size 24 bytes to store data:
	the first 8 bytes are red (most significant values), then 8 for
	green and blue.
	256 is 16^2 (8 bytes).
	They are multipled by multiples of 16 to differentiate them. 
*/
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
