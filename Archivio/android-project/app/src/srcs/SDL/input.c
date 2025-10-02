/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:34:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 03:11:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	keyboard(t_data *data, SDL_Keycode key);
static void	window(t_data *data, SDL_WindowEvent *event);
static void	finger(t_data *data, SDL_TouchFingerEvent *event);

void	events(t_data *data)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || \
			(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			data->run = false;
		else if (event.type == SDL_KEYDOWN)
			keyboard(data, event.key.keysym.sym);
		else if (event.type == SDL_WINDOWEVENT)
			window(data, &event.window);
		else if (event.type == SDL_FINGERDOWN || event.type == SDL_FINGERMOTION)
			finger(data, &event.tfinger);
		else if (event.type == SDL_FINGERUP)
			data->android.finger_init = false;
	}
}

static void	keyboard(t_data *data, SDL_Keycode key)
{
	if (key == SDLK_w || key == SDLK_UP)
		move(data, &data->player, data->player.pos[X], data->player.pos[Y] - 1);
	else if (key == SDLK_s || key == SDLK_DOWN)
		move(data, &data->player, data->player.pos[X], data->player.pos[Y] + 1);
	else if (key == SDLK_a || key == SDLK_LEFT)
		move(data, &data->player, data->player.pos[X] - 1, data->player.pos[Y]);
	else if (key == SDLK_d || key == SDLK_RIGHT)
		move(data, &data->player, data->player.pos[X] + 1, data->player.pos[Y]);
}

static void	window(t_data *data, SDL_WindowEvent *event)
{
	if (event->event == SDL_WINDOWEVENT_RESIZED)
	{
		SDL_SetWindowSize(data->sdl.win, event->data1, event->data2);
		reset_map(data->old_map);
		animations(data);
	}
}

static void	finger(t_data *data, SDL_TouchFingerEvent *event)
{
	float	delta[2];
	static int	test;

	++test;
	if (!data->android.finger_init)
	{
		data->android.is_android = true;
		data->android.finger_init = true;
		data->android.finger[X] = event->x;
		data->android.finger[Y] = event->y;
		return ;
	}
	if (!(test % 3))
		return ;
	delta[X] = event->x - data->android.finger[X];
	delta[Y] = event->y - data->android.finger[Y];
	data->android.finger[X] = event->x;
	data->android.finger[Y] = event->y;
	if (fabsf(delta[X]) > fabsf(delta[Y]))
	{
		if (delta[X] > 0)
			data->player.input = RIGHT;
		else
			data->player.input = LEFT;
		return ;
	}
	if (delta[Y] > 0)
		data->player.input = DOWN;
	else
		data->player.input = UP;
}
