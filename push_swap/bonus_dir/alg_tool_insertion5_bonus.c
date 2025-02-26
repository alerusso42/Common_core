/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_tool_insertion5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:24:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:42:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

int	find_shortest_value(t_stack *a)
{
	int	index;
	int	shortest_value;
	int	shortest_index;

	index = a->first;
	shortest_value = INT_MAX;
	shortest_index = index;
	while (index != a->last + 1)
	{
		if (a->data[index].n < shortest_value)
		{
			shortest_value = a->data[index].n;
			shortest_index = index;
		}
		++index;
	}
	return (shortest_index);
}

void	final_rotation(t_stack *a)
{
	int	shortest;

	shortest = find_shortest_value(a);
	find_half(a, NULL);
	if (shortest < a->half)
		a->order = RA;
	else
		a->order = RRA;
	a->data[shortest].to_push = YES;
	a->nums_to_push += 1;
	while (a->nums_to_push != 0)
	{
		if (a->data[a->first].to_push == YES)
		{
			a->data[a->first].to_push = NO;
			a->nums_to_push--;
		}
		else if (a->order == RA)
			ra();
		else
			rra();
	}
}
