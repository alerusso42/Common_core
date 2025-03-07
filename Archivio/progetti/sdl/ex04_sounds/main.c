/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:56:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/19 21:37:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	screen_animations(t_sdl *sdl, int animator)
{
	SDL_Event	event;

	sdl->curr_img = dialga(animator);
	if (sdl->curr_img == -1)
		return (0);
	event.type = UPDATE_SCREEN;
	event.user.data1 = (void *)&sdl->curr_img;
	SDL_PushEvent(&event);
	return (0);
}

unsigned int	timer(unsigned int interval, void *param)
{
	static int	animator;

	screen_animations((t_sdl *)param, animator);
	++animator;
	return (interval);
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
	SDL_TimerID	timer_id;

	sdl->run = 1;
	timer_id = SDL_AddTimer(150, timer, (void *)sdl);
	while (sdl->run)
	{
		while (SDL_PollEvent(&event))
		{
			sdl->frame_start = SDL_GetTicks64();
			if ((event.type == SDL_QUIT) || ((event.type == SDL_KEYDOWN) && \
			(event.key.keysym.sym == 27)))
				sdl->run = 0;
			else if (event.type == UPDATE_SCREEN)
				if (update_screen(sdl, (int *)event.user.data1) != 0)
					return ;
			sdl->runtime = SDL_GetTicks64() - sdl->frame_start;
			if (sdl->runtime < FRAME)
				SDL_Delay(FRAME - sdl->runtime);
		}
	}
	SDL_RemoveTimer(timer_id);
}
