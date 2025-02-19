/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:56:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/19 18:53:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		test(void);
void	game_loop(t_sdl *sdl);
int		make_surface(t_sdl *sdl);

/*
	ADDED: 

	1)	Rendering colors and rectangles;
	2)	Frame pause on loop;
	3)	Buttons to change colors.

	SDL_Get_Error() returns a string related to the last error
	recorded in this thread.
	SDL_Quit must be called even in case of errors.
*/
int	main(int argc, char *argv[])
{
	int			error;

	(void)argc;
	(void)argv;
	error = test();
	if (error != 0)
	{
		printf("ERROR: %d:\n\n%s\n", error, SDL_GetError());
	}
	SDL_Quit();
	return (0);
}

/*
	SDL_PollEvent manages unput taken from keyboard and
	other stuff, EVEN DURING LOOP RUNTIME.
	Like two different threads.

	type == SDL_QUIT: [X]
	key 27 == ESC

	This function prints the Button pressed if different
	than [X] and ESC.
	Alphabet and numbers are like in ASCII.

	114 = r;
	103 = g;
	98 = b.
*/
void	game_loop(t_sdl *sdl)
{
	SDL_Event	event;

	sdl->run = 1;
	while (sdl->run)
	{
		while (SDL_PollEvent(&event))
		{
			sdl->frame_start = SDL_GetTicks64();
			if ((event.type == SDL_QUIT) || ((event.type == SDL_KEYDOWN) && \
			(event.key.keysym.sym == 27)))
				sdl->run = 0;
			sdl->runtime = SDL_GetTicks64() - sdl->frame_start;
			if (sdl->runtime < FRAME)
				SDL_Delay(FRAME - sdl->runtime);
		}
	}
}

void	quit_sdl(t_sdl *sdl)
{
	if (sdl->texture)
		SDL_DestroyTexture(sdl->texture);
	if (sdl->surface)
		SDL_FreeSurface(sdl->surface);
	if (sdl->img_flags)
		IMG_Quit();
	if (sdl->render)
		SDL_DestroyRenderer(sdl->render);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
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
	error = SDL_Init(SDL_INIT_VIDEO);
	if (error != 0)
		return (quit_sdl(&sdl), 1);
	sdl.win = SDL_CreateWindow("SDL2 exercise", X, Y, W, H, 0);
	if (!sdl.win)
		return (quit_sdl(&sdl), 2);
	sdl.render = SDL_CreateRenderer(sdl.win, -1, 0);
	if (!sdl.render)
		return (quit_sdl(&sdl), 3);
	sdl.img_flags = IMG_Init(VALID_FILES);
	if ((sdl.img_flags & VALID_FILES) != VALID_FILES)
		return (quit_sdl(&sdl), 8);
	sdl.surface = IMG_Load("Pac.xpm");
	error = make_surface(&sdl);
	if (error != 0)
		return (quit_sdl(&sdl), error);
	game_loop(&sdl);
	return (quit_sdl(&sdl), 0);
}

/*
	Render_copy accepts a rectangle as parameter to put the
	image on precise location.
*/
int	make_surface(t_sdl *sdl)
{
	if (!sdl->surface)
		return (4);
	if (SDL_SetRenderDrawColor(sdl->render, 0, 0, 0, 255) != 0)
		return (5);
	if (SDL_RenderClear(sdl->render) != 0)
		return (5);
	sdl->texture = SDL_CreateTextureFromSurface(sdl->render, sdl->surface);
	if (!sdl->texture)
		return (6);
	sdl->rect.x = 50;
	sdl->rect.y = 50;
	sdl->rect.w = sdl->surface->w;
	sdl->rect.h = sdl->surface->h;
	if (SDL_RenderCopy(sdl->render, sdl->texture, NULL, &sdl->rect) != 0)
		return (7);
	SDL_RenderPresent(sdl->render);
	return (0);
}
