/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:59:57 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/12 22:40:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void	area_alloc(t_memzone *zone, t_area *area, t_bytelist size)
{
	uint32_t	area_size;
	uint32_t	alignment;
	int			new_area_size;
	t_area		*prev;
//FIXME allineamento
	print_zone(zone);
	alignment = align_addr()
	area_size = area->next;
	zone->free_space -= size;
	area->info &= (~MEM_FREED);
	new_area_size = ((int)area_size) - ((int)size) - sizeof(t_area);
	if (new_area_size > 0)
		bytelst_split(area, size);
	if (zone->first_free_area == area)
		zone->first_free_area = zone_find_first_free_area(zone);
	if (zone->longest_chunk == area_size)
		zone->longest_chunk = zone_find_longest_chunk(zone);
}

/*
	oooooooooo	lc = 10
	xxxxxooooo	lc = 5
	xxxxxbbboo	lc = 2
	ooooobbboo	lc = 5
*/
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

t_memzone	*area_freed(t_area *area)
{
	t_memzone	*zone;
	t_area		*next;
	t_area		*prev;

	zone = bytelst_head(area);
	print_zone(zone);
	if (zone->first_free_area > area)
		zone->first_free_area = area;
	if (zone->longest_chunk < area->next)
		zone->longest_chunk = area->next;
	zone->free_space += area->next;
	area->info |= MEM_FREED;
	prev = bytelst_prev(area);
	if (prev && prev->info & MEM_FREED)
	{
		area = bytelst_merge(prev, area);
	}
	next = bytelst_next(area);
	if (next && next->info & MEM_FREED)
	{
		bytelst_merge(area, next);
	}
	if (!area->prev && !bytelst_next(area))
		zone->first_free_area = NULL;
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
