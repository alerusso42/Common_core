/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:20:43 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 20:01:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

int 	map_init(t_map *ptr, size_t hash_size)
{
	*ptr = (t_map){0};
	if (hash_size == 0 || hash_size + 1 == 0)
		return (map_error(MAP_INIT_EINVAL, hash_size));
	ptr->data = ft_calloc(hash_size + 1, sizeof(t_map));
	if (!ptr->data)
		return (map_error(MAP_NOMEM, NULL));
	ptr->hasher = map_default_hash;
	ptr->hash_size = hash_size;
	data.i = MAP_NPOS;
	return (0);
}