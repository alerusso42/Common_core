/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:20:46 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 01:59:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void 	*map_get(t_map *ptr, char *key)
{
	void	*val;

	if (!ptr || !key)
		return (map_error(MAP_EINVAL, NULL));
	if (map_find(ptr, key) == false)
		return (map_error(MAP_NOTFOUND, key), NULL);
	val = ptr->_priv.node->val;
	map_end_function(ptr);
	return (val);
}
