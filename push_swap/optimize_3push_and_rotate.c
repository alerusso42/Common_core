/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_3push_and_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:40:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/31 16:06:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*
	In this case, we need to check from the tails.
*/
static void	reverse_rotate(t_stack *a)
{
	static int	index;

	index = a->first;
	while ((index != a->last - 1) && (a->nums_to_push))
	{
		if (a->to_push[index])
		{
			pb();
			a->nums_to_push--;
			a->to_push[index] = 0;
		}
		else
			ra();
		++index;
	}
}

/*
	In this case, we need to check from the head.
*/
static void	normal_rotate(t_stack *a)
{
	static int	index;

	index = a->first;
	if (a->to_push[index] == 1)
	{
		pb();
		a->nums_to_push--;
		a->to_push[index] = 0;
	}
	index = a->last;
	while ((index != a->first - 1) && (a->nums_to_push))
	{
		if (a->to_push[index])
		{
			pb();
			a->nums_to_push--;
			a->to_push[index] = 0;
		}
		else
			rra();
		--index;
	}
}

void	push_and_rotate(t_stack *a)
{
	if (a->order == RA)
	{
		normal_rotate(a);
	}
	else
		reverse_rotate(a);
}