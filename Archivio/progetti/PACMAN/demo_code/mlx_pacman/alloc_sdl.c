/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_sdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:06:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:56:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

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
	sdl.win = SDL_CreateWindow("SDL3 exercise", X, Y, W, H, 0);
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



