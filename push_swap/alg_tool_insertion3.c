/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_tool_insertion3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:19:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:42:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	find_best_rotations(t_stack *a, t_stack *b, int lowest_index);

void	choose_cheepest(t_stack *a, t_stack *b)
{
	int	lowest_cost;
	int	lowest_index;
	int	index;

	lowest_cost = INT_MAX;
	index = b->first;
	lowest_index = b->first;
	while (index != b->last + 1)
	{
		if (b->data[index].cost < lowest_cost)
		{
			lowest_cost = b->data[index].cost;
			lowest_index = index;
		}
		++index;
	}
	b->data[lowest_index].to_push = YES;
	b->nums_to_push = 1;
	a->target_to_search = b->data[lowest_index].lowest_bigger;
	find_best_rotations(a, b, lowest_index);
}

void	find_best_rotations(t_stack *a, t_stack *b, int lowest_index)
{
	int	target_i;

	if (lowest_index < b->half + 1)
		b->order = RB;
	else
		b->order = RRB;
	target_i = a->first;
	while (target_i != a->last + 1)
	{
		if (b->data[lowest_index].lowest_bigger == INT_MAX)
		{
			if (a->data[target_i].n == a->biggest_num)
				break ;
		}
		else if (a->data[target_i].n == b->data[lowest_index].lowest_bigger)
			break ;
		++target_i;
	}
	if (target_i < a->half + 1)
		a->order = RA;
	else
		a->order = RRA;
}
