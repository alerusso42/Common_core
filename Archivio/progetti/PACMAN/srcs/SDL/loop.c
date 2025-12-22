/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:31:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/22 22:07:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	init_loop(t_data *data);

void	game_loop(t_data *data)
{
	uint64_t	start_time;
	uint64_t	update_time;

	init_loop(data);
	while (data->run == true)
	{
		map_render(data, false);
		animations(data);
		move_enemies(data);
		//print_map(data->map, data->old_map);
		//print_bfs(data->map, 0);
		SDL_RenderPresent(data->sdl.render);
		start_time = SDL_GetTicks();
		events(data);
		update_time = SDL_GetTicks() - start_time;
		if (update_time < FRAME_TIME)
			SDL_Delay(FRAME_TIME - (uint32_t)(update_time));
	}
}

void	init_loop(t_data *data)
{
	data->run = true;
	init_enemies_animation(data);
	map_render(data, true);
	animations(data);
	SDL_RenderPresent(data->sdl.render);
	SDL_Delay(10);
	Mix_PlayChannel(1, data->sdl.sound[SO_PACMAN_BEGINNING], 0);
	Mix_ChannelFinished(set_sound_ending);
	//wait_sound_ending(data);
	Mix_PlayMusic(data->sdl.mus[MUS_MAIN], 0);
}
