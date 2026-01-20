/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:21:25 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/20 12:39:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void 	*realloc(void *ptr, size_t size)
{
	t_alloc		*data;
	t_area		*area;
	void		*new_ptr;

	data = _global_data(false);
	switch (identify_area(data, ptr))
	{
		case (MEM_ALLOC) :
			area = ptr - sizeof(t_area);
			if (area->next >= size)
				return (ptr);
			new_ptr = malloc(size);
			ft_memcpy(new_ptr, ptr, size);
			return (free(ptr), new_ptr);
		case (MEM_FREED) :
			WARNING("$RFree: $Z%p $Ralready freed$Z\n");
			return (malloc(size));
		case (MEM_INTERNAL) :
			return (NULL);
		case (MEM_INVALID) :
			WARNING("Realloc: invalid ptr\n");
			new_ptr = malloc(size);
			ft_memcpy(new_ptr, ptr, size);
			return (free(ptr), new_ptr);
		case (MEM_ERROR) :
			return (NULL);
	}
	return (NULL);
	// if (data->error)
	// 	return (NULL);
	// if (ptr >= data->pool.mem && ptr <= data->pool.mem + data->pool.size)
	// 	return (NULL);
	// if (area->info > (MEM_FREED | MEM_SET))
	// {
	// 	WARNING("Realloc: ptr address is wrong. It will be replaced.\n");
	// 	new_ptr = malloc(size);
	// 	ft_memcpy(new_ptr, ptr, size);
	// 	free(ptr);
	// 	return (new_ptr);
	// }
	// if (area->next >= size)
	// 	return (ptr);
	// new_ptr = malloc(size);
	// ft_memcpy(new_ptr, ptr, size);
	// return (free(ptr), new_ptr);
}
