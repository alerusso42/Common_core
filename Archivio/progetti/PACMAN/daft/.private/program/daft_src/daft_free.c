/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:43:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 12:13:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

/*
//REVIEW -	daft_get
//
	Free a memory returned by daft, in a call of daft_get.
	Only calls that does not return NULL count; the count starts by 0.
	If -1 is given, every allocated memory from start are freed; then, count
	is reset to 0.
*/
void	daft_free(int daft_get_call)
{
	t_daft_data	*data;

	data = _daft_get_memory(NULL, false);
	if (!data)
		return ;
	_daft_free_mem(data, daft_get_call);
	return ;
}
