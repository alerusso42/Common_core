/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:20:51 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 00:48:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

void 	map_clear(t_map *ptr)
{
	for (int i = 0; ptr->size && i != ptr->hash_size; i++)
	{
		lst_clear(&ptr->data[i], ptr->del);
		ptr->size--;
	}
	if (ptr->size)
		map_error(MAP_BUG, ptr->size);
}
