/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_4medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:57:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 10:28:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	find_medium(t_stack *a);

/*
	This function choose to put the number below or above the half of the
	b stack.

	It does it by calculating the medium between all number.
*/
void	choose_medium_area(t_stack *a, int num)
{
	if (a->medium == 0)
		find_medium(a);
	if (num > a->medium)
		rb();
}

/*
	Finds the medium between all numbers.
*/
static void	find_medium(t_stack *a)
{
	int	i;

	i = 0;
	while (i != a->size)
	{
		a->medium += a->data[a->first + i].n;
		++i;
	}
	a->medium /= a->size;
}
