/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:14:20 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/11 05:04:38 by alerusso         ###   ########.fr       */
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

void	*error_malloc(char *s)
{
	err_printf("$RMalloc$Z:$R %s$Z\nPerror details: ", s);
	perror(NULL);
	return (NULL);
}

void	*fatal_malloc(char *s)
{
	t_alloc	*data;

	data = _global_data(false);
	err_printf("Malloc, fatal: %s\nPerror details: ", s);
	perror(NULL);
	malloc_munmap_data(data);
	data->error = true;
	return (NULL);
}

void	*mmap_syscall(t_alloc *data, uint32_t len)
{
	void	*ptr;

	len = round_page(len, data->pagesize);
	PRINT("$Ymmap$Z: allocating %d bytes\n", len);
	ptr = mmap(NULL, len, PROT_RDWR, MAP_AP, -1, 0);
	if (ptr == (void *)-1)
		return (NULL);
	if (data->ptr_max < ptr)
		data->ptr_max = ptr;
	if (data->ptr_min > ptr)
		data->ptr_min = ptr;
	data->bytes_alloc += len;
	if (DEBUG == true)
		VALGRIND_MALLOCLIKE_BLOCK(ptr, len, 0, false);
	return (ptr);
}

bool	munmap_syscall(t_alloc *data, void *ptr, uint32_t len)
{
	PRINT("$Ymunmap$Z: deallocating %d bytes from %p\n", len, ptr);
	if (munmap(ptr, len) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	data->bytes_freed += len;
	if (DEBUG == true)
		VALGRIND_FREELIKE_BLOCK(ptr, 0);
}
