/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:30:46 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/26 01:59:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

/*
static bool	pool_init(t_alloc *data, uint32_t pool_size);
static bool	pool_realloc(t_alloc *data, uint32_t new_size);
static void	pool_reassign(t_alloc *data, t_pool *pool, int64_t diff);

//used when a new mmap zone is created
//the list with all the zones is expanded
//memory needed by list is taken from the malloc memory pool
void	*pool_alloc(t_alloc *data, uint32_t len)
{
	uint32_t	size;
	uint32_t	new_size;

	if (!data->pool.mem)
	{
		if (pool_init(data, POOL_SIZE) != EXIT_SUCCESS)
			return (NULL);
	}
	size = data->pool.bytes + len;
	new_size = data->pool.size;
	if (size > new_size)
	{
		while (size > new_size)
			new_size <<= 1;
		if (pool_realloc(data, new_size) != EXIT_SUCCESS)
			return (NULL);
	}
	data->pool.bytes += len;
	data->pool.len += 1;
	PRINT("pool usage: new %u, total %u, left %u\n", len, data->pool.bytes, \
	data->pool.size - data->pool.bytes);
	return (data->pool.mem + data->pool.bytes - len);
}

//malloc memory pool initialization
static bool	pool_init(t_alloc *data, uint32_t pool_size)
{
	uint32_t	len;

	data->pool = (t_pool){0};
	len = round_page(pool_size, data->pagesize);
	data->pool.mem = mmap_syscall(data, len);
	if (!data->pool.mem)
		return (error_malloc("cannot init pool"), EXIT_FAILURE);
	data->pool.size = len;
	PRINT("pool init, len %d, ptr %p\n", len, data->pool.mem);
	return (EXIT_SUCCESS);
}

//expand malloc memory pool
static bool	pool_realloc(t_alloc *data, uint32_t new_size)
{
	t_pool	old_pool;

	old_pool = data->pool;
	PRINT("pool realloc, expanding from %d to %d\n", old_pool.size, new_size);
	if (pool_init(data, new_size) == EXIT_FAILURE)
		return (error_malloc("pool realloc failure"), EXIT_FAILURE);
	PRINT("Success! munmap of old pool...\n");
	ft_memcpy(data->pool.mem, old_pool.mem, old_pool.size);
	data->pool.bytes = old_pool.bytes;
	data->pool.len = old_pool.len;
	data->pool.size = new_size;
	pool_reassign(data, &data->pool, data->pool.mem - old_pool.mem);
	if (munmap_syscall(data, old_pool.mem, old_pool.size) != 0)
		return (error_malloc("pool: cannot free old pool"), EXIT_FAILURE);
	PRINT("Success!\n");
	return (EXIT_SUCCESS);
}

//updates old list ptr with new ones
static void	pool_reassign(t_alloc *data, t_pool *pool, int64_t diff)
{
	t_list		*list;
	t_memzone	*zone;

	list = (t_list *)pool->mem;
	for (uint32_t i = 0; i < pool->len; i++)
	{
		zone = ((t_memzone *)list->content);
		if (zone)
		{
			if (zone->ptr_node->next)
				list->next = ((void *)list->next) + diff;
			if (zone->ptr_node->prev)
				list->prev = ((void *)list->prev) + diff;
			zone->ptr_node = list;
			if (!list->prev)
			{
				if (zone->size == ZONE_TINY)
					data->zone_tiny = list;
				else if (zone->size == ZONE_SMALL)
					data->zone_small = list;
				else
					data->zone_large = list;
			}
		}
		list++;
	}
}
*/
