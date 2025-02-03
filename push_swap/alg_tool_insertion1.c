/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_tool_insertion1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:29:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/03 18:09:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	from_to(t_stack *from, t_stack *to);
static void	find_one(t_stack *from, t_stack *to, int current);
static void	find_biggest_in_stack_to(t_stack *to);

/*
	Find smallest bigger find the best place to insert
	a number.

	In particular, it search for the shortest bigger
	number.

	What the heck does it mean?
	Example:

	017		016
	002		-22
	042		040
	-15		060

STACK A		STACK B

We need to insert the number from stack B to stack A.
We start from 16: when do we put it?
Simple: below 17, the shortest bigger number! 
		that's because, if we put it below 42 it would
		not be sorted, same thing for 2.

	This function does exactly this job: given a
	stack "from" to put to another stack "to" (from, to),
	it finds the insertion, like in a puzzle.

NOTE: 	for 60 in stack b there are no sh. bigger number:
		therefore, the program assign INT_MAX as 
		shorter bigger number, to remember it has to be
		put above the biggest in stack a (42).

*/
void	find_smallest_bigger(t_stack *a, t_stack *b)
{
	if ((a->size == 0) || (b->size == 0))
		return ;
	from_to(b, a);
}

static void	find_one(t_stack *from, t_stack *to, int current)
{
	int	index;

	index = to->first;
	while (index != to->last + 1)
	{
		if (to->data[index].n > from->data[current].n)
			if (from->data[current].lowest_bigger > to->data[index].n)
				from->data[current].lowest_bigger = to->data[index].n;
		++index;
	}
}

static void	from_to(t_stack *from, t_stack *to)
{
	int	current;

	current = from->first;
	while (current != from->last + 1)
	{
		from->data[current].lowest_bigger = INT_MAX;
		++current;
	}
	current = from->first;
	while (current != from->last + 1)
	{
		find_one(from, to, current);
		++current;
	}
	find_biggest_in_stack_to(to);
}

static void	find_biggest_in_stack_to(t_stack *to)
{
	int	index;

	index = to->first;
	to->biggest_num = INT_MIN;
	while (index != to->last + 1)
	{
		if (to->data[index].n > to->biggest_num)
			to->biggest_num = to->data[index].n;
		++index;
	}
}
