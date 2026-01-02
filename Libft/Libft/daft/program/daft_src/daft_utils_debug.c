/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:49:21 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/02 12:44:13 by alerusso         ###   ########.fr       */
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
		return (daft_printerror(log, (t_fd){2, 2}), log);
	if (log > DAFT_ERRORS)
		data->last_error = log;
	if (data->conf.debug_log == false)
		return (log);
	if (data->conf.log_path)
		log_file = openfd("daft.log", "a+");
	else
		log_file = (t_fd){2, 2};
	if (!log_file.n)
		return (log);
	daft_printerror(log, log_file);
	closefd(log_file);
	return (log);
}

static void	daft_printerror(int log, t_fd fd)
{
	fd_printf(fd, "\033[31mDaft log: \033[0m");
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
	else if (log == DAFT_LOG_USAGE)
		fd_printf(fd, "invalid use of daft_init. Correct use:\n \
if (daft_init(data_path, setting_filename) != 0)\n\treturn (EXIT_FAILURE);\n");
}
