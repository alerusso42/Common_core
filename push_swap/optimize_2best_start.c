/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_2best_start.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:23:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/02 22:35:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	mark_best_start(t_stack *a, int current);
static int	check_one(t_stack *a, int current);

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
				cost =  half - (index - half);
				stack->furthest_position = index;
				stack->order = RRA;
			}
		}
	}
}

/*

*/
void	move_unsorted_to_b(t_stack *a)
{
	if (a->size < 3)//AGGIUNGERE CONTROLLO SU ORDINE
		return ;
	while (a->nums_to_push)
	{
		if (a->data[a->first].to_push == YES)
		{
			pb();
			a->nums_to_push--;
			if ((a->order == RRA) && (a->nums_to_push != 0))
				rra();
		}
		else if (a->order == RRA)
			rra();
		else if (a->order == RA)
			ra();
	}
}

void	best_start(t_stack *a)
{
	int	best;
	int	current;
	int	record;
	int	current_score;

	current = 0;
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