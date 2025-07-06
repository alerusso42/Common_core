/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:40:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/06 17:16:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static int		init_render(t_data *data);
static int		init_textures(t_data *data);
static int		init_music(t_data *data);
static int		init_sound(t_data *data);

int	init_all(t_data *data)
{
	if (daft_init() != 0)
		return (error(data, ER_DAFT));
	if (SDL_Init(SDL_INIT_MASK) != 0)
		return (error(data, ER_SDL));
	data->sdl.win = SDL_CreateWindow(WIN_NAME, WIN_X, WIN_Y, WIN_W, WIN_H, WIN_FLAGS);
	if (!data->sdl.win)
		return (error(data, ER_SDL));
	if (init_render(data) != 0)
		return (data->last_error);
	daft_swap(MEDIA_LIST);
	if (init_textures(data) != 0)
		return (data->last_error);
	if (init_music(data) != 0)
		return (data->last_error);
	if (init_sound(data) != 0)
		return (data->last_error);
	if (get_map(data, RANDOM) != 0)
		return (data->last_error);
	set_player(data);
	set_enemies(data);
	set_exit(data);
	return (0);
}

int		init_render(t_data *data)
{
	data->sdl.render = SDL_CreateRenderer(data->sdl.win, -1, SDL_RENDERER_SOFTWARE);
	if (!data->sdl.render)
		return (error(data, ER_SDL));
	SDL_SetRenderDrawColor(data->sdl.render, 0, 0, 0, 255);
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
		if (DEBUG == true)
			printf("|%s|\n", files[i]);
		data->sdl.texture[i] = IMG_LoadTexture(data->sdl.render, files[i]);
		if (!data->sdl.texture[i])
			return (error(data, ER_SDL));
		++i;
	}
	data->sdl.rect.w = SPRITE_SIZE;
	data->sdl.rect.h = SPRITE_SIZE;
	return (0);
}

static int	init_music(t_data *data)
{
	char	**files;
	int		i;

	//NOTE usare il driver dsp
	if (Mix_OpenAudio(44100, AUDIO_S16, 1, 5000) != 0)
		return (error(data, ER_SDL));
	files = daft_get("mus");
	if (!files)
		return (error(data, ER_DAFT));
	i = 0;
	while (files[i])
	{
		if (DEBUG == true)
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
		if (DEBUG == true)
			printf("|%s|\n", files[i]);
		data->sdl.sound[i] = Mix_LoadWAV(files[i]);
		if (!data->sdl.sound[i])
			return (error(data, ER_SDL));
		++i;
	}
	return (0);
}
