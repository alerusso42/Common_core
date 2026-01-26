/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:20:59 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/09 15:20:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static void	*get_mem(t_alloc *dt, uint32_t size, t_list **zones, int zone_size);

void 	*malloc(size_t size)
{
	t_alloc		*data;
	void		*ptr;

	data = _global_data(false);
	if (data->error)
		return (NULL);
	if (size > data->size_area.large)
		return (error_malloc("request size too large"));
	else if (size > data->size_area.small)
		ptr = get_mem(data, size, &data->zone_large, data->header_size + size);
	else if (size > data->size_area.tiny)
		ptr = get_mem(data, size, &data->zone_small, data->size_zone.small);
	else
		ptr = get_mem(data, size, &data->zone_tiny, data->size_zone.tiny);
	if (DEBUG_FLAG == false && ptr)
	{
		VALGRIND_MALLOCLIKE_BLOCK(ptr, size, 0, false);
	}
	return (ptr);
}

static void	*get_mem(t_alloc *dt, uint32_t size, t_list **zones, int zone_size)
{
	void	*ptr;

	ptr = zone_area_alloc(*zones, size);
	if (ptr)
		return (ptr);
	if (!zone_add(dt, zones, zone_size))
		return (fatal_malloc("cannot allocate new zone"));
	ptr = zone_area_alloc(*zones, size);
	if (!ptr)
		return (fatal_malloc("unexpected error in address selection"));
	return (ptr);
}
