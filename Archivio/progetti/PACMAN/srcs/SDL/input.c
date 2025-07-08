/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:34:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 18:14:43 by alerusso         ###   ########.fr       */
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
		if (event.type == SDL_EVENT_QUIT || \
			(event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE))
			data->run = false;
		else if (event.type == SDL_EVENT_KEY_DOWN)
			keyboard(data, event.key.key);
		else
			window(data, &event.window);
	}
}

static void	keyboard(t_data *data, SDL_Keycode key)
{
	if (key == SDLK_W || key == SDLK_UP)
		move(data, &data->player, data->player.pos[X], data->player.pos[Y] - 1);
	else if (key == SDLK_S || key == SDLK_DOWN)
		move(data, &data->player, data->player.pos[X], data->player.pos[Y] + 1);
	else if (key == SDLK_A || key == SDLK_LEFT)
		move(data, &data->player, data->player.pos[X] - 1, data->player.pos[Y]);
	else if (key == SDLK_D || key == SDLK_RIGHT)
		move(data, &data->player, data->player.pos[X] + 1, data->player.pos[Y]);
}

static void	window(t_data *data, SDL_WindowEvent *event)
{
	if (event->type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED)
	{
		SDL_SetWindowSize(data->sdl.win, event->data1, event->data2);
		reset_map(data->old_map);
		animations(data);
	}
}
