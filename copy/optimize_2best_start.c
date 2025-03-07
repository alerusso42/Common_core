/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_2best_start.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:23:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 11:50:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	mark_best_start(t_stack *a, int current);
static int	check_one(t_stack *a, int current);

/*
	1)	Finds the half of the size of the stack;
	2)	If a number has to be pushed:

	-	If it's below half, its cost is the current index, order RA;
	-	If it's above half, its cost is index - half, order RRA.
*/
static void	find_rotation_order(t_stack *stack)
{
	int	half;
	int	index;
	int	cost;

	half = stack->size >> 1;
	index = stack->first - 1;
	cost = 0;
	stack->order = RA;
	while (++index != stack->last + 1)
	{
		if (stack->data[index].to_push == YES)
		{
			if (index < half)
			{
				cost = index;
				stack->furthest_position = index;
			}
			else if (cost * 2 < half - (index - half))
			{
				cost = half - (index - half);
				stack->furthest_position = index;
				stack->order = RRA;
			}
		}
	}
}

/*
	While there are numbers to push:

	1)	If you DON't have to push the number, do a RA or a RRA;
	2)	If you have to push, save the number, push the data, decrease
		the counter of numbers to push;
	3)	For every num, choose if it must be put below or above the
		medium area. See "choose medium area".
*/
void	move_unsorted_to_b(t_stack *a)
{
	int	num;

	if (a->size < 3)
		return ;
	while (a->nums_to_push)
	{
		if (a->data[a->first].to_push == YES)
		{
			num = a->data[a->first].n;
			pb();
			a->nums_to_push--;
			if ((a->order == RRA) && (a->nums_to_push != 0))
				rra();
			choose_medium_area(a, num);
		}
		else if (a->order == RRA)
			rra();
		else if (a->order == RA)
			ra();
	}
}

/*
	Best start finds:

	1)	The biggest sequence of crescent numbers in stack a;
	2)	The arithmetic medium of all numbers in stack a.

	It left on stack a the biggest sequence of already ordened number;
	while, in the stack b, push down the numbers above the medium,
	and puts top the numbers below the medium.
	Example:
	A			B
	8
	1
	3
	5
	4
	7
	6
	9
	2

	BIGGEST_SEQUENCE: 1 3 4 6 9
	MEDIUM: 45 / 9 = 5
	RESULT:
	A			B
	1			2
	3			5
	4			8
	6			7
	9			

	1)	For every num, we save in current_score the sequence length;
	2)	We save in current the num we are checking;
	3)	We save in record the highest score, in best its number;
	4)	In the end, we ma
*/
void	best_start(t_stack *a)
{
	int	best;
	int	current;
	int	record;
	int	current_score;

	current = a->first;
	best = 0;
	record = 0;
	while (current != a->last + 1)
	{
		current_score = check_one(a, current);
		if (current_score > record)
		{
			record = current_score;
			best = current;
		}
		++current;
	}
	mark_best_start(a, best);
}

/*
	Counts how many bigger numbers there are after current.
*/
static int	check_one(t_stack *a, int current)
{
	int	index;
	int	biggest;
	int	counter;

	biggest = a->data[current].n;
	index = current + 1;
	counter = 1;
	while (index != a->last + 1)
	{
		if (a->data[index].n > biggest)
		{
			biggest = a->data[index].n;
			++counter;
		}
		++index;
	}
	return (counter);
}

/*
	1)	We set to_push of every data to YES;
	2)	We set to_push of best to NO, and reduce the nbr
		of numbers to push;
	3)	For every number after best, if they are bigger,
		mark that they don't have to be pushed;
	4)	Find the best rotation order;
*/
static void	mark_best_start(t_stack *a, int current)
{
	int	index;
	int	biggest;

	index = -1;
	while (++index != a->last + 1)
	{
		a->data[index].to_push = YES;
		a->nums_to_push += 1;
	}
	biggest = a->data[current].n;
	a->data[current].to_push = NO;
	a->nums_to_push -= 1;
	index = current + 1;
	while (index != a->last + 1)
	{
		if (a->data[index].n > biggest)
		{
			biggest = a->data[index].n;
			a->data[index].to_push = NO;
			a->nums_to_push -= 1;
		}
		++index;
	}
	find_rotation_order(a);
}
