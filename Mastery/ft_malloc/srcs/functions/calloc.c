/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:21:17 by alerusso          #+#    #+#             */
/*   Updated: 2026/03/13 13:47:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

/// @brief returns ptr with malloc. Size is nmemb * size
/// @param nmemb number of elements to allocate
/// @param size size in bytes of each element to allocate
/// @return aligned ptr of heap memory, NULL if an error occurred
void 	*calloc(size_t nmemb, size_t size)
{
	size_t		total;
	void		*ptr;
	uintptr_t	area;

	total = nmemb * size;
	if (!total)
	{
		WARNING("calloc: %u-%u: EINVAL\n", nmemb, size);
		return (NULL);
	}	
	if (total < nmemb || total < size)
	{
		WARNING("calloc: %u * %u overflows\n", nmemb, size);
		return (NULL);
	}
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	area = ((uintptr_t)ptr) - sizeof(t_area);
	((t_area *)area)->info |= MEM_SET;
	return (ptr);
}
