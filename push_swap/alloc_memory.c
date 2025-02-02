/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:10:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/02 18:33:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

t_stack	*store_stacks(t_stack *stack, int mode)
{
	static t_stack	*a;
	static t_stack	*b;

	if (mode == FILL_A)
	{
		a = stack;
		return (NULL);
	}
	if (mode == FILL_B)
	{
		b = stack;
		return (NULL);
	}
	if (mode == GET_A)
	{
		return (a);
	}
	if (mode == GET_B)
	{
		return (b);
	}
	return (NULL);
}

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
	if (size == INT_MAX)
		return (ER_SIZE_OVERFLOW);
	if ((!a) || (!b))
		return (ER_STACK_CORRUPTION);
	*a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*a)
		return (ER_MALLOC_ERROR);
	(*a)->data = (t_data *)ft_calloc(size + 1, sizeof(t_data));
	if (!(*a)->data)
		return (ER_MALLOC_ERROR);
	*b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*b)
		return (ER_MALLOC_ERROR);
	(*b)->data = (t_data *)ft_calloc(size, sizeof(t_data));
	if (!(*b)->data)
		return (ER_MALLOC_ERROR);
	(*a)->command_list = (char *)ft_calloc(ENVISIONED_MOVES_NUM, sizeof(char));
	if (!(*a)->command_list)
		return (ER_MALLOC_ERROR);
	(*a)->command_list_size = ENVISIONED_MOVES_NUM;
	(*a)->command_list_length = 0;
	return (0);
}