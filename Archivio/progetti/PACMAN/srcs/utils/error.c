/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:23:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/24 18:27:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

static void	print_error(t_data *data, int type);

int	error(t_data *data, int type)
{
	data->last_error = type;
	print_error(data, type);
	free_all(data);
	return (type);
}

static void	print_error(t_data *data, int type)
{
	char	errstr[255];

	if (!data->debug_file.n)
		data->debug_file = openfd(ERROR_FILE, "w+");
	if (data->debug_file.n)
		fd_printf(data->debug_file, ctime(0));
	if (type == ER_OK)
		fd_printf(data->debug_file, "No errors.\n");
	else if (type == ER_MALLOC)
		fd_printf(data->debug_file, "Allocation error.\n");
	else if (type == ER_OPEN)
		fd_printf(data->debug_file, "Critical open error.\n");
	else if (type == ER_SDL)
	{
		fd_printf(data->debug_file, "SDL error.\n");
		fd_printf(data->debug_file, SDL_GetErrorMsg(errstr, 255));
	}
	else if (type == ER_DAFT)
		fd_printf(data->debug_file, "Daft error.\n");
	else
		fd_printf(data->debug_file, "Unknown error.\n");
}