/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_3indexation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:01:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/03 11:24:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	override_nums_with_position_index(t_stack *a);
static void	bubble_sort_one(int current, t_stack *a);

void	indexation(t_stack *a)
{
	int	index;

	index = 0;
	while (index != a->size)
	{
		a->data[index].pos = index + 1;
		++index;
	}
	index = 0;
	while (index != a->size)
	{
		bubble_sort_one(index, a);
		++index;
	}
	if (a->switch_2_indexation == ON)
		override_nums_with_position_index(a);
}

static void	bubble_sort_one(int current, t_stack *a)
{
	int	index;

	index = current + 1;
	while (index != a->size)
	{
		if (a->data[current].n > a->data[index].n)
		{
			a->data[current].pos ^= a->data[index].pos;
			a->data[index].pos ^= a->data[current].pos;
			a->data[current].pos ^= a->data[index].pos;
		}
		++index;
	}
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
