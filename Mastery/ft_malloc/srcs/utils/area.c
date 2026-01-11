/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:59:57 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/11 22:01:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void	area_alloc(t_area *area, t_bytelist size)
{
	t_memzone	*zone;

	zone = bytelst_head(area);
	if (zone->first_free_area == area)
		zone->first_free_area = zone_find_first_free_area(zone);
	if (zone->longest_chunk == area->next)
		zone->longest_chunk = zone_find_longest_chunk(zone);
	zone->free_space -= size;
	area->info &= (~MEM_FREED);
	bytelst_split(area, size);
}

t_area	*area_find_alloc_block(t_area *area, t_bytelist size)
{
	while (area->next)
	{
		if (area->next >= size)
			return (area);
		area += area->next;
	}
	error_malloc("area_find_alloc_block failure");
	return (NULL);
}

t_memzone	*area_freed(t_area *area)
{
	t_memzone	*zone;

	zone = bytelst_head(area);
	if (zone->first_free_area > area)
		zone->first_free_area = area;
	if (zone->longest_chunk < area->next)
		zone->longest_chunk = area->next;
	zone->free_space += area->next;
	area->info |= MEM_FREED;
	if (area->prev && bytelst_prev(area)->info & MEM_FREED)
	{
		area = bytelst_merge(bytelst_prev(area), area);
	}
	if (area->next && bytelst_next(area)->info & MEM_FREED)
	{
		bytelst_merge(area, bytelst_next(area));
	}
	return (zone);
}

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
