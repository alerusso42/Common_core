/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:28:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/23 19:49:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static void	*get_sample(t_daft_data *data, t_daft_list *file, char *key);
static void	*gen_sample(t_daft_data *data, t_daft_list *file, char *key, int i);

void	*daft_append(char *key, int size, int mtr_number)
{
	t_daft_data	*data;
	void		*mem;

	if (!key)
		return (NULL);
	if (size < 0)
		size = 0;
	if (mtr_number <= 0)
		mtr_number = 1;
	data = _daft_get_memory(NULL, false);
	if (!data)
		return (NULL);
	data->minimal_alloc_size = size;
	data->minimal_matrix_num = mtr_number;
	mem = get_sample(data, data->data_list[data->current_file], key);
	data->minimal_alloc_size = 0;
	data->minimal_matrix_num = 1;
	if (mem)
		data->data_list[data->current_file]->append = true;
	return (mem);
}

static void	*get_sample(t_daft_data *data, t_daft_list *file, char *key)
{
	return (gen_sample(data, file, key, file->first_node));
}

static void	*gen_sample(t_daft_data *data, t_daft_list *file, char *key, int i)
{
	t_fd	fd;
	char	*line;
	void	*mem;

	fd = openfd(data->data_list[data->current_file]->filename, "r");
	if (!fd.n)
		return (NULL);
	SEEK(fd.p, file->node[i]->offset, RW_SEEK_SET);
	line = gnl();
	if (!line)
		return (closefd(fd), NULL);
	mem = _daft_select_mem_type(data, file, line);
	FREE(line);
	closefd(fd);
	if (mem)
	{
		data->mem.file = data->current_file;
		data->mem.hash = i;
		data->mem.key = ft_strjoin(key, file->field_sep);
		data->mem.offset = file->node[i]->offset;
		_daft_add_mem(data);
	}
	return (mem);
}
