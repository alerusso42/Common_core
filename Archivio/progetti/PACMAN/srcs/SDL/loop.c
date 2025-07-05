/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:31:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 12:17:56 by alerusso         ###   ########.fr       */
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
	while (data->run == true)
	{
		map_render(data, first_rendering);
		animations(data);
		move_enemies(data);
		//print_map(data->map, data->old_map);
		SDL_RenderPresent(data->sdl.render);
		first_rendering = false;
		start_time = SDL_GetTicks64();
		events(data);
		update_time = SDL_GetTicks64() - start_time;
		if (update_time < FRAME_TIME)
			SDL_Delay(FRAME_TIME - (uint32_t)(update_time));
	}
}
