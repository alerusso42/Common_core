/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_edit2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:55:49 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/22 19:43:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static void	edit_file(t_daft_data *data, int i, char **line, t_daft_mem *mem);

t_daft_mem	*check_edit(t_daft_data *data, int list_n, char *line)
{
	int			i;
	int			hash;
	t_daft_mem	*mem;

	if (*line == '#')
		return (NULL);
	else if (!ft_strchr(line, *data->data_list[list_n]->field_sep))
		return (NULL);
	i = data->mem_size;
	hash = _daft_hash(data->data_list[i], line);
	mem = _daft_old_mem_node(data, i--);
	while (mem)
	{
		if (mem->hash == hash)
		{
			data->mem.add = i + 1;
			return (mem);
		}
		mem = _daft_old_mem_node(data, i--);
	}
	return (NULL);
}

int	open_files(t_daft_data *data, char *f_read, char *f_write)
{
	t_fd	fd_replace;
	t_fd	fd_file;

	if (data->temp_files[0].n || data->temp_files[1].n)
	{
		closefd(data->temp_files[0]);
		closefd(data->temp_files[1]);
	}
	fd_replace = openfd(f_write, "w");
	fd_file = openfd(f_read, "r");
	if (!fd_replace.n || !fd_file.n)
	{
		closefd(fd_replace);
		closefd(fd_file);
		return (1);
	}
	data->temp_files[1] = fd_replace;
	data->temp_files[0] = fd_file;
	return (0);
}

int	ROCKY(t_daft_data *data, int i)
{
	char		*line;
	t_daft_mem	*edit;

	if (open_files(data, data->data_list[i]->filename, DAFT_PWD"/temp_file"))
		return (1);
	line = gnl();
	while (line)
	{
		edit = check_edit(data, i, line);
		if (edit)
			edit_file(data, i, &line, edit);
		else
		{
			fd_printf(data->temp_files[1], "%s\n", line);
			line = gnl();
		}
	}
	if (open_files(data, DAFT_PWD"/temp_file", data->data_list[i]->filename))
		return (1);
	line = gnl();
	while (line)
	{
		fd_printf(data->temp_files[1], "%s\n", line);
		line = gnl();
	}
	return (closefd(data->temp_files[0]), closefd(data->temp_files[1]), 0);
}
