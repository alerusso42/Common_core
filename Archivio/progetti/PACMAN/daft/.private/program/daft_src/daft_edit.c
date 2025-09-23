/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:04:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/23 11:28:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

void	*daft_edit(const char *search, int size, int mtr_number)
{
	t_daft_data	*data;
	void		*mem;

	if (!search)
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
	mem = daft_get(search);
	data->minimal_alloc_size = 0;
	data->minimal_matrix_num = 1;
	if (mem)
		data->data_list[data->current_file]->edit = true;
	return (mem);
}
