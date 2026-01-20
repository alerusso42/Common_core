/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:20:56 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/20 12:03:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static void	free_correct_area(t_alloc *data, void *ptr);
static void	munmap_zone_if_empty(t_alloc *data, t_memzone *zone);

void 	free(void *ptr)
{
	t_alloc		*data;
	t_memzone	*zone;

	data = _global_data(false);
	switch (identify_area(data, ptr))
	{
		case (MEM_ALLOC) :
			zone = area_freed(ptr - sizeof(t_area));
			munmap_zone_if_empty(data, zone);
			break ;
		case (MEM_FREED) :
			return (WARNING("$RFree: $Z%p $Ralready freed$Z\n"));
		case (MEM_INTERNAL) :
			return ;
		case (MEM_INVALID) :
			free_correct_area(data, ptr);
			break ;
		case (MEM_ERROR) :
			return ;
	}
}

static void	free_correct_area(t_alloc *data, void *ptr)
{
	t_area	*area;

	WARNING("Free: ptr %p is not correct!\n", ptr);
	area = zone_area_freed(data->zone_tiny, ptr);
	if (!area)
		area = zone_area_freed(data->zone_small, ptr);
	if (!area)
		area = zone_area_freed(data->zone_large, ptr);
	if (!area)
	{
		WARNING("Free: ptr %p is invalid!\n", ptr);
		return ;
	}
	else if (DEBUG_FLAG == false)
	{
		VALGRIND_FREELIKE_BLOCK((void *)area + sizeof(t_area), 0);
	}
}

static void	munmap_zone_if_empty(t_alloc *data, t_memzone *zone)
{
	
	if (zone->empty == false)
		return ;
	if (zone->ptr_node == data->zone_tiny)
		data->zone_tiny = data->zone_tiny->next;
	else if (zone->ptr_node == data->zone_small)
		data->zone_small = data->zone_small->next;
	else if (zone->ptr_node == data->zone_large)
		data->zone_large = data->zone_large->next;
	lst_delone(zone->ptr_node, NULL);
	munmap_syscall(data, zone, zone->size);
	if (!data->zone_tiny && !data->zone_small && !data->zone_large)
		return (malloc_munmap_data(data));
}
