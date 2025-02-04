/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_tool_insertion2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:32:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:59:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	from_to(t_stack *from, t_stack *to);
static void	find_one(t_stack *from, t_stack *to, int current, int c_distance);

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
			current_distance = current - from->first;
		else
			current_distance = (from->last - current) + 1;
		find_one(from, to, current, current_distance);
		++current;
	}
}

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
	from->data[current].cost = index + c_distance + 1;
}
