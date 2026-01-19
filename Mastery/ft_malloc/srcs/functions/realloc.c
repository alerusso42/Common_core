/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:21:25 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/20 00:45:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void 	*realloc(void *ptr, size_t size)
{
	t_alloc		*data;
	t_area		*area;
	void		*new_ptr;

	if (!ptr)
		return ;
	data = _global_data(false);
	if (data->error)
		return ;
	if (ptr >= data->pool.mem && ptr <= data->pool.mem + data->pool.size)
		return ;
	area = ptr - sizeof(t_area);
	if (area->info > MEM_FREED | MEM_SET)
	{
		WARNING("Realloc: ptr address is wrong. It will be replaced.\n");
		new_ptr = malloc(size);
		ft_memcpy(new_ptr, ptr, size);
		free_correct_area(data, ptr);
		return (new_ptr);
	}
	if (area->next >= size)
		return (ptr);
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	return (free(ptr), new_ptr);
}
