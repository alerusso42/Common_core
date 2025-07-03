/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:31:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/03 17:58:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	events(t_data *data);

void	game_loop(t_data *data)
{
	uint64_t	start_time;
	uint64_t	update_time;
	bool		first_rendering;

	data->run = true;
	first_rendering = true;
	while (data->run == true)
	{
		map_render(data, first_rendering);
		animations(data);
		SDL_RenderPresent(data->sdl.render);
		first_rendering = false;
		start_time = SDL_GetTicks64();
		events(data);
		update_time = SDL_GetTicks64() - start_time;
		if (update_time < FRAME_TIME)
			SDL_Delay(FRAME_TIME - (uint32_t)(update_time));
	}
}

static void	events(t_data *data)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || \
			(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			data->run = false;
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w)
			move(data, &data->player, data->player.pos[X], data->player.pos[Y] - 1);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s)
			move(data, &data->player, data->player.pos[X], data->player.pos[Y] + 1);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a)
			move(data, &data->player, data->player.pos[X] - 1, data->player.pos[Y]);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d)
			move(data, &data->player, data->player.pos[X] + 1, data->player.pos[Y]);
	}
}
