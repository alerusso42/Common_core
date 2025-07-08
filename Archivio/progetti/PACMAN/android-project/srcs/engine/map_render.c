/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:37:13 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 12:25:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	render(t_data *data, char entity, int x, int y);

void	map_render(t_data *data, bool first_rend)
{
	int	y;
	int	x;

	y = 0;
	while (y != data->game.map_size[Y] + 1)
	{
		x = 0;
		while (x != data->game.map_size[X] + 1)
		{
			if (first_rend || data->map[y][x].val != data->old_map[y][x].val)
			{
				render(data, data->map[y][x].val, x, y);
				data->old_map[y][x].val = data->map[y][x].val;
			}
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
	else if (entity == S_EXIT && data->exit.triggered == false)
		i = TEX_CLOSE_EXIT;
	else
		return ;
	data->sdl.rect.x = x * SPRITE_SIZE;
	data->sdl.rect.y = y * SPRITE_SIZE;
	SDL_RenderCopy(data->sdl.render, data->sdl.texture[i], NULL, &data->sdl.rect);
}
