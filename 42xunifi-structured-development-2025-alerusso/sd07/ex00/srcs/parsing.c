/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:26:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 23:26:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	add_line(t_data *data, char *line, int fd);
static void	save_offsets(t_data *data);

void	parsing(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->filename, P_EXIST, 0777);
	if (fd < 0)
		error(data, ER_MISSING_DATABASE);
	line = get_next_line(fd, false);
	while (line)
	{
		if (valid_entry(line) == true)
			add_line(data, line, fd);
		else
			delete_warning(data, line);
		free(line);
		line = get_next_line(fd, false);
	}
	close(fd);
	save_offsets(data);
	free_all_matrix(data);
}

static void	add_line(t_data *data, char *line, int fd)
{
	int	i;

	trim_spaces(line);
	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		if (data->entry[i].last_element >= data->entry[i].size)
		{
			if (resize_matr(&data->entries[i], &data->entry[i].size) == 1)
			{
				close(fd);
				error(data, ER_MALLOC);
			}
		}
		data->entries[i][data->entry[i].last_element] = ft_strdup(line);
		if (!data->entries[i][data->entry[i].last_element])
		{
			close(fd);
			error(data, ER_MALLOC);
		}
		data->entry[i].last_element++;
		++i;
	}
}

static void	save_offsets(t_data *data)
{
	int	i;

	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		prioritize_main_entry(data, i);
		sort(data->entries[i], data->entry[i].type);
		print_matrix(data, data->entries[i], data->entry[i].filename);
		offset_matrix(data, i);
		++i;
	}
}
