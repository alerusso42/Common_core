/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:37:21 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 22:06:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

// returns true if found
// else false
bool	_map_find(t_map *ptr, const char *key, t_map_find_val *val)
{
	size_t		i;
	t_list		*values;
	t_map_val	*node;

	i = ptr->hasher(key) % ptr->hash_size;
	if (!ptr->data[i])
		return (map_error(MAP_NOTFOUND, key), false);
	values = ptr->data[i]->values;
	while (values)
	{
		node = values->content;
		if (ft_strncmp(key, node->key, INT_MAX) == 0)
			break ;
		values = values->next;
	}
	if (!values)
		return (map_error(MAP_NOTFOUND, key), false);
	if (!val)
		return (true);
	val->i = i;
	val->head = ptr->data[i]->values;
	val->node = values->content;
	val->key = node->key;
	val->value = node->val;
	return (true);
}

// returns true if found
// else false
bool	map_find(t_map *ptr, const char *key)
{
	return (_map_find(ptr, key, NULL));
}
