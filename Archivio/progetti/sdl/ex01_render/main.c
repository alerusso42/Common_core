/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:56:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/19 15:38:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		test(void);
void	game_loop(t_sdl *sdl);
int		make_rect(t_sdl *sdl, int color);

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
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == 114)
					make_rect(sdl, 255000000);
				else if (event.key.keysym.sym == 103)
					make_rect(sdl, 000255000);
				else if (event.key.keysym.sym == 98)
					make_rect(sdl, 000000255);
			}
			sdl->runtime = SDL_GetTicks64() - sdl->frame_start;
			if (sdl->runtime < FRAME)
				SDL_Delay(FRAME - sdl->runtime);
		}
	}
}

void	quit_sdl(t_sdl *sdl)
{
	if (sdl->render)
		SDL_DestroyRenderer(sdl->render);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	*sdl = (t_sdl){0};
}

int	test(void)
{
	int			error;
	t_sdl		sdl;

	error = SDL_Init(SDL_INIT_VIDEO);
	if (error != 0)
		return (quit_sdl(&sdl), 1);
	sdl.win = SDL_CreateWindow("SDL2 exercise", X, Y, W, H, 0);
	if (!sdl.win)
		return (quit_sdl(&sdl), 2);
	sdl.render = SDL_CreateRenderer(sdl.win, -1, 0);
	if (!sdl.render)
		return (quit_sdl(&sdl), 3);
	error = make_rect(&sdl, 255255000);
	if (error != 0)
		return (quit_sdl(&sdl), error);
	game_loop(&sdl);
	return (quit_sdl(&sdl), 0);
}

/*
	Color is taken as follows:

	int that takes 9 cipher:
	1-3 represents RED;
	4-6 represents GREEN;
	7-9 represent BLUE.

	So, for example: 255255255 is white.
*/
int	make_rect(t_sdl *sdl, int color)
{
	int	r;
	int	g;
	int	b;

	sdl->color = color;
	b = color % 1000;
	color /= 1000;
	g = color % 1000;
	color /= 1000;
	r = color % 1000;
	if (SDL_SetRenderDrawColor(sdl->render, 0, 0, 0, 255) != 0)
		return (4);
	if (SDL_RenderClear(sdl->render) != 0)
		return (5);
	if (SDL_SetRenderDrawColor(sdl->render, r, g, b, 255) != 0)
		return (4);
	sdl->rect.x = 50;
	sdl->rect.y = 50;
	sdl->rect.w = 100;
	sdl->rect.h = 100;
	if (SDL_RenderFillRect(sdl->render, &sdl->rect) != 0)
		return (6);
	SDL_RenderPresent(sdl->render);
	return (0);
}
