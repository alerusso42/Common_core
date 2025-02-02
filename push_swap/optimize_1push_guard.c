/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_1push_guard.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:39:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/02 12:39:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	add_one(t_stack *a, int index)
{
	a->furthest_position = index;
	a->nums_to_push += 1;
	a->to_push[index] = 1;
}

void	push_guard(int binary, t_stack *a)
{
	int	index;
	int	count;

	count = count_zero_bits(binary, a);
	if ((count == 0) || (count == a->size))
	{		
		return ;
	}
	index = a->first;
	while (index != a->last + 1)
	{
		if (!(a->data[index] & binary))
		{
			add_one(a, index);
		}
		++index;
	}
}