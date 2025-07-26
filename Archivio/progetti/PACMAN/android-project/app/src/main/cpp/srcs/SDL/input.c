/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:34:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/13 14:20:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	keyboard(t_data *data, SDL_Keycode key);
static void	window(t_data *data, SDL_WindowEvent *event);

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
