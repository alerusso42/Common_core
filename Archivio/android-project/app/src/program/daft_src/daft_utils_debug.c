/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:49:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 00:03:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static void	daft_printerror(int log, t_fd fd);
static void	android_print(int log);

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
	daft_printerror(log, log_file);
	android_print(log);
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

#include <android/log.h>

void	logg(char *s)
{
	static int	c;

	if (s)
		__android_log_print(ANDROID_LOG_ERROR, "DAFT", "Log %d:\t%s\n", c, s);
	else
		__android_log_print(ANDROID_LOG_ERROR, "DAFT", "Log %d\n", c);
	++c;
}

static void	android_print(int log)
{
	if (log == DAFT_LOG_ALLOCSIZE)
		logg("Missing or invalid allocsize in hash_data.\n");
	else if (log == DAFT_LOG_ATOI)
		logg("Invalid integer in SETTINGS.md file.\n");
	else if (log == DAFT_LOG_MALLOC)
		logg("Malloc failure.\n");
	else if (log == DAFT_LOG_MISSFLAGS)
		logg("Inner flags of a file are missing.\n");
	else if (log == DAFT_LOG_OPEN)
		logg("Open has failed.\n");
	else if (log == DAFT_LOG_SETT)
		logg("Missing SETTINGS.md file.\n");
	else if (log == DAFT_LOG_FILESETT)
		logg("Missing hash_data file.\n");
	else if (log == DAFT_LOG_NOMEM)
		logg("Called a function without calling daft_init().\n");
	else if (log == DAFT_LOG_KEYUSED)
		logg("Selected key has already been used.\n");
}
