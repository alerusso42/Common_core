/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:54:33 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/11 22:02:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static void	munmap_zone(t_alloc *mem, t_list *list);

//always return alloc global data.
//if reset is true, they are set to default values
t_alloc	*_global_data(bool reset)
{
	static t_alloc	data;

	if (data.pagesize == 0 || reset)
	{
		data = (t_alloc){0};
		data.pagesize = sysconf(_SC_PAGESIZE);
		if (!data.pagesize)
			return (fatal_malloc("sysconf SC_PAGESIZE doesn't work"));
		data.size_area.tiny = round_page(AREA_TINY, data.pagesize);
		data.size_area.small = round_page(AREA_SMALL, data.pagesize);
		data.size_area.large = ALLOC_MAX_SIZE;
		data.size_zone.tiny = round_page(ZONE_TINY, data.pagesize);
		data.size_zone.small = round_page(ZONE_SMALL, data.pagesize);
		data.size_zone.large = ALLOC_MAX_SIZE;
		data.header_size = sizeof(t_memzone) + sizeof(t_area);
	}
	return (&data);
}

void	malloc_munmap_data(t_alloc *data)
{
	if (data->zone_tiny)
		munmap_zone(data, data->zone_tiny);
	if (data->zone_small)
		munmap_zone(data, data->zone_small);
	if (data->zone_large)
		munmap_zone(data, data->zone_large);
	if (munmap_syscall(data, data->pool.mem, data->pool.size) != 0)
		error_malloc("munmap of memory pool failed!");
	*data = (t_alloc){0};
}

static void	munmap_zone(t_alloc *data, t_list *list)
{
	t_memzone	*zone;
	uint32_t	size;

	while (list)
	{
		zone = (t_memzone *)list->content;
		size = zone->size;
		if (munmap_syscall(data, zone, size) != 0)
			error_malloc("munmap of zone failed!");
		list = list->next;
	}
}
