/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggered.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:05:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/06 02:06:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static int	x_eye_contact(t_map **map, t_entity *player, int en_x, int en_y);
static int	y_eye_contact(t_map **map, t_entity *player, int en_x, int en_y);

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
int	triggered(t_data *data, int en_x, int en_y)
{
	int	delta_x;
	int	delta_y;

	delta_x = data->player.pos[X] - en_x;
	delta_y = data->player.pos[Y] - en_y;
	if (abs(delta_x) > abs(delta_y))
	{
		if (x_eye_contact(data->map, &data->player, en_x, en_y) == true)
			return (true);
	}
	else if (abs(delta_x) < abs(delta_y))
	{
		if (y_eye_contact(data->map, &data->player, en_x, en_y) == true)
			return (true);
	}
	else
	{
		if ((x_eye_contact(data->map, &data->player, en_x, en_y) == true) || \
		(y_eye_contact(data->map, &data->player, en_x, en_y) == true))
			return (true);
	}	return (false);
}

static int	eye(char value)
{
	if (value == S_EXIT)
		return (true);
	if (value == S_ENEMY)
		return (true);
	if (value == S_WALL || value == S_HARD_WALL)
		return (true);
	return (false);
}

static int	x_eye_contact(t_map **map, t_entity *player, int en_x, int en_y)
{
	if (en_x > player->pos[X])
		en_x--;
	else if (en_x < player->pos[X])
		en_x++;
	while ("I loop until I find the player or anything else")
	{
		if (en_x > player->pos[X])
			en_x--;
		if (eye(map[en_y][en_x].val) == true)
			return (false);
		if (en_y > player->pos[Y])
			en_y--;
		if (eye(map[en_y][en_x].val) == true)
			return (false);
		if (en_x < player->pos[X])
			en_x++;
		if (eye(map[en_y][en_x].val) == true)
			return (false);
		if (en_y < player->pos[Y])
			en_y++;
		if (eye(map[en_y][en_x].val) == true)
			return (false);
		if (map[en_y][en_x].val == S_PLAYER)
			return (true);
	}
}

static int	y_eye_contact(t_map **map, t_entity *player, int en_x, int en_y)
{
	if (en_y > player->pos[Y])
		en_y--;
	else if (en_y < player->pos[Y])
		en_y++;
	while ("I loop until I find the player or anything else")
	{
		if (en_y > player->pos[Y])
			en_y--;
		if (eye(map[en_y][en_x].val) == true)
			return (false);
		if (en_x > player->pos[X])
			en_x--;
		if (eye(map[en_y][en_x].val) == true)
			return (false);
		if (en_y < player->pos[Y])
			en_y++;
		if (eye(map[en_y][en_x].val) == true)
			return (false);
		if (en_x < player->pos[X])
			en_x++;
		if (eye(map[en_y][en_x].val) == true)
			return (false);
		if (map[en_y][en_x].val == S_PLAYER)
			return (true);
	}
}
