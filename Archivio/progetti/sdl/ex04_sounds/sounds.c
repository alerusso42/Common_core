/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:29:08 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/15 14:55:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	load_wav(t_sdl *sdl, int num, ...);

int	get_sound(t_sdl *sdl)
{
	int	error;

	if (Mix_OpenAudio(sdl->mix.frequency, sdl->mix.format, \
		sdl->mix.channels, sdl->mix.chunksize) != 0)
		return (10);
	sdl->mix.music = Mix_LoadMUS(S_MUSIC);
	if (sdl->mix.music == NULL)	
		return (11);
	error = load_wav(sdl, 7, S_BEGIN, S_CHOMP, S_DEATH, S_EATFRUIT, \
		S_EATGHOST, S_EXTRAPAC, S_INTERMISSION);
	return (0);
}

int	load_wav(t_sdl *sdl, int num, ...)
{
	va_list	ptr;
	char	*s;
	int		i;

	i = 0;
	va_start(ptr, num);
	while (num > 0)
	{
		s = (char *)va_arg(ptr, char *);
		sdl->mix.sound[i] = Mix_LoadWAV(s);
		if (sdl->mix.sound[i] == NULL)	
			return (printf("\nError in finding file %s\n", s));
		++i;
	}
	va_end(ptr);
}