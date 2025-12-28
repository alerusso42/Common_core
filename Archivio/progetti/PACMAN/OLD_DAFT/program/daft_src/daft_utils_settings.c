/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_settings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:50:14 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 10:01:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static int	parse_config(t_daft_data *data, char *line);

//	Checks for settings in all lines that are not comments.
//	Stop when finding an empty line after the first setting found.
int	_daft_save_config(t_daft_data *data)
{
	bool	found_first;
	char	*line;

	found_first = false;
	line = gnl();
	while (line)
	{
		if (found_first && !line[0])
		{
			FREE(line);
			break ;
		}
		else if (!ft_strchr("#", line[0]))
		{
			found_first = true;
			if (parse_config(data, line) != 0)
			{
				FREE(line);
				break ;
			}
		}
		FREE(line);
		line = gnl();
	}
	return (0);
}

//	List of all general config.
static int	parse_config(t_daft_data *data, char *line)
{
	if (!ft_strncmp(line, "DEFAULT_FLAGS->", 15))
	{
		data->conf.default_flags = ft_strdup(line + 15);
		if (!data->conf.default_flags)
			return (_daft_log(DAFT_LOG_MALLOC));
	}
	else if (!ft_strncmp(line, "DEBUG_LOG->", 11))
	{
		if (line[11] == 'y')
			data->conf.debug_log = true;
	}
	return (0);
}
