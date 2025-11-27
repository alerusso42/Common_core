/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:07:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 17:24:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static void	append(t_daft_data *dt, t_daft_mem *mem, int fn);

void	_daft_append_data(t_daft_data *data, t_daft_list *file, int file_n)
{
	t_daft_mem	*mem;
	int			i;

	if (_daft_append_files(data, file->filename, file->filename))
		return ;
	i = 0;
	mem = _daft_old_mem_node(data, i);
	while (mem)
	{
		data->mem.add = i;
		if (mem->offset)
			append(data, mem, file_n);
		else
			i++;
		mem = _daft_old_mem_node(data, i);
	}
	closefd(data->temp_files[0]);
	closefd(data->temp_files[1]);
}

static void	append(t_daft_data *dt, t_daft_mem *mem, int fn)
{
	char	*line;

	SEEK(dt->temp_files[0].p, mem->offset, SEEK_SET);
	line = gnl();
	if (!line)
	{
		_daft_free_mem(dt, dt->mem.add);
		return ;
	}
	fd_printf(dt->temp_files[1], "\n");
	_daft_append_f(dt, fn, &line, mem);
	FREE(line);
}

