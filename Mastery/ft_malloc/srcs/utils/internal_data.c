/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:54:33 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/27 12:46:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static void	munmap_zone(t_alloc *mem, t_list *list);

//always return alloc global data.
//if reset is true, they are set to default values.
//call thread_safe before this
t_alloc	*malloc_global_data()
{
	static t_alloc			data;

	if (data.error == false && data.pagesize == 0)
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

void	thread_safe(t_malloc_thread_flag flags)
{
	static pthread_mutex_t	mutex;
	bool					error;

	error = 0;
	if (flags & MALL_THREAD_CREATE)
	{
		if (pthread_mutex_init(&mutex, NULL) != 0)
			return (fatal_malloc("pthread_mutex_init failed"), (void)0);
	}
	if (flags & MALL_THREAD_DESTROY)
		error = pthread_mutex_destroy(&mutex);
	else if (flags & MALL_THREAD_UNLOCK)
		error = pthread_mutex_unlock(&mutex);
	else if (flags & MALL_THREAD_LOCK)
		error = pthread_mutex_lock(&mutex);
	if (error == true)
		return (fatal_malloc("pthread failure"), (void)0);
}

//munmap of all malloc data
void malloc_munmap_data(void)
{
	t_alloc	*data;

	thread_safe(MALL_THREAD_UNLOCK);
	thread_safe(MALL_THREAD_LOCK);
	data = malloc_global_data();
	PRINT("$Ymunmap all$Z: freeing allocator memory\n");
	if (data->zone_tiny)
		munmap_zone(data, data->zone_tiny);
	if (data->zone_small)
		munmap_zone(data, data->zone_small);
	if (data->zone_large)
		munmap_zone(data, data->zone_large);
	thread_safe(MALL_THREAD_UNLOCK);
	*data = (t_alloc){0};
}

//munmap an entire list of tiny/small/large area
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

static void __attribute__((destructor, used))	malloc_destructor(void)
{
	thread_safe(MALL_THREAD_LOCK);
	malloc_munmap_data();
	thread_safe(MALL_THREAD_DESTROY);
}

static void __attribute__((constructor, used))	malloc_constructor(void)
{
	thread_safe(MALL_THREAD_CREATE);
	malloc_global_data();
}
