/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:59:57 by alerusso          #+#    #+#             */
/*   Updated: 2026/03/13 14:09:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

/// @brief set an area as allocated.
///			if there is enough space for another, area is split in two.
/// @param zone ptr to the zone data
/// @param area ptr to the area data
/// @param size size of the area
void	area_alloc(t_memzone *zone, t_area *area, t_bytelist size)
{
	uint32_t	area_size;
	int			new_area_size;

	area_size = area->next;
	zone->empty = false;
	area->info &= (~MEM_FREED);
	new_area_size = ((int)area_size) - ((int)size) - sizeof(t_area);
	if (new_area_size > 0)
		bytelst_split(area, size);
	else
		zone->blocks_freed -= 1;
	if (zone->first_free_area == area)
		zone->first_free_area = zone_find_first_free_area(zone);
	if (zone->blocks_freed == 0)
		zone->longest_chunk = 0;
	else if (new_area_size > 0 && zone->blocks_freed == 1)
		zone->longest_chunk = (uint32_t)new_area_size;
	else
		zone->longest_chunk = zone_find_longest_chunk(zone);
}

/// @brief finds the first available area of size bytes in a zone
/// @param area ptr to the area data
/// @param size size of the area
/// @return first available area, NULL if an error occurred
t_area	*area_find_alloc_block(t_area *area, t_bytelist size)
{
	uint32_t	alignment;

	while (area->next)
	{
		if (area->info & MEM_FREED && area->next >= size)
		{
			alignment = align_addr(((void *)area) + area->next);
			if (area->next + alignment >= size)
				return (area);
		}
		area = ((void *)area) + area->next;
	}
	error_malloc("area_find_alloc_block failure");
	return (NULL);
}

/// @brief mark an area as freed; try merging it with left and right areas.
///			if there are no nearby area, the zone is marked as empty.
/// @param area ptr to the area data
/// @return ptr to the zone data
t_memzone	*area_freed(t_area *area)
{
	t_memzone	*zone;
	t_area		*next;
	t_area		*prev;

	zone = bytelst_head(area);
	zone->blocks_freed += 1;
	if (!zone->first_free_area || zone->first_free_area > area)
	{
		zone->first_free_area = area;
	}
	area->info |= MEM_FREED;
	prev = bytelst_prev(area);
	if (prev && prev->info & MEM_FREED)
	{
		area = bytelst_merge(prev, area);
		zone->blocks_freed -= 1;
	}
	next = bytelst_next(area);
	if (next && next->info & MEM_FREED)
	{
		bytelst_merge(area, next);
		zone->blocks_freed -= 1;
	}
	if (!area->prev && !bytelst_next(area))
	{
		zone->empty = true;
	}
	if (zone->longest_chunk < area->next)
		zone->longest_chunk = area->next;
	else if (DEBUG_FLAG == false)
		VALGRIND_FREELIKE_BLOCK((void *)area + sizeof(t_area), 0);
	return (zone);
}

/// @brief used when a misaligned area is given to free.
///			the correct ptr is found and returned.
/// @param area ptr to the area data
/// @param ptr ptr given by user
/// @return ptr of correct area, NULL if search fails.
t_area	*area_find_freed_block(t_area *area, void *ptr)
{
	void	*head;

	while (area->next)
	{
		if (ptr >= (void *)area && ptr <= (void *)area + area->next)
		{
			head = area + sizeof(t_area);
			if (ptr != head)
			{
				WARNING("$RMalloc, free:$z%p head is %p!\n", ptr, head);
				WARNING("You should free $Y%p$Z\n", head);
			}
			return (area);
		}
		area = area + area->next;
	}
	return (NULL);
}
