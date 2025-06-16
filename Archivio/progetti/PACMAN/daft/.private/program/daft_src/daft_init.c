/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:36:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/16 15:43:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_settings_file(t_daft_data *data);
static int	get_database_file(t_daft_data *data);

int 	daft_init(void)
{
	t_daft_data	*data;

	if (_daft_get_memory(NULL, false))
		return (0);
	data = ft_calloc(1, sizeof(t_daft_data));
	if (!data)
		return (DAFT_LOG_MALLOC);
	_daft_get_memory(data, true);
	if (get_settings_file(data) == 1)
		return (data->last_error);
	if (get_database_file(data) == 1)
		return (data->last_error);
	return (0);
}

static int	get_settings_file(t_daft_data *data)
{
	char	*settings_file_name;
	char	*line;
	t_fd	settings_file;

	settings_file_name = ft_strjoin(DAFT_PWD, "/SETTINGS.md");
	if (!settings_file_name)
		return (_daft_log(DAFT_LOG_MALLOC));
	settings_file = openfd(settings_file_name, "r");
	if (!settings_file.n)
		return (SDL_free(settings_file_name), _daft_log(DAFT_LOG_SETT));
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
		SDL_free(line);
		line = gnl();
	}
	return (SDL_free(settings_file_name), closefd(settings_file), 0);
}

static int	get_database_file(t_daft_data *data)
{
	int	i;

	data->data_list = ft_calloc(data->files_num + 1, sizeof(t_daft_list *));
	if (!data->data_list)
		return (_daft_log(DAFT_LOG_MALLOC));
	i = 0;
	while (i != data->files_num)
	{
		if (_daft_get_data(data->data_list[i], data->files_names[i]) != 0)
			return (data->last_error);
		++i;
	}
	return (0);
}
