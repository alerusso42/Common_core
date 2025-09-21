/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:04:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 14:28:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

void	*daft_edit(const char *search, int size)
{
	t_daft_data	*data;
	void		*mem;

	if (!search)
		return (NULL);
	data = _daft_get_memory(NULL, false);
	if (!data)
		return (NULL);
	data->minimal_alloc_size = size;
	mem = daft_get(search);
	data->minimal_alloc_size = 0;
	if (mem)
		data->data_list[data->current_file]->edit = true;
	return (mem);
}