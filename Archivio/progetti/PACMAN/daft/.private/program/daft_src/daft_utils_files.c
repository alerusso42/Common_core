/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:18:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/22 18:26:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

int	_daft_find_data_type(t_daft_list *file)
{
	if (file->multiple_lines == false && file->split_values == false)
	{
		return (STRING);
	}
	else if (file->multiple_lines == true && file->split_values == false)
	{
		return (TWO_D_MATRIX);
	}
	else if (file->multiple_lines == false && file->split_values == true)
	{
		return (TWO_D_MATRIX_VERTICAL);
	}
	else if (file->multiple_lines == true && file->split_values == true)
	{
		return (THREE_D_MATRIX);
	}
	return (NO_MEM);
}
