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

/// @brief returns heap memory. Manages kernel syscall mmap internally.
/// @param size bytes needed for memory chunk
/// @return aligned ptr of heap memory, NULL if an error occurred
void 	*malloc(size_t size)
{
	t_alloc		*data;
	void		*ptr;

	thread_safe(MALL_THREAD_LOCK);
	data = malloc_global_data();
	if (data->error)
		return (thread_safe(MALL_THREAD_UNLOCK), NULL);
	if (size > data->size_area.large)
		return (thread_safe(MALL_THREAD_UNLOCK), error_malloc("request size too large"));
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
	thread_safe(MALL_THREAD_UNLOCK);
	return (ptr);
}

/// @brief if there is an available area of size bytes, returns it.
///			else, create a new zone calling mmap, then returns its first area.
/// @param dt ptr of malloc data
/// @param size bytes needed by user
/// @param zones ptr to the list of zones (3: little, small, large zone lists)
/// @param zone_size the total size of the zone.
/// @return aligned ptr of heap memory, NULL if an error occurred
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
