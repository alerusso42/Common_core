/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:24:15 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 20:01:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

void 	map_del(t_map *ptr, char *key)
{
	t_map_find_data	data;

	if (!ptr || !key)
		return (map_error(MAP_EINVAL, NULL));
	if (map_find(ptr, key) == false)
		return (map_error(MAP_NOTFOUND, key), NULL);
	if (data.list == ptr->data[data.i]->values)
		ptr->data[data.i]->values = ptr->data[data.i]->values->next;
	lst_delone(data.list, ptr->del);
	ptr->size--;
	if (ptr->data[data.i])
		ptr->data[data.i]->size--;
}
