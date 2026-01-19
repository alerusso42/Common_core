/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overload.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:22:49 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/20 00:22:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"
# include <malloc.h>

void 	*reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t	total;

	total = nmemb * size;
	if (total < nmemb || total < size)
	{
		WARNING("reallocarray: %u * %u overflows\n", nmemb, size);
		return (NULL);
	}
	return (realloc(ptr, total));
}

void	*memalign(size_t alignment, size_t size)
{
	if (alignment < sizeof(void *) || alignment & (alignment - 1) != 0)
	{
		WARNING("memalign: alignment %u must be pow of 2, >= sizeof(ptr)\n", \
		alignment);
		return (NULL);
	}
	size = (size + alignment - 1) & (alignment - 1);
	return (malloc(size));
}

void	*valloc(size_t size)
{
	return (malloc(size));
}

void	*pvalloc(size_t size)
{
	return (malloc(size));
}

void	*xmalloc(size_t size)
{
	return (malloc(size));
}
