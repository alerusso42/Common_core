/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:11:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/26 00:24:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

/*
//REVIEW -	daft_load
//	Update all files opened with successful calls of daft_append() and 
	daft_edit().
//	Memories pointers connected to daft_append() and daft_edit() are freed.
	Using them later bring undefined behaviour.
*/
int	daft_load(void)
{
	int			curr_file;
	int			exit_code;
	t_daft_data	*data;

	data = _daft_get_memory(NULL, false);
	if (!data)
		return (_daft_log(DAFT_LOG_NOMEM));
	curr_file = data->current_file;
	daft_quit();
	exit_code = daft_init();
	data = _daft_get_memory(NULL, false);
	if (data)
		data->current_file = curr_file;
	return (exit_code);
}
