/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:27:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/25 00:54:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while (data->sdl.mus[++i])
	{
		Mix_FreeMusic(data->sdl.mus[i]);
		data->sdl.mus[i] = NULL;
	}
	i = -1;
	while (data->sdl.sound[++i])
	{
		Mix_FreeChunk(data->sdl.sound[i]);
		data->sdl.sound[i] = NULL;
	}
	Mix_HaltMusic();
	if (data->sdl.win)
		SDL_DestroyWindow(data->sdl.win);
	if (data->sdl.render)
		SDL_DestroyRenderer(data->sdl.render);
	SDL_Quit();
	daft_quit();
	del_filedata();
}