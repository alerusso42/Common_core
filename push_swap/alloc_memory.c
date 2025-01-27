/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:10:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/27 11:59:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*
	Alloc data for stack a and stack b.
	The stacks are passed as address.
	Data are alloc with ft_calloc.
	
	Size is the number of numbers that must be sorted.
	It will be multipled by 3 to be able to shift everything right or left.
	
	It fails if:
	
	SIZE_OVERFLOW: the size, multipled by 3, surpassed max int.
	STACK_CORRUPTION: address received is NULL. Something weird is going on.
	MALLOC_ERROR: if malloc fails. 
*/
int	alloc_data(t_stack **a, t_stack **b, int size)
{
	int	old_size;

	old_size = size;
	size = size * 3;
	if (size / old_size != 3)
		return (ER_SIZE_OVERFLOW);
	if ((!a) || (!b))
		return (ER_STACK_CORRUPTION);
	*a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*a)
		return (ER_MALLOC_ERROR);
	(*a)->data = (int *)ft_calloc(size, sizeof(int));
	if (!(*a)->data)
		return (ER_MALLOC_ERROR);
	*b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*b)
		return (ER_MALLOC_ERROR);
	(*b)->data = (int *)ft_calloc(size, sizeof(int));
	if (!(*b)->data)
		return (ER_MALLOC_ERROR);
	return (0);
}