/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:24:15 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 22:17:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

void 	map_del(t_map *ptr, char *key)
{
	t_map_find_val	val;

	if (!ptr || !key)
		return (map_error(MAP_EINVAL, NULL));
	if (map_find(ptr, key) == false)
		return (map_error(MAP_NOTFOUND, key), NULL);
	if (val.node == ptr)
		ptr->data[val.i]->values = ptr->data[val.i]->values->next;
	lst_delone(val.list, ptr->del);
	ptr->size--;
	if (ptr->data[val.i])
		ptr->data[val.i]->size--;
}
