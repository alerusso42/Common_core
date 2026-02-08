/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:22:21 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 22:11:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

int map_replace(t_map *ptr, char *key, void *new_val)
{
	t_map_find_val	val;

	if (!ptr || !key || !new_val)
		return (map_error(MAP_EINVAL, NULL));
	if (_map_find(ptr, key, &val) == true)
		_map_del(ptr, key, &val);
	val.value = ft_calloc(1, sizeof(t_map_val));
	if (!val.value)
		return (map_error(MAP_NOMEM, NULL));
	val.node = lst_new(val.value);
	if (!val.node)
		return (FREE(val.value), map_error(MAP_NOMEM, NULL));
	lst_back(&ptr->data[val.i]->values, val.node);
	ptr->size++;
	ptr->data[val.i]->size++;
	return (0);
}
