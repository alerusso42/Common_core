/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:37:21 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 01:54:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

// returns true if found
// else false
bool	map_find(t_map *ptr, const char *key)
{
	size_t		i;
	t_list		*list;
	t_map_node	*node;

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
	ptr->_priv.i = i;
	ptr->_priv.list = list;
	ptr->_priv.node = node;
	return (true);
}

void	map_end_function(t_map *ptr)
{
	ptr->_priv = (t_map_private){0};
	ptr->_priv.i = MAP_NPOS;
}
