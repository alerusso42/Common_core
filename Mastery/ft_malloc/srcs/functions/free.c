/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:20:56 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/12 19:02:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static void	free_correct_area(t_alloc *data, void *ptr);
static void	munmap_zone_if_empty(t_alloc *data, t_memzone *zone);

void 	free(void *ptr)
{
	t_alloc		*data;
	t_area		*area;
	t_memzone	*zone;

	if (!ptr)
		return ;
	data = _global_data(false);
	if (data->error)
		return ;
	if (ptr >= data->pool.mem && ptr <= data->pool.mem + data->pool.size)
		return ;
	area = ptr - sizeof(t_area);
	if (area->info != 0 && area->info != 1)
		free_correct_area(data, ptr);
	zone = area_freed(area);
	munmap_zone_if_empty(data, zone);
}

static void	free_correct_area(t_alloc *data, void *ptr)
{
	t_area	*area;

	PRINT("Free: ptr %p is not correct!\n", ptr);
	area = zone_area_freed(data->zone_tiny, ptr);
	if (!area)
		area = zone_area_freed(data->zone_small, ptr);
	if (!area)
		area = zone_area_freed(data->zone_large, ptr);
	if (!area)
	{
		PRINT("Free: ptr %p is invalid!\n", ptr);
		return ;
	}
	else if (DEBUG_FLAG == false)
	{
		VALGRIND_FREELIKE_BLOCK((void *)area + sizeof(t_area), 0);
	}
}

static void	munmap_zone_if_empty(t_alloc *data, t_memzone *zone)
{
	t_list	*temp;

	if (zone->first_free_area)
		return ;
	temp = zone->ptr_node;
	lst_delone(zone->ptr_node, NULL);
	if (temp == data->zone_tiny)
		data->zone_tiny = NULL;
	else if (temp == data->zone_small)
		data->zone_small = NULL;
	else if (temp == data->zone_large)
		data->zone_large = NULL;
	munmap_syscall(data, zone, zone->size);
	if (!data->zone_tiny && !data->zone_small && !!data->zone_large)
		malloc_munmap_data(data);
}
