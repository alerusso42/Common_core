/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:31:42 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/15 18:00:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void	*zone_area_alloc(t_list *zones, uint32_t size)
{
	t_memzone	*zone;
	t_area		*area;
	static int	EYE;

	size += sizeof(t_area);
	++EYE;
	while (zones)
	{
		zone = (t_memzone *)zones->content;
		if (zone->longest_chunk >= size)
		{
			area = zone->first_free_area;
			area = area_find_alloc_block(area, size);
			if (area)
			{
				area_alloc(zone, area, size);
				return (((void *)area) + sizeof(t_area));
			}
			else
				print_zone(zone);
		}
		zones = zones->next;
	}
	return (NULL);
}

t_area	*zone_area_freed(t_list *zones, void *ptr)
{
	t_memzone	*zone;
	t_area		*area;

	ptr += sizeof(t_area);
	while (zones)
	{
		zone = (t_memzone *)zones->content;
		if (ptr >= (void *)zone && ptr < (void *)zone + zone->size)
		{
			area = ((void *)zone) + sizeof(t_memzone);
			area = area_find_freed_block(area, ptr);
			if (!area)
				return (NULL);
			area_freed(area);
			return (area);
		}
		zones = zones->next;
	}
	return (NULL);
}

t_list	*zone_add(t_alloc *data, t_list **zones, uint32_t size)
{
	t_list		*node;
	t_memzone	*new_zone;
	void		*ptr;

	ptr = mmap_syscall(data, size + sizeof(t_area));
	if (!ptr)
		return (error_malloc("zone_add: can't allocate memory\n"));
	node = pool_alloc(data, sizeof(t_memzone));
	if (!node)
		return (munmap_syscall(data, ptr, size), NULL);
	node->content = ptr;
	new_zone = node->content;
	*new_zone = (t_memzone){0};
	new_zone->empty = true;
	new_zone->longest_chunk = size - sizeof(t_memzone);
	new_zone->first_free_area = ((void *)new_zone) + sizeof(t_memzone);
	*new_zone->first_free_area = (t_area){0};
	new_zone->first_free_area->next = new_zone->longest_chunk;
	new_zone->first_free_area->info = MEM_FREED;
	*((t_area *)(((void *)new_zone) + size)) = (t_area){0};
	new_zone->index = lst_size(*zones);
	new_zone->ptr_node = node;
	new_zone->size = round_page(size, data->pagesize);
	lst_front(zones, node);
	data->bytes_alloc += size + sizeof(t_memzone);
	return (node);
}

t_bytelist	zone_find_longest_chunk(t_memzone *zone)
{
	t_bytelist	record;
	t_area		*area;

	record = 0;
	area = zone->first_free_area;
	if (!area)
		return (0);
	while (area->next)
	{
		if (area->info & MEM_FREED && area->next > record)
			record = area->next;
		area = ((void *)area) + area->next;
	}
	return (record);
}

t_area	*zone_find_first_free_area(t_memzone *zone)
{
	t_area	*area;

	//area = ((void *)zone + sizeof(t_memzone));
	area = zone->first_free_area;
	while (area)
	{
		if (area->info & MEM_FREED)
			return (area);
		area = bytelst_next(area);
	}
	zone->longest_chunk = 0;
	return (NULL);
}
