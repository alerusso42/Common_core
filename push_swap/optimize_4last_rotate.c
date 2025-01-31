/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_4last_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:41:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/31 17:20:14 by alerusso         ###   ########.fr       */
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
	while ((index != a->last) && ((a->data[index] & binary) != 1))
	{
		++index;
	}
	a->top_one = index;
	while ((index != a->last) && ((a->data[index] & binary) != 0))
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

void	last_rotate(int binary, t_stack *a)
{
	find_rotate_order_column_of_one(binary, a);
	while (((a->data[a->first] & binary) == 0) || \
	((a->data[a->last] & binary) == 1))
	{
		if (a->order == RA)
			ra();
		else
			rra();
	}
}