/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:14:20 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/09 17:17:44 by alerusso         ###   ########.fr       */
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

	if (data.pagesize == 0 || reset)
	{
		data = (t_alloc){0};
		data.pagesize = sysconf(_SC_PAGESIZE);
		if (!data.pagesize)
			return (malloc_error("sysconf SC_PAGESIZE don't work"));
		data.limit.tiny = round_page(ALLOC_TINY, data.pagesize);
		data.limit.small = round_page(ALLOC_SMALL, data.pagesize);
		data.limit.large = ALLOC_MAX_SIZE;
	}
	return (&data);
}

void	*malloc_error(char *s)
{
	err_printf("$RMalloc$Z:$R %s$Z", s);
	return (NULL);
}
