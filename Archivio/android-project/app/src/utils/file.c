/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:39:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/09 11:11:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/include/header.h"

static SDL_Texture	*init_one(t_data *data, char *filename);

int		init_txtr(t_data *data)
{
	SDL_Surface	*surface;

	data->txtr[TXTR_NUM] = NULL;
	data->txtr[TXTR_BOX] = init_one(data, "textures/box.bmp");
	data->txtr[TXTR_CURSOR] = init_one(data, "textures/cursor.bmp");
	for (int i = 0; i != TXTR_NUM; i++)
	{
		if (!data->txtr[i])
			return (1);
	}
	return (0);
}

static SDL_Texture	*init_one(t_data *data, char *filename)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = SDL_LoadBMP(filename);
	if (!surface)
		return (NULL);
	texture = SDL_CreateTextureFromSurface(data->rend, surface);
	SDL_FreeSurface(surface);
	return (texture);
}

void	free_txtr(t_data *data)
{
	for (int i = 0; i != TXTR_NUM; i++)
	{
		SDL_DestroyTexture(data->txtr[i]);
	}
}
