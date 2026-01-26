/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:54:33 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/26 04:13:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static void	munmap_zone(t_alloc *mem, t_list *list);

//always return alloc global data.
//if reset is true, they are set to default values
t_alloc	*_global_data(bool reset)
{
	static t_alloc	data;

	if (!data.error && (data.pagesize == 0 || reset))
	{
		data = (t_alloc){0};
		data.pagesize = sysconf(_SC_PAGESIZE);
		if (!data.pagesize)
			return (fatal_malloc("sysconf SC_PAGESIZE doesn't work"));
		data.header_size = sizeof(t_memzone) + sizeof(t_area);
		data.size_area.tiny = AREA_TINY;
		data.size_area.small = AREA_SMALL;
		data.size_area.large = ALLOC_MAX_SIZE;
		data.size_zone.tiny = ZONE_TINY - data.header_size;
		data.size_zone.small = ZONE_SMALL - data.header_size;
		data.size_zone.large = ALLOC_MAX_SIZE;
		data.ptr_max = 0x0;
		data.ptr_min = (void *)-1;
	}
	return (&data);
}

//munmap of all malloc data
void __attribute__((destructor, used))	malloc_munmap_data(void)
{
	t_alloc	*data;

	data = _global_data(false);
	PRINT("$Ymunmap all$Z: freeing allocator memory\n");
	if (data->zone_tiny)
		munmap_zone(data, data->zone_tiny);
	if (data->zone_small)
		munmap_zone(data, data->zone_small);
	if (data->zone_large)
		munmap_zone(data, data->zone_large);
	*data = (t_alloc){0};
}

//munmap an entire list of tiny/small/big area
static void	munmap_zone(t_alloc *data, t_list *list)
{
	t_memzone	*zone;
	uint32_t	size;
	t_list		*next;

	while (list)
	{
		zone = (t_memzone *)list->content;
		size = zone->size;
		next = list->next;
		if (munmap_syscall(data, zone, size) != 0)
			error_malloc("munmap of zone failed!");
		list = next;
	}
}
