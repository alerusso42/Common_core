/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:24:15 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 02:03:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

void 	map_del(t_map *ptr, char *key)
{
	if (!ptr || !key)
		return (map_error(MAP_EINVAL, NULL));
	if (map_find(ptr, key) == false)
		return (map_error(MAP_NOTFOUND, key), NULL);
	if (ptr->_priv.list == ptr->data[ptr->_priv.i]->values)
		ptr->data[ptr->_priv.i]->values = ptr->data[ptr->_priv.i]->values->next;
	lst_delone(ptr->_priv.list, ptr->del);
	ptr->size--;
	if (ptr->data[ptr->_priv.i])
		ptr->data[ptr->_priv.i]->size--;
	map_end_function(ptr);
}
