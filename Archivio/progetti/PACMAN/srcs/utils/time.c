/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:34:13 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 18:00:23 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

//REVIEW - 	elapsed_time
/*
	Returns time passed, in milliseconds, between now and start time.
	Start time is a struct timeval already set with gettimeofday.
*/
uint64_t	elapsed_time(uint64_t start)
{
	uint64_t	curr;
	long		diff;

	curr = SDL_GetTicks();
	diff = curr - start;
	return (diff);
}
