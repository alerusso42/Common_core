/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:27:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/24 18:47:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	free_all(t_data *data)
{
	if (data->sdl.win)
		SDL_DestroyWindow(data->sdl.win);
	if (data->sdl.render)
		SDL_DestroyRenderer(data->sdl.render);
	SDL_Quit();
	daft_quit();
	del_filedata();
}