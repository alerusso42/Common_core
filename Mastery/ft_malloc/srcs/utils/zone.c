/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:31:42 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/10 16:33:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

t_bytelist	zone_find_longest_chunk(t_memzone *zone)
{
	t_bytelist	record;
	t_area		*area;

	record = 0;
	area = zone + sizeof(t_memzone);
	while (area->next)
	{
		if (area->next > record)
			record = area->next;
		area += area->next;
	}
	return (record);
}

t_area	*zone_find_first_free_area(t_memzone *zone)
{
	t_area	*area;

	area = zone->first_free_area;
	while (area->next)
	{
		if (area->info & MEM_FREED)
			return (area);
		area += area->next;
	}
	return (NULL);
}

bool	zone_alloc(t_list *zones, uint32_t size)
{
	t_memzone	*zone;
	t_area		*area;

	size += sizeof(t_area);
	while (zones)
	{
		zone = (t_memzone *)zones->content;
		if (zone->longest_chunk >= size)
		{
			area = (t_area *)zone + sizeof(t_memzone);
			area = area_find_alloc_block(area, size);
			if (!area)
				return (EXIT_FAILURE);
			area_alloc(area, size);
			return (EXIT_SUCCESS);
		}
		zones = zones->next;
	}
	return (EXIT_FAILURE);
}

bool	zone_freed(t_list *zones, void *ptr)
{
	t_memzone	*zone;
	t_area		*area;

	ptr += sizeof(t_area);
	while (zones)
	{
		zone = (t_memzone *)zones->content;
		if (ptr >= zone && ptr < zone + zone->size)
		{
			area = (t_area *)zone + sizeof(t_memzone);
			area = area_find_freed_block(area, ptr);
			if (!area)
				return (EXIT_FAILURE);
			area_freed(area);
			return (EXIT_SUCCESS);
		}
		zones = zones->next;
	}
	return (EXIT_FAILURE);
}
