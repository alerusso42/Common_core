/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:20:46 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 19:59:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

void 	*map_get(t_map *ptr, char *key)
{
	t_map_find_data	data;

	if (!ptr || !key)
		return (map_error(MAP_EINVAL, NULL));
	if (_map_find(ptr, key, &data) == false)
		return (map_error(MAP_NOTFOUND, key), NULL);
	return (data.value);
}
