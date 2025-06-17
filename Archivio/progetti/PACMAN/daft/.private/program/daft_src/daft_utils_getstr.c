/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_getstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:11:28 by codespace         #+#    #+#             */
/*   Updated: 2025/06/17 15:35:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*_daft_get_string(t_daft_data *data, t_daft_list *file)
{
	char	*string;

	string = gnl();
	data->mem.ptr = string;
	return (string + sub_strlen(string, file->field_sep, EXCLUDE));
}
