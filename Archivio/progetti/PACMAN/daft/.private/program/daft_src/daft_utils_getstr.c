/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_getstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:11:28 by codespace         #+#    #+#             */
/*   Updated: 2025/06/18 00:25:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
	1)	|nn=,		|	Colors			|	"Red,Yellow,Green"
*/
void	*_daft_get_string(t_daft_data *data, t_daft_list *file, char *key)
{
	data->mem.ptr = key;
	return (key + sub_strlen(key, file->field_sep, EXCLUDE));
}
