/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:35:31 by codespace         #+#    #+#             */
/*   Updated: 2025/06/17 15:01:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	daft_swap(int enum_id)
{
	t_daft_data	*data;

	data = _daft_get_memory(NULL, false);
	if (!data)
		return ;
	_daft_free_old_mem(data);
	if (enum_id >= data->files_num || enum_id < 0)
		return ;
	data->current_file = enum_id;
}
