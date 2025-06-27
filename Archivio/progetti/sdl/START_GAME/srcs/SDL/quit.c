/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:27:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/26 22:12:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	destroy_media(t_SDL *sdl);

void	free_all(t_data *data)
{
	destroy_media(&data->sdl);
	Mix_HaltMusic();
	if (data->sdl.win)
		SDL_DestroyWindow(data->sdl.win);
	if (data->sdl.render)
		SDL_DestroyRenderer(data->sdl.render);
	SDL_Quit();
	daft_quit();
	del_filedata();
}

static void	destroy_media(t_SDL *sdl)
{
	int	i;

	i = -1;
	while (sdl->mus[++i])
	{
		Mix_FreeMusic(sdl->mus[i]);
		sdl->mus[i] = NULL;
	}
	i = -1;
	while (sdl->sound[++i])
	{
		Mix_FreeChunk(sdl->sound[i]);
		sdl->sound[i] = NULL;
	}
	i = -1;
	while (sdl->texture[++i])
	{
		SDL_DestroyTexture(sdl->texture[i]);
		sdl->texture[i] = NULL;
	}
}