/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:37:21 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 15:31:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

// returns true if found
// else false
bool	map_find(t_map *ptr, const char *key, t_map_find_data *val)
{
	size_t		i;
	t_list		*list;
	t_map_val	*node;

	i = ptr->hasher(key) % ptr->hash_size;
	if (!ptr->data[i])
		return (map_error(MAP_NOTFOUND, key), false);
	list = ptr->data[i]->values->content;
	while (list)
	{
		node = list->content;
		if (ft_strncmp(key, node->key, INT_MAX) == 0)
			break ;
		list = list->next;
	}
	if (!list)
		return (map_error(MAP_NOTFOUND, key), false);
	if (!val)
		return (true);
	val->i = i;
	val->list = list;
	val->key = node->key;
	val->value = node->val;
	return (true);
}
