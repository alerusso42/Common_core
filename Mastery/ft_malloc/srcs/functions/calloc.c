/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:21:17 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/20 00:38:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void 	*calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

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
	((t_area *)ptr - 1)->info |= MEM_SET;
	return (ptr);
}
