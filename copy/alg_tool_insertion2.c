/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_tool_insertion2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:32:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 14:25:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	from_to(t_stack *from, t_stack *to);
static void	find_one(t_stack *from, t_stack *to, int current, int c_distance);
void		consider_rr(t_stack *from, t_stack *to, int current, \
	int c_distance);

/*REVIEW - 

	We need to find the cost to put every number FROM b TO a.
	So, if the stacks are not empty, we start the following process for 
	every num.

	1)	For every num, consider it its below or above half.
		If it's above, the cost related to B is the distance from the
		top of the array; else, is the distance from bottom.
	2)	Find the cost related to A, and sum it to the cost in B.
*/
void	update_cost(t_stack *a, t_stack *b)
{
	if ((a->size == 0) || (b->size == 0))
		return ;
	from_to(b, a);
}

static void	from_to(t_stack *from, t_stack *to)
{
	int	current;
	int	current_distance;

	current = from->first;
	current_distance = current - from->first;
	while (current != from->last + 1)
	{
		if (current < from->half)
		{
			current_distance = current - from->first;
			from->order = RB;
		}
		else
		{
			current_distance = (from->last - current) + 1;
			from->order = RRB;
		}
		find_one(from, to, current, current_distance);
		++current;
	}
}

/*REVIEW - 
	1)	Find the lowest_biggest of current;
	2)	Increase the index in which you find it to one;
	3)	If above half, the cost of A is the distance between the index
		of the target + 1 and the last member of the array.
		Else, the distance is the index less the first member of the 
		array;
	4)	Save this result in a temp variable;
	5)	Consider the double rotations, and sum the results.

*/
void	find_one(t_stack *from, t_stack *to, int current, int c_distance)
{
	int	index;

	index = to->first;
	while (index != to->last + 1)
	{
		if (from->data[current].lowest_bigger == INT_MAX)
		{
			if (to->data[index].n == to->biggest_num)
			{
				++index;
				break ;
			}
		}
		else if (to->data[index].n == from->data[current].lowest_bigger)
			break ;
		++index;
	}
	if (index >= to->half)
		index = (to->last - index) + 1;
	else
		index -= to->first;
	to->temp = index;
	consider_rr(from, to, current, c_distance);
}

/*REVIEW - 
	1)	If both stacks needs to be ordened in the same order, do one
		of the following operation.
		Else, sum the cost of A to the cost of B + 1 (the push);
	
	2)	If the cost of A is bigger than the cost of B,
		sum the cost of B to A - B;

		Else if the cost of B is bigger than the cost of A,
		sum the cost of A to B - A;

		Else sum the cost of A to the cost of B + 1 (the push).

*/
void	consider_rr(t_stack *from, t_stack *to, int current, int c_distance)
{
	int	cost_to;

	cost_to = to->temp;
	if ((cost_to >= to->half && from->order == RRB) || \
	(cost_to < to->half && from->order == RB))
	{
		if (cost_to > c_distance)
			from->data[current].cost = c_distance + (cost_to - c_distance) + 1;
		else if (cost_to < c_distance)
			from->data[current].cost = cost_to + (c_distance - cost_to) + 1;
		else
			from->data[current].cost = cost_to + c_distance + 1;
	}
	else
		from->data[current].cost = cost_to + c_distance + 1;
}
