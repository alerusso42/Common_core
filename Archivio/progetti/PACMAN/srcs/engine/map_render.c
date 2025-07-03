/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:37:13 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/03 17:57:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	render(t_data *data, char entity, int x, int y);

void	map_render(t_data *data, bool first_rend)
{
	int	y;
	int	x;

	//SDL_RenderClear(data->sdl.render);
	y = 0;
	while (y != data->game.map_size[Y] + 1)
	{
		x = 0;
		while (x != data->game.map_size[X] + 1)
		{
			if (first_rend || data->map[y][x].val != data->old_map[y][x].val)
				render(data, data->map[y][x].val, x, y);
			x++;
		}
		y++;
	}
}

static void	render(t_data *data, char entity, int x, int y)
{
	int	i;

	i = 0;
	if (entity == S_COL)
		i = TEX_DOT;
	else if (entity == S_HARD_WALL || entity == S_WALL)
		i = TEX_WALL_TOTAL;
	else if (entity == S_FLOOR)
		i = TEX_FLOOR;
	else if (entity == S_EXIT)
		i = TEX_CLOSE_EXIT;
	data->sdl.rect.x = x * SPRITE_SIZE;
	data->sdl.rect.y = y * SPRITE_SIZE;
	SDL_RenderCopy(data->sdl.render, data->sdl.texture[i], NULL, &data->sdl.rect);
}
