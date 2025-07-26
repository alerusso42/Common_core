/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:23:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 18:07:53 by alerusso         ###   ########.fr       */
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
	if (!data->debug_file.n)
		data->debug_file = openfd(ERROR_FILE, "w+");
	if (data->debug_file.n)
		fd_printf(data->debug_file, "#------#\n");
	if (type == ER_OK)
		fd_printf(data->debug_file, "No errors.\n");
	else if (type == ER_MALLOC)
		fd_printf(data->debug_file, "Allocation error.\n");
	else if (type == ER_OPEN)
		fd_printf(data->debug_file, "Critical open error.\n");
	else if (type == ER_SDL)
	{
		fd_printf(data->debug_file, "SDL error.\n");
		fd_printf(data->debug_file, SDL_GetError());
	}
	else if (type == ER_DAFT)
		fd_printf(data->debug_file, "Daft error.\n");
	else if (print_error_map(data, type) == 1)
		fd_printf(data->debug_file, "Unknown error.\n");
}

static int	print_error_map(t_data *data, int type)
{
	if (type == ER_MAP_ID)
		fd_printf(data->debug_file, "Map:\tSomething weird happened with map id.\n");
	else if (type == ER_MAP_EXTENSION)
			fd_printf(data->debug_file, "Map:\tMap extension must be .ber.\n");
	else if (type == ER_MAP_BIG)
		fd_printf(data->debug_file, "Map:\ttoo big.\n");
	else if (type == ER_MAP_LITTLE)
			fd_printf(data->debug_file, "Map:\ttoo little.\n");
	else if (type == ER_MAP_EXIT)
		fd_printf(data->debug_file, "Map:\tNo exit in map.\n");
	else if (type == ER_MAP_PLAYER)
			fd_printf(data->debug_file, "Map:\tbad number of player.\n");
	else if (type == ER_MAP_FLOODFILL)
		fd_printf(data->debug_file, "Map:\tnot all map can be accessed.\n");
	else
		return (1);
	return (0);
}
