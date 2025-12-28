/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:36:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 22:32:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static int	get_settings_file(t_daft_data *data);
static int	get_database_file(t_daft_data *data);

/*
//REVIEW -	daft_get
//
	Initialize daft memory.
	Returns 0 on success.
	On failure, creates a log file named daft_log, 
	writing on it the issue, and returns an integer
	different than 0, based on a enum called e_daft_logs.
*/
int 	daft_init(void)
{
	t_daft_data	*data;

	if (_daft_get_memory(NULL, false))
		return (0);
	data = ft_calloc(1, sizeof(t_daft_data));
	if (!data)
		return (DAFT_LOG_MALLOC);
	data->mem_size = -1;
	data->minimal_matrix_num = 1;
	_daft_get_memory(data, true);
	if (get_settings_file(data) != 0)
		return (daft_quit(), data->last_error);
	if (get_database_file(data) != 0)
		return (daft_quit(), data->last_error);
	return (0);
}

//	DAFT_PWD is updated upon launching the update script.
//	All setting file is read, searching for the two section of
//	settings.
static int	get_settings_file(t_daft_data *data)
{
	char	*line;
	t_fd	settings_file;

	settings_file = openfd(DAFT_PWD"/SETTINGS.md", "r");
	if (!settings_file.n)
		return (_daft_log(DAFT_LOG_SETT));
	line = gnl();
	while (line)
	{
		if (!ft_strncmp(line, "#SECTION - General settings", 27))
		{
			if (_daft_save_config(data) == DAFT_LOG_MALLOC)
				closefd(settings_file);
		}
		else if (!ft_strncmp(line, "#SECTION - Files flags", 22))
		{
			if (_daft_save_fnames(data) == DAFT_LOG_MALLOC)
				closefd(settings_file);
		}
		FREE(line);
		line = gnl();
	}
	return (closefd(settings_file), 0);
}

//	For every file, a dedicated struct is allocated.
//	The struct stores its inner flags, its filename, 
static int	get_database_file(t_daft_data *data)
{
	int	i;

	data->data_list = ft_calloc(data->files_num + 1, sizeof(t_daft_list *));
	if (!data->data_list)
		return (_daft_log(DAFT_LOG_MALLOC));
	i = 0;
	while (i != data->files_num)
	{
		data->data_list[i] = ft_calloc(1, sizeof(t_daft_list));
		if (!data->data_list[i])
			return (_daft_log(DAFT_LOG_MALLOC));
		if (_daft_get_data(data->data_list[i], data->files_names[i]) != 0)
			return (data->last_error);
		++i;
	}
	return (0);
}
