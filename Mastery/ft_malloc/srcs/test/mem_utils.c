/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:14:20 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/09 15:17:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/ft_malloc.h"

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

//always return alloc global data.
//if reset is true, they are set to default values
t_alloc	*_global_data(bool reset)
{
	static t_alloc	data;
	(void)reset;

	if (!data.pagesize)
	{
		data = (t_alloc){0};
		data.pagesize = sysconf(_SC_PAGE_SIZE);
		data.limits.tiny = round_page(ALLOC_TINY, data.pagesize);
		data.limits.small = round_page(ALLOC_SMALL, data.pagesize);
		data.limits.large = round_page(ALLOC_LARGE, data.pagesize);
		data.ptr_start = mmap(NULL, 10000000, PROT_RDWR, MAP_AP, 0, 0);
		data.ptr_curr = data.ptr_start;
		data.offset = data.pagesize;
		PRINT("START ADDRESS: %p\n", data.ptr_start);
	}
	if (!data.ptr_start)
		return (NULL);
	return (&data);
}
