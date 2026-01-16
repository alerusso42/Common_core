/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:51:09 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/16 10:01:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

/*
//REVIEW -	daft_iter
- when called, returns the key used to access the CSV.
- on a new call, returns the next key.
- on the last call, return NULL, and reset the iterator to start.

- you can pass the enum_id, or -1 (DAFT_CURR_DATA) to use the current database.
*/
char	*daft_iter(int enum_id)
{
	t_daft_data	*data;

	data = _daft_get_memory(NULL, false);
	if (!data)
		return (_daft_log(DAFT_LOG_NOMEM));
	if (enum_id == DAFT_CURR_DATA)
		enum_id = data->current_file;
	else if (enum_id >= data->files_num || enum_id < 0)
		return (_daft_log(DAFT_LOG_ENUM_ID), NULL);
	
		
}