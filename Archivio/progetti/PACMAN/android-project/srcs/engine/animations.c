/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:59:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 16:47:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static int	which_text(t_entity *entity);

void	animations(t_data *data)
{
	int			i;
	t_entity	*enemy;

	if (elapsed_time(data->player.anim.last) >= data->player.anim.interval)
		animate_one(data, &data->player);
	if (data->exit.triggered == false && data->game.collectables == 0)
	{
		data->exit.frame = 1;
		data->exit.triggered = true;
		animate_one(data, &data->exit);
	}
	enemy = data->enemy;
	i = 0;
	while (enemy[i].type != EN_LAST)
	{
		if (elapsed_time(enemy[i].anim.last) >= enemy[i].anim.interval)
			animate_one(data, &enemy[i]);
		i++;
	}
}

void	animate_one(t_data *data, t_entity *entity)
{
	int	i;

	data->sdl.rect.x = entity->pos[X] * SPRITE_SIZE;
	data->sdl.rect.y = entity->pos[Y] * SPRITE_SIZE;
	i = which_text(entity);
	SDL_RenderCopy(data->sdl.render, data->sdl.texture[i], NULL, &data->sdl.rect);
	if (entity->frame == entity->last_frame)
		entity->frame = 0;
	else
		entity->frame += 1; 
	entity->anim.last = SDL_GetTicks64();
}

static int		which_text(t_entity *entity)
{
	int	texture;

	texture = TEX_PAC_DEAD_3;
	if (entity->type == PLAYER && entity->frame == 0)
		texture = TEX_PAC_OPEN_DOWN + entity->dir;
	else if (entity->type == PLAYER && entity->frame == 1)
		texture = TEX_PAC_HALF_DOWN + entity->dir;
	else if (entity->type == PLAYER && entity->frame == 2)
		texture = TEX_PAC_CLOSE_DOWN + entity->dir;
	else if (entity->type == PLAYER && entity->frame == 3)
		texture = TEX_PAC_HALF_DOWN + entity->dir;
	else if (entity->type == EN_CIAN)
		texture = TEX_CIAN_DOWN + entity->dir;
	else if (entity->type == EN_ORANGE)
		texture = TEX_ORANGE_DOWN + entity->dir;
	else if (entity->type == EN_PURPLE)
		texture = TEX_PURPLE_DOWN + entity->dir;
	else if (entity->type == EN_RED)
		texture = TEX_RED_DOWN + entity->dir;
	else if (entity->type == EN_EXIT)
		texture = TEX_EXIT;
	return (texture);
}

void	init_enemies_animation(t_data *data)
{
	int			i;
	t_entity	*enemy;

	enemy = data->enemy;
	i = 0;
	while (enemy[i].type != EN_LAST)
	{
		animate_one(data, &enemy[i]);
		i++;
	}
}
