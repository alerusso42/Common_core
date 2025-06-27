/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggered.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:05:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/27 15:13:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static int	x_eye_contact(t_map *map, int en_x, int en_y);
static int	y_eye_contact(t_map *map, int en_x, int en_y);

/*
	$111		How enemies see and triggers
	--00
	0--P
	0000

	-	Enemies search using the delta value (difference with abs)
		between enemies and player.
	-	If delta_x > delta_y, they search before in the x axis.
	-	Opposite if delta_x are equal to delta_y.
	-	If are equal, I do both.
	
	-	As shown up, Their vision moves oblique until they are on
		the same x/y of the player.
	-	Then, they just search toward player until they find it.
*/
int	triggered(t_all *all, int en_x, int en_y)
{
	int	delta_x;
	int	delta_y;

	delta_x = all->map->p_x - en_x;
	delta_y = all->map->p_y - en_y;
	if (ft_abs(delta_x) > ft_abs(delta_y))
	{
		if (x_eye_contact(all->map, en_x, en_y) == YES)
			return (YES);
	}
	else if (ft_abs(delta_x) < ft_abs(delta_y))
	{
		if (y_eye_contact(all->map, en_x, en_y) == YES)
			return (YES);
	}
	else
	{
		if ((x_eye_contact(all->map, en_x, en_y) == YES) || \
		(y_eye_contact(all->map, en_x, en_y) == YES))
			return (YES);
	}
	return (NO);
}

static int	eye(char value)
{
	if (value == 'E')
		return (YES);
	if (value == '$')
		return (YES);
	if (value == '1')
		return (YES);
	return (NO);
}

static int	x_eye_contact(t_map *map, int en_x, int en_y)
{
	if (en_x > map->p_x)
		en_x--;
	else if (en_x < map->p_x)
		en_x++;
	while ("I loop until I find the player or anything else")
	{
		if (en_x > map->p_x)
			en_x--;
		if (eye(map->position[en_x][en_y].value) == YES)
			return (NO);
		if (en_y > map->p_y)
			en_y--;
		if (eye(map->position[en_x][en_y].value) == YES)
			return (NO);
		if (en_x < map->p_x)
			en_x++;
		if (eye(map->position[en_x][en_y].value) == YES)
			return (NO);
		if (en_y < map->p_y)
			en_y++;
		if (eye(map->position[en_x][en_y].value) == YES)
			return (NO);
		if (map->position[en_x][en_y].value == 'P')
			return (YES);
	}
}

static int	y_eye_contact(t_map *map, int en_x, int en_y)
{
	if (en_y > map->p_y)
		en_y--;
	else if (en_y < map->p_y)
		en_y++;
	while ("I loop until I find the player or anything else")
	{
		if (en_y > map->p_y)
			en_y--;
		if (eye(map->position[en_x][en_y].value) == YES)
			return (NO);
		if (en_x > map->p_x)
			en_x--;
		if (eye(map->position[en_x][en_y].value) == YES)
			return (NO);
		if (en_y < map->p_y)
			en_y++;
		if (eye(map->position[en_x][en_y].value) == YES)
			return (NO);
		if (en_x < map->p_x)
			en_x++;
		if (eye(map->position[en_x][en_y].value) == YES)
			return (NO);
		if (map->position[en_x][en_y].value == 'P')
			return (YES);
	}
}
