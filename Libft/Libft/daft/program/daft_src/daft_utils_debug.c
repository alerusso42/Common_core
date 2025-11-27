/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:49:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 17:35:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static void	daft_printerror(int log, t_fd fd);

int	_daft_log(int log)
{
	t_daft_data	*data;
	t_fd		log_file;

	data = _daft_get_memory(NULL, false);
	if (!data)
		return (log);
	if (log > DAFT_ERRORS)
		data->last_error = log;
	if (data->conf.debug_log == false)
		return (log);
	log_file = openfd("daft.log", "a+");
	if (!log_file.n)
		return (log);
	daft_printerror(log, (t_fd){2, 2});
	closefd(log_file);
	return (log);
}

static void	daft_printerror(int log, t_fd fd)
{
	if (log == DAFT_LOG_ALLOCSIZE)
		fd_printf(fd, "Missing or invalid allocsize in hash_data.\n");
	else if (log == DAFT_LOG_ATOI)
		fd_printf(fd, "Invalid integer in SETTINGS.md file.\n");
	else if (log == DAFT_LOG_MALLOC)
		fd_printf(fd, "Malloc failure.\n");
	else if (log == DAFT_LOG_MISSFLAGS)
		fd_printf(fd, "Inner flags of a file are missing.\n");
	else if (log == DAFT_LOG_OPEN)
		fd_printf(fd, "Open has failed.\n");
	else if (log == DAFT_LOG_SETT)
		fd_printf(fd, "Missing SETTINGS.md file.\n");
	else if (log == DAFT_LOG_FILESETT)
		fd_printf(fd, "Missing hash_data file.\n");
	else if (log == DAFT_LOG_NOMEM)
		fd_printf(fd, "Called a function without calling daft_init().\n");
	else if (log == DAFT_LOG_KEYUSED)
		fd_printf(fd, "Selected key has already been used.\n");
}
