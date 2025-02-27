/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_3indexation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:01:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 10:20:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	override_nums_with_position_index(t_stack *a);

/*
	Assign "current_num_to_assign" to the current biggest num.
*/
static void	assign(t_stack *a, int biggest, int to_assign)
{
	int	index;

	index = a->first;
	while (index != a->last + 1)
	{
		if (biggest == a->data[index].n)
		{
			a->data[index].pos = to_assign;
			return ;
		}
		++index;
	}
}

/*
	What is indexation?

	Override every number with its position in the
	ordened stack.
	Example:
	50	--->	3
	30	--->	2
	20	--->	1	
	70	--->	4

	Very helpful for a lot of things.

	If switch indexation is ON, the function
	"override_nums_with_position_index(a)" replace
	every number of the stack with its position in 
	the ordened stack.
	Otherwise, the indexation value will be saved
	in a variable called .pos, saved in the data of
	every member of the array.

	Procedure:

	1)	Find the size of the stack a, and save it in "current_num_to_assign";
	2)	Find the biggest number of the stack a;
	3)	Assign "current_num_to_assign" to the biggest number of stack a;
	4)	Decrease one "current_num_to_assign";
	5)	Do this process for every num NOT already assigned;
	6)	If switch indexation is ON, apply the indexation to numbers.
*/
void	indexation(t_stack *a)
{
	int	biggest;
	int	current_number_to_assign;
	int	index;

	current_number_to_assign = a->size;
	while (current_number_to_assign != 0)
	{
		index = a->first;
		biggest = INT_MIN;
		while (index != a->last + 1)
		{
			if ((a->data[index].n > biggest) && (a->data[index].pos == 0))
				biggest = a->data[index].n;
			++index;
		}
		assign(a, biggest, current_number_to_assign);
		current_number_to_assign--;
	}
	if (a->switch_2_indexation == ON)
		override_nums_with_position_index(a);
}

/*
	For every data.n, assign its data.pos

	ez
*/
static void	override_nums_with_position_index(t_stack *a)
{
	int	index;

	index = 0;
	while (index != a->size)
	{
		a->data[index].n = a->data[index].pos;
		++index;
	}
}
