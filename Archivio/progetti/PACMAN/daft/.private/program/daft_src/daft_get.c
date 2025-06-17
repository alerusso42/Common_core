/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:44:50 by codespace         #+#    #+#             */
/*   Updated: 2025/06/17 15:14:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	*select_data_struct(t_daft_data	*data, t_daft_list *file);

void	*daft_get(char *search)
{
	t_daft_data	*data;
	int			hash_result;
	int			offset;
	t_fd		fd;
	void		*mem;

	if (!search)
		return (NULL);
	data = _daft_get_memory(NULL, false);
	if (!data)
		return (0);
	_daft_free_old_mem(data);
	fd = openfd(data->data_list[data->current_file]->filename, "r");
	if (!fd.n)
		return (NULL);
	SDL_RWseek(fd.p, offset, 0);
	//da mettere in un while
	hash_result = _daft_hash(data->data_list[data->current_file], search);
	if (!data->data_list[data->current_file]->node[hash_result])
		return (NULL);
	offset = data->data_list[data->current_file]->node[hash_result]->offset;
	mem = gnl();
	closefd(fd);
	return (mem);
}

static void	*select_data_struct(t_daft_data	*data, t_daft_list *file)
{
	void	*ptr;

	ptr = NULL;
	data->mem.type = NO_MEM;
	if (file->multiple_lines == false && file->split_values == false)
	{
		ptr = _daft_get_string(data, file);
		data->mem.type = STRING;
	}
	else if (file->multiple_lines == true && file->split_values == false)
	{
		ptr = _daft_get_vertical_matr(data, file);
		data->mem.type = TWO_D_MATRIX;
	}
	else if (file->multiple_lines == false && file->split_values == false)
	{
		ptr = _daft_get_horizontal_matr(data, file);
		data->mem.type = TWO_D_MATRIX;
	}
	else if (file->multiple_lines == true && file->split_values == true)
	{
		ptr = _daft_get_three_d_matr(data, file);
		data->mem.type = THREE_D_MATRIX;
	}
	return (ptr);
}
