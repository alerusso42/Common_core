/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:51:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 03:42:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	set_sound_ending(int channel)
{
	t_data *data;

	(void)channel;
	data = getter(NULL, false);
	SDL_AtomicSet(&data->sdl.sound_playing, false);
}

void	wait_sound_ending(t_data *data)
{
	int	wait_chunk;

	SDL_AtomicSet(&data->sdl.sound_playing, true);
	wait_chunk = 20;
	while (SDL_AtomicGet(&data->sdl.sound_playing) == true)
		SDL_Delay(wait_chunk);
}