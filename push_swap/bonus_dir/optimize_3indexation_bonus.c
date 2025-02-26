/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_3indexation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:01:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:44:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	override_nums_with_position_index(t_stack *a);

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
