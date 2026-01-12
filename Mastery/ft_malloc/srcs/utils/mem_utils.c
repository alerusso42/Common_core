/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:14:20 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/12 22:32:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

/*ANCHOR - round_page
round n to a multiple of pagesize. The round is for excess.

n + pagesize - 1 & ~(pagesize - 1)
EXAMPLE
n = 250				{00000000001111110}
pagesize = 4096 		{00001000000000000}
pagesize - 1 = 4095	{00000111111111111}
1)255 + 4096 - 1 = 4320	{00001000011100000}
2)~(pagesize-1) = ~4095 {11110000000000000}
3)4320 & ~4095 = 4096	{11110000000000000}

4320 -->	{00001000011100000}
~4095 -> 	{11110000000000000}
4096 -->	{11110000000000000}

this works only if pagesize is a power of 2
*/
int	round_page(int n, int pagesize)
{
	return ((n + pagesize - 1) & ~(pagesize - 1));
}

uint32_t	align_addr(void *ptr)
{
	uintptr_t	addr;

	addr = ptr;
	return (ALIGN - (addr % ALIGN));
}

void	*error_malloc(char *s)
{
	static bool	recursion_guard;

	if (recursion_guard == true)
	{
		recursion_guard = false;
		return (NULL);
	}
	err_printf("$RMalloc$Z:$R %s$Z\nPerror details: ", s);
	recursion_guard = true;
	perror(NULL);
	recursion_guard = false;
	return (NULL);
}

void	*fatal_malloc(char *s)
{
	static bool	recursion_guard;
	t_alloc	*data;

	if (recursion_guard == true)
	{
		recursion_guard = false;
		return (NULL);
	}
	data = _global_data(false);
	err_printf("Malloc, fatal: %s\nPerror details: ", s);
	recursion_guard = true;
	perror(NULL);
	recursion_guard = false;
	malloc_munmap_data(data);
	data->error = true;
	return (NULL);
}

void	*mmap_syscall(t_alloc *data, uint32_t len)
{
	void	*ptr;

	len = round_page(len, data->pagesize);
	PRINT("$Ymmap$Z: allocating %u bytes: ", len);
	ptr = mmap(NULL, len, PROT_RDWR, MAP_AP, -1, 0);
	if (ptr == (void *)-1)
		return (NULL);
	if (DEBUG_FLAG)
		ft_printf("$B%p$Z\n", ptr);
	if (data->ptr_max < ptr)
		data->ptr_max = ptr;
	if (data->ptr_min > ptr)
		data->ptr_min = ptr;
	data->bytes_alloc += len;
	if (DEBUG_FLAG == true)
		VALGRIND_MALLOCLIKE_BLOCK(ptr, len, 0, false);
	return (ptr);
}

bool	munmap_syscall(t_alloc *data, void *ptr, uint32_t len)
{
	PRINT("$Ymunmap$Z: deallocating %d bytes from $B%p$Z\n", len, ptr);
	if (munmap(ptr, len) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	data->bytes_freed += len;
	if (DEBUG_FLAG == true)
		VALGRIND_FREELIKE_BLOCK(ptr, 0);
	return (EXIT_SUCCESS);
}
