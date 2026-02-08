/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:22:21 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 02:04:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

int map_replace(t_map *ptr, char *key, void *val)
{
	t_list		*list;
	t_map_node	*node;

	if (!ptr || !key || !val)
		return (map_error(MAP_EINVAL, NULL));
	if (map_find(ptr, key) == true)
		map_del(ptr, key);
	node = ft_calloc(1, sizeof(t_map_node));
	if (!node)
		return (map_error(MAP_NOMEM, NULL));
	list = lst_new(node);
	if (!list)
		return (map_error(MAP_NOMEM, NULL));
	lst_back(&ptr->data[ptr->_priv.i]->values, list);
	ptr->size++;
	ptr->data[ptr->_priv.i]->size++;
	map_end_function(ptr);
	return (0);
}
