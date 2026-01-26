/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:14:20 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/26 05:24:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

/*ANCHOR - round_page
round n to a multiple of pagesize. The round is for excess.

n + pagesize - 1 & ~(pagesize - 1)
EXAMPLE
n = 250					{00000000001111110}
pagesize = 4096 		{00001000000000000}
pagesize - 1 = 4095		{00000111111111111}
1)255 + 4096 - 1 = 4315	{00001000011011011}
2)~(pagesize-1) = ~4095 {11110000000000000}
3)4320 & ~4095 = 4096	{11110000000000000}

4315 -->	{00001000011011011}
~4095 -> 	{11110000000000000}
4096 -->	{11110000000000000}

this works only if pagesize is a power of 2
*/
inline int	round_page(int n, int pagesize)
{
	return ((n + pagesize - 1) & ~(pagesize - 1));
}

//used to aligned a pointer to max_align_t
//same logic as round_page
//returns aligned_ptr - ptr
inline uint32_t	align_addr(void *ptr)
{
	return (ALIGN - (((uintptr_t)ptr) % ALIGN));
}

//mmap a new zone with len bytes
//updates internal malloc data
void	*mmap_syscall(t_alloc *data, uint32_t len)
{
	void	*ptr;

	len = round_page(len, data->pagesize);
	PRINT("$Ymmap$Z: allocating %u bytes: ", len);
	ptr = mmap(NULL, len, PROT_RDWR, MAP_AP, -1, 0);
	if (ptr == (void *)-1)
		return (fatal_malloc("mmap failure"));
	if (PRINT_FLAG)
		ft_printf("New ptr $B%p$Z created\n", ptr);
	if (data->ptr_max < ptr)
		data->ptr_max = ptr + len;
	if (data->ptr_min > ptr)
		data->ptr_min = ptr;
	data->bytes_alloc += len;
	if (DEBUG_FLAG == true)
		VALGRIND_MALLOCLIKE_BLOCK(ptr, len, 0, false);
	return (ptr);
}

//munmap an old zone with len bytes
//updates internal malloc data
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

//identify where a pointer given by user comes from
//invalid ptr may cause crash if not on heap/stack
uint32_t	identify_area(t_alloc *data, void *ptr)
{
	t_area	*area;

	if (data->error || !ptr)
		return (MEM_ERROR);
	if (ptr < data->ptr_min || ptr > data->ptr_max)
		return (MEM_NO_HEAP);
	area = ptr - sizeof(t_area);
	if ((area->info & (~MEM_FLAGS)) != 0)
		return (MEM_INVALID);
	else if (area->info &= MEM_FREED)
		return (MEM_FREED);
	return (MEM_ALLOC);
}
