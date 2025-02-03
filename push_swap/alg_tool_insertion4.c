/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_tool_insertion4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:52:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/03 19:37:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static char	find_next_rotation_a(t_stack *a)
{
	if (a->target_to_search == INT_MAX)
	{
		if (a->data[a->first].n == a->biggest_num)
			return (NO);
	}
	if (a->data[a->first].n == a->target_to_search)
		return (NO);
	if (a->order == RA)
		return (RA);
	return (RRA);
}

static char	find_next_rotation_b(t_stack *b)
{
	if (b->data[b->first].to_push == YES)
		return (NO);
	if (b->order == RB)
		return (RB);
	return (RRB);
}

static int	ready_to_push(t_stack *a, t_stack *b)
{
	if (b->data[b->first].to_push == NO)
		return (NO);
	if (b->data[b->first].lowest_bigger == INT_MAX)
	{
		if (a->data[a->first].n == a->biggest_num)
			return (YES);
		return (NO);
	}
	if (a->data[a->first].n == b->data[b->first].lowest_bigger)
		return (YES);
	return (NO);
}

static void	separate_rotation(char a_order, char b_order)
{
	if (a_order != NO)
	{
		if (a_order == RA)
			ra();
		else
			rra();
	}
	if (b_order != NO)
	{
		if (b_order == RB)
			rb();
		else
			rrb();
	}
}

void	push_one(t_stack *a, t_stack *b)
{
	char	a_order;
	char	b_order;

	while (b->nums_to_push != 0)
	{
		a_order = find_next_rotation_a(a);
		b_order = find_next_rotation_b(b);
		if (ready_to_push(a, b) == YES)
		{
			b->data[b->first].to_push = NO;
			b->nums_to_push -= 1;
			pa();
		}
		else if ((a_order == RA) && (b_order == RB))
			rr();
		else if ((a_order == RRA) && (b_order == RRB))
			rrr();
		else
		{
			separate_rotation(a_order, b_order);
		}
	}
}