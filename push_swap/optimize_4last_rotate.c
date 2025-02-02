/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_4last_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:41:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/01 14:29:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	find_rotate_order_column_of_one(int binary, t_stack *a)
{
	static int	index;

	index = a->first;
	while ((index != a->last) && (!(a->data[index] & binary)))
	{
		++index;
	}
	a->top_one = index;
	while ((index != a->last) && (a->data[index] & binary))
	{
		++index;
	}
	if (index != 0)
		a->bottom_one = index - 1;
	if ((a->top_one - a->first) < (a->last - a->bottom_one))
		a->order = RA;
	else
		a->order = RRA;
}

void	repush_in_a()
{
	static t_stack	*b;

	if (!b)
		b = store_stacks(NULL, GET_B);
	while (b->size != 0)
			pa();
}

void	last_rotate(int binary, t_stack *a)
{
	int	count;
	
	find_rotate_order_column_of_one(binary, a);
	count = count_one_bits(binary, a);
	if ((count == a->size) || (count == 0))
		return ;
	while ((a->data[a->first] & binary) || \
	(!(a->data[a->last] & binary)))
	{
		if (a->order == RA)
			ra();
		else
			rra();
	}
}