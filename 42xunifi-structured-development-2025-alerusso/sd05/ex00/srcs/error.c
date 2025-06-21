/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:59:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 23:44:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	error(t_data *data, int err_type)
{
	fd_printf(2, "Error %d\n");
	free_memory(data);
	exit(err_type);
}

int	delete_warning(t_data *data, char *line)
{
	if (data->del_warning == false)
	{
		data->del_warning = true;
		fd_printf(2, "\033[33m⚠Warning⚠\033[0m\nSome entries were invalid.\n");
		fd_printf(2, "Please open "ERROR_FILE" to see ");
		fd_printf(2, "what entries were deleted.\n");
	}
	if (!data->error_file)
		data->error_file = open(ERROR_FILE, P_APPEND, 0777);
	if (!data->error_file)
		return (1);
	fd_printf(data->error_file, line);
	return (0);
}
