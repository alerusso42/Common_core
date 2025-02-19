/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:56:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/19 12:26:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		test(void);
void	game_loop(void);

/*
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
*/
void	game_loop(void)
{
	int			run;
	SDL_Event	event;

	run = 1;
	while (run)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				run = 0;
			if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == 27))
				run = 0;
			if (event.type == SDL_KEYDOWN)
				printf("Button pressed: %s (%d)\n", \
					SDL_GetKeyName(event.key.keysym.sym), \
					event.key.keysym.sym);
		}
	}
	return (0);
}

int	test(void)
{
	int			error;
	t_sdl		sdl;

	error = SDL_Init(SDL_INIT_VIDEO);
	if (error != 0)
		return (1);
	sdl.win = SDL_CreateWindow("SDL2 exercise", X, Y, W, H, 0);
	if (!sdl.win)
		return (2);
	game_loop();
	SDL_DestroyWindow(sdl.win);
	if (error != 0)
		return (2);
	return (0);
}
