/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:35:31 by codespace         #+#    #+#             */
/*   Updated: 2025/06/17 23:01:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
//REVIEW -	daft_swap
//
	In daft.h, there is an enum, called e_daft_db.
	You can pass those enum to daft_swap, to change database.

	Note: enum names can be changed in SETTINGS.md
*/
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
