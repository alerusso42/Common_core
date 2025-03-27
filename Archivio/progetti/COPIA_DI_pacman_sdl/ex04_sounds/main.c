/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:56:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/15 15:52:30 by alerusso         ###   ########.fr       */
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
	int			frame_start;

	screen_animations((t_sdl *)param, animator);
	++animator;
	usleep(1800);
	return (interval);
}

void	get_commands(SDL_Event *event, t_sdl *sdl);

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
	int			frame_start;
	int			last_tick;
	const int timer_interval = 150;
	int			now;
	SDL_Event	event;

	sdl->run = 1;
	Mix_PlayMusic(sdl->mix.music, -1);
	Mix_PlayChannel(-1, sdl->mix.sound[0], 1);
	last_tick = SDL_GetTicks();
	while (sdl->run)
	{
		frame_start = SDL_GetTicks();
		get_commands(&event, sdl);
		now = SDL_GetTicks();
		if (now - last_tick >= timer_interval)
		{
			sdl->curr_img = dialga(now / timer_interval);
			update_screen(sdl, &sdl->curr_img);
			last_tick += timer_interval;
		}
	}
}

void	get_commands(SDL_Event *event, t_sdl *sdl)
{
	while (SDL_PollEvent(event))
	{
		if ((event->type == SDL_QUIT) ||
			(event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE))
			sdl->run = 0;
		else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == 'z')
			Mix_PlayChannel(-1, sdl->mix.sound[1], 0);
		else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == 'x')
			Mix_PlayChannel(-1, sdl->mix.sound[2], 0);
		else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == 'c')
			Mix_PlayChannel(-1, sdl->mix.sound[3], 0);
		else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == 'v')
			Mix_PlayChannel(-1, sdl->mix.sound[4], 0);
		else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == 'b')
			Mix_PlayChannel(-1, sdl->mix.sound[5], 0);
	}
}
