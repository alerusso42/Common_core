/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:36:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/16 00:32:23 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_settings_file(t_daft_data *data);
static int	save_config(t_daft_data *data, t_fd	settings_file);
static int	parse_config(t_daft_data *data, char *line);
static int	save_fnames(t_daft_data *data, t_fd	settings_file);
static int	parse_fnames(t_daft_data *data, char *line, int *fnum, int *matr_s);

int 	daft_init(void)
{
	t_daft_data	*data;

	if (_daft_get_memory(NULL, false))
		return (0);
	data = ft_calloc(1, sizeof(t_daft_data));
	if (!data)
		return (DAFT_LOG_MALLOC);
	_daft_get_memory(data, true);
	if (get_settings_file(data) == false)
		return (data->last_error);
	if (get_database_files(data) == false)
		return (data->last_error);
	return (0);
}

static int	get_settings_file(t_daft_data *data)
{
	char	*settings_file_name;
	char	*line;
	t_fd	settings_file;

	settings_file_name = ft_strjoin(daft_pwd, "/SETTINGS.md");
	if (!settings_file_name)
		return (_daft_log(data, DAFT_LOG_MALLOC));
	settings_file = openfd(settings_file_name, "r");
	if (!settings_file.n)
		return (SDL_free(settings_file_name), _daft_log(data, DAFT_LOG_SETT));
	line = gnl();
	while (line)
	{
		if (!ft_strncmp(line, "#SECTION - General settings", 27))
		{
			if (save_config(data, settings_file) == DAFT_LOG_MALLOC)
				closefd(settings_file);
		}
		else if (!ft_strncmp(line, "#SECTION - Files flags", 22))
		{
			if (save_fnames(data, settings_file) == DAFT_LOG_MALLOC)
				closefd(settings_file);
		}
		SDL_free(line);
		line = gnl();
	}
	closefd(settings_file);
}

static int	save_config(t_daft_data *data, t_fd	settings_file)
{
	bool	found_first;
	char	*line;

	found_first = false;
	line = gnl();
	while (line)
	{
		if (found_first && !ft_strncmp(line, "\n", 1))
		{
			SDL_free(line);
			break ;
		}
		else if (!ft_strchr("\n#", line[0]))
		{
			found_first = true;
			if (parse_config(data, line) != 0)
			{
				SDL_free(line);
				break ;
			}
		}
		SDL_free(line);
		line = gnl();
	}
}

static int	parse_config(t_daft_data *data, char *line)
{
	if (!ft_strncmp(line, "DEFAULT_FLAGS->", 15))
	{
		data->conf.default_flags = ft_strdup(line + 15);
		if (!data->conf.default_flags)
			return (_daft_log(data, DAFT_LOG_MALLOC));
	}
	else if (!ft_strncmp(line, "DEBUG_LOG->", 11))
	{
		if (line[11] == 'y')
			data->conf.debug_log = true;
	}
	return (0);
}

static int	save_fnames(t_daft_data *data, t_fd	settings_file)
{
	bool	found_files;
	int		fnum;
	int		matr_s;
	char	*line;

	found_files = false;
	fnum = 0;
	matr_s = 0;
	line = gnl();
	while (line)
	{
		if (found_files && line[0] == '#')
			break ;
		else if (!ft_strncmp(line, "# -- FLAGS -- #", 15))
			found_files = true;
		else if (parse_fnames(data, line, &fnum, &matr_s) == DAFT_LOG_MALLOC)
		{
			SDL_free(line);
			return (DAFT_LOG_MALLOC);
		}
		SDL_free(line);
		line = gnl();
	}
	SDL_free(line);
	return (0);
}

static int	parse_fnames(t_daft_data *data, char *line, int *fnum, int *matr_s)
{
	int	len;

	len = 0;
	while (line[len] && !ft_strncmp(line + len, "->", 2))
		++len;
	cut_string(line, len, INT_MAX);
	if (*fnum == *matr_s)
		if (resize_matr(data->files_names) == DAFT_LOG_MALLOC)
			return (_daft_log(data, DAFT_LOG_MALLOC));
}
