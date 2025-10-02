/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   android_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:44:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 02:57:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

void	android_player_move(t_data *data)
{
	int32_t	coord[2];

	if (!data->android.is_android)
		return ;
	if (elapsed_time(data->player.move.last) < data->player.move.interval)
		return ;
	coord[X] = data->player.pos[X];
	coord[Y] = data->player.pos[Y];
	move_to_random(data->player.input, coord);
	move(data, &data->player, coord[X], coord[Y]);
}
