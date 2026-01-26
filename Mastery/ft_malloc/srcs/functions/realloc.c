/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:21:25 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/26 15:20:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static inline void	*expand_mem(void *ptr, size_t size);

void 	*realloc(void *ptr, size_t size)
{
	t_alloc		*data;
	t_area		*area;

	data = _global_data();
	switch (identify_area(data, ptr))
	{
		case (MEM_ALLOC) :
			area = ptr - sizeof(t_area);
			if (area->next >= size)
				return (ptr);
			return (expand_mem(ptr, size));
		case (MEM_FREED) :
			WARNING("$RRealloc: $Z%p $Ralready freed$Z\n");
			return (malloc(size));
		case (MEM_INVALID) :
			WARNING("$RRealloc: $Zinvalid ptr\n");
			return (expand_mem(ptr, size));
		case (MEM_NO_HEAP) :
			return (WARNING("$RRealloc: $Z%p$R is not a heap ptr$Z\n"), NULL);
		case (MEM_ERROR) :
			return (NULL);
	}
	return (NULL);
}

static inline void	*expand_mem(void *ptr, size_t size)
{
	void		*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
		return (free(ptr), fatal_malloc("Realloc failure"));
	ft_memcpy(new_ptr, ptr, size);
	return (free(ptr), new_ptr);
}
