/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:42:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	dialga(unsigned int ms)
{
	if (ms % 4 == 0)
		return (0);
	if (ms % 4 == 1)
		return (1);
	if (ms % 4 == 2)
		return (2);
	if (ms % 4 == 3)
		return (1);
	return (-1);
}

void	quit_sdl(t_sdl *sdl)
{
	int	index;

	index = 0;
	while (index != 3)
	{
		if (sdl->img[index].texture)
			SDL_DestroyTexture(sdl->img[index].texture);
		if (sdl->img[index].surface)
			FREESurface(sdl->img[index].surface);
		++index;
	}
	if (sdl->img_flags)
		IMG_Quit();
	if (sdl->render)
		SDL_DestroyRenderer(sdl->render);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	if (sdl->mix.music)
		Mix_FreeMusic(sdl->mix.music);
	index = 0;
	while (sdl->mix.sound[index])
		Mix_FreeChunk(sdl->mix.sound[index++]);
	Mix_HaltMusic();
	Mix_HaltChannel(-1);
	SDL_CloseAudio();
	*sdl = (t_sdl){0};
}

/*
	VALID_FILES is a enum value that store all the binary
	values of the files that can be accepted.

	Process to init a pic:

	1) 	Declare IMG_Init to set the images you want to accept.
		Consider the errors by doing a bitwise operation;
	2)	Load the images in the surfaces with IMG_Load;
	3)	Remember to call IMG_Quit before exit!
*/
int	test(void)
{
	int			error;
	t_sdl		sdl;

	sdl = (t_sdl){0};
	int num_drivers = SDL_GetNumAudioDrivers();
for (int i = 0; i < num_drivers; i++)
    printf("Audio Driver %d: %s\n", i, SDL_GetAudioDriver(i));

	SDL_setenv("SDL_AUDIODRIVER", "pulseaudio", 1);
	error = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
	if (error != 0)
		return (quit_sdl(&sdl), 1);
	sdl.win = SDL_CreateWindow("SDL2 exercise", X, Y, W, H, 0);
	if (!sdl.win)
		return (quit_sdl(&sdl), 2);
	sdl.render = SDL_CreateRenderer(sdl.win, -1, 0);
	if (!sdl.render)
		return (quit_sdl(&sdl), 3);
	error = get_images(&sdl);
	if (error != 0)
		return (quit_sdl(&sdl), error);
	error = get_sounds(&sdl);
	if (error != 0)
		return (quit_sdl(&sdl), error);
	game_loop(&sdl);
	return (quit_sdl(&sdl), 0);
}

int	get_images(t_sdl *sdl)
{
	sdl->img_flags = IMG_Init(VALID_FILES);
	if ((sdl->img_flags & VALID_FILES) != VALID_FILES)
		return (8);
	sdl->img[0].surface = IMG_Load("Pac_open_right.xpm");
	sdl->img[1].surface = IMG_Load("Pac_half_right.xpm");
	sdl->img[2].surface = IMG_Load("Pac_close_right.xpm");
	if ((sdl->img[0].surface == NULL) || \
	(sdl->img[1].surface == NULL) || \
	(sdl->img[2].surface == NULL))
		return (9);
	sdl->img[0].texture = SDL_CreateTextureFromSurface\
	(sdl->render, sdl->img[0].surface);
	sdl->img[1].texture = SDL_CreateTextureFromSurface\
	(sdl->render, sdl->img[1].surface);
	sdl->img[2].texture = SDL_CreateTextureFromSurface\
	(sdl->render, sdl->img[2].surface);
	if ((sdl->img[0].texture == NULL) || \
	(sdl->img[1].texture == NULL) || \
	(sdl->img[2].texture == NULL))
		return (9);
	return (0);
}

/*
	Render_copy accepts a rectangle as parameter to put the
	image on precise location.
*/
int	update_screen(t_sdl *sdl, int *which)
{
	if (*which > 2 || *which < 0)
		return (-1);
	if (SDL_SetRenderDrawColor(sdl->render, 0, 0, 0, 255) != 0)
		return (5);
	if (SDL_RenderClear(sdl->render) != 0)
		return (5);
	sdl->rect.x = 50;
	sdl->rect.y = 50;
	sdl->rect.w = sdl->img[*which].surface->w;
	sdl->rect.h = sdl->img[*which].surface->h;
	if (SDL_RenderCopy(sdl->render, sdl->img[*which].texture, NULL, &sdl->rect)\
	 != 0)
		return (7);
	SDL_RenderPresent(sdl->render);
	return (0);
}
