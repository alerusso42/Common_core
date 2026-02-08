/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:22:21 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 19:52:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

int map_replace(t_map *ptr, char *key, void *val)
{
	t_map_find_data	data;

	if (!ptr || !key || !val)
		return (map_error(MAP_EINVAL, NULL));
	if (_map_find(ptr, key, &data) == true)
		_map_del(ptr, key, &data);
	data.value = ft_calloc(1, sizeof(t_map_val));
	if (!data.value)
		return (map_error(MAP_NOMEM, NULL));
	data.list = lst_new(data.value);
	if (!data.list)
		return (FREE(data.value), map_error(MAP_NOMEM, NULL));
	lst_back(&ptr->data[data.i]->values, data.list);
	ptr->size++;
	ptr->data[data.i]->size++;
	return (0);
}
