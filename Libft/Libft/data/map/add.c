/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:50:00 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 20:05:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

int 	map_add(t_map *ptr, char *key, void *val)
{
	t_map_find_data	data;

	if (!ptr || !key || !val)
		return (map_error(MAP_EINVAL, NULL));
	if (_map_find(ptr, key, &data) == true)
		return (map_error(MAP_EXIST, NULL));
	data.value = ft_calloc(1, sizeof(t_map_val));
	if (!data.value)
		return (map_error(MAP_NOMEM, NULL));
	data.list = lst_new(data.value);
	if (!data.list)//FIXME - head!!!
		return (FREE(data.value), map_error(MAP_NOMEM, NULL));
	lst_back(&ptr->data[data.i]->values, list);
	ptr->size++;
	ptr->data[data.i]->size++;
	map_end_function(ptr);
	return (0);
}
