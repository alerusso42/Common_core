/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:40:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/27 16:52:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static int		init_textures(t_data *data);
static int		init_music(t_data *data);
static int		init_sound(t_data *data);

int	init_all(t_data *data)
{
	if (daft_init() != 0)
		return (error(data, ER_DAFT));
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (error(data, ER_SDL));
	data->sdl.win = SDL_CreateWindow(WIN_NAME, WIN_X, WIN_Y, WIN_W, WIN_H, 0);
	if (!data->sdl.win)
		return (error(data, ER_SDL));
	data->sdl.render = SDL_CreateRenderer(data->sdl.win, -1, SDL_RENDERER_SOFTWARE);
	if (!data->sdl.render)
		return (error(data, ER_SDL));
	daft_swap(MEDIA_LIST);
	if (init_textures(data) != 0)
		return (data->last_error);
	if (init_music(data) != 0)
		return (data->last_error);
	if (init_sound(data) != 0)
		return (data->last_error);
	if (get_map(data, RANDOM) != 0)
		return (data->last_error);
	return (0);
}

static int	init_textures(t_data *data)
{
	char	**files;
	int		i;

	files = daft_get("textures");
	if (!files)
		return (error(data, ER_DAFT));
	i = 0;
	while (files[i])
	{
		printf("|%s|\n", files[i]);
		data->sdl.texture[i] = IMG_LoadTexture(data->sdl.render, files[i]);
		if (!data->sdl.texture[i])
			return (error(data, ER_SDL));
		++i;
	}
	return (0);
}

static int	init_music(t_data *data)
{
	char	**files;
	int		i;

	if (Mix_OpenAudio(48000, AUDIO_S16SYS, 2, 2048) != 0)
		return (error(data, ER_SDL));
	files = daft_get("mus");
	if (!files)
		return (error(data, ER_DAFT));
	i = 0;
	while (files[i])
	{
		printf("|%s|\n", files[i]);
		data->sdl.mus[i] = Mix_LoadMUS(files[i]);
		if (!data->sdl.mus[i])
			return (error(data, ER_SDL));
		++i;
	}
	return (0);
}

static int	init_sound(t_data *data)
{
	char	**files;
	int		i;

	files = daft_get("sound");
	if (!files)
		return (error(data, ER_DAFT));
	i = 0;
	while (files[i])
	{
		printf("|%s|\n", files[i]);
		data->sdl.sound[i] = Mix_LoadWAV(files[i]);
		if (!data->sdl.sound[i])
			return (error(data, ER_SDL));
		++i;
	}
	return (0);
}
