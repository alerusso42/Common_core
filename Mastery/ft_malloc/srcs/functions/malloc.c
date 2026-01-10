/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:20:59 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/09 15:20:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void 	*malloc(uint32_t size)
{
	t_alloc	*data;

	data = _global_data(false);
	if (size > data->size_area.large)
		return (error_malloc("request size too large"));
}