/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:48:20 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/13 11:15:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

t_area	*bytelst_next(t_area *curr)
{
	t_area	*area;

	if (!curr->next)
		return (NULL);
	area = ((void *)curr) + curr->next;
	if (!area->next)
		return (NULL);
	return (area);
}

t_area	*bytelst_prev(t_area *curr)
{
	if (!curr->prev)
		return (NULL);
	return (((void *)curr) - curr->prev);
}

t_memzone	*bytelst_head(t_area *curr)
{
	while (curr->prev)
		curr = ((void *)curr) - curr->prev;
	return (((void *)curr) - sizeof(t_memzone));
}

/*
BEFORE:			   <!!!!!!	!!!!!!>
		Node 1		Node 2	Node 3	Node 4
next|	25			11		109			0	
prev|	0			25		11			109	
info|	alloc.		freed	freed		alloc.
AFTER:			   <!!!!!!>
		Node 1		Node 2	Node 3
next|	25			120		0
prev|	0			25		120
info|	alloc.		freed	alloc.
*/
t_area	*bytelst_merge(t_area *left, t_area *right)
{
	if (!left || !right)
		return (error_malloc("bytelst_merge args error"));
	left->next += right->next;
	right = bytelst_next(right);
	if (right)
		right->prev = left->next;
	return (left);
}

/*
BEFORE:			   <!!!!!!>
		Node 1		Node 2	Node 3
next|	25			120		0
prev|	0			25		120
info|	alloc.		freed	alloc.
AFTER:			   <!!!!!!	!!!!!!>
		Node 1		Node 2	Node 3	Node 4
next|	25			11		109			0	
prev|	0			25		11			109	
info|	alloc.		freed	freed		alloc.
*/
t_area	*bytelst_split(t_area *area, t_bytelist size)
{
	t_area	*next;
	t_area	*new;
	int		alignment;

	if (!area || !size)
		return (error_malloc("bytelst_split args error"));
	next = bytelst_next(area);
	new = ((void *)area) + size;
	alignment = align_addr(new);
	new = ((void *)(new)) + alignment;
	size += alignment;
	new->info = MEM_FREED;
	new->prev = size;
	new->next = area->next - size;
	area->next = size;
	if (next)
	{
		next->prev = new->next;
	}
	return (new);
}
