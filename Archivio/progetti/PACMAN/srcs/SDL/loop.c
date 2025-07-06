/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:31:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/06 16:50:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	game_loop(t_data *data)
{
	uint64_t	start_time;
	uint64_t	update_time;
	bool		first_rendering;

	data->run = true;
	first_rendering = true;
	init_enemies_animation(data);
	Mix_PlayMusic(data->sdl.mus[MUS_MAIN], 0);
	while (data->run == true)
	{
		map_render(data, first_rendering);
		animations(data);
		move_enemies(data);
		//print_map(data->map, data->old_map);
		print_bfs(data->map, 0);
		SDL_RenderPresent(data->sdl.render);
		first_rendering = false;
		start_time = SDL_GetTicks64();
		events(data);
		update_time = SDL_GetTicks64() - start_time;
		if (update_time < FRAME_TIME)
			SDL_Delay(FRAME_TIME - (uint32_t)(update_time));
	}
}
