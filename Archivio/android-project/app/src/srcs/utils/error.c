/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:23:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 00:10:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	print_error(t_data *data, int type);
static int	print_error_map(t_data *data, int type);

int	error(t_data *data, int type)
{
	data->last_error = type;
	print_error(data, type);
	free_all(data);
	return (type);
}

static void	print_error(t_data *data, int type)
{
	if (type == ER_OK)
		err("No errors.\n");
	else if (type == ER_MALLOC)
		err("Allocation error.\n");
	else if (type == ER_OPEN)
		err("Critical open error.\n");
	else if (type == ER_SDL)
	{
		err("SDL error.\n");
		err(SDL_GetError());
	}
	else if (type == ER_DAFT)
		err("Daft error.\n");
	else if (print_error_map(data, type) == 1)
		err("Unknown error.\n");
}

static int	print_error_map(t_data *data, int type)
{
	if (type == ER_MAP_ID)
		err("Map:\tSomething weird happened with map id.\n");
	else if (type == ER_MAP_EXTENSION)
			err("Map:\tMap extension must be .ber.\n");
	else if (type == ER_MAP_BIG)
		err("Map:\ttoo big.\n");
	else if (type == ER_MAP_LITTLE)
			err("Map:\ttoo little.\n");
	else if (type == ER_MAP_EXIT)
		err("Map:\tNo exit in map.\n");
	else if (type == ER_MAP_PLAYER)
			err("Map:\tbad number of player.\n");
	else if (type == ER_MAP_FLOODFILL)
		err("Map:\tnot all map can be accessed.\n");
	else
		return (1);
	return (0);
}
