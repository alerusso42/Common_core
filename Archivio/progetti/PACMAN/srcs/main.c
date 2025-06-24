/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:03:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/25 01:19:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

int	main()
{
	t_data	data;

	data = (t_data){0};
	if (init_all(&data) != 0)
		return (data.last_error);
	Mix_PlayMusic(data.sdl.mus[FEELING_RESOLUTE], 1);
	Mix_PlayChannel(-1, data.sdl.sound[PACMAN_EATFRUIT], 1);
	SDL_Delay(10000);
	free_all(&data);
	return (0);
}
