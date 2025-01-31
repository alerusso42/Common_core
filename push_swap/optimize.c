/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:49:23 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/31 12:51:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	optimize(int binary)
{
	static t_stack	*a;
	static int		index;

	if (!a)
		a = store_stacks(NULL, GET_A);
	push_guard(binary, a);
	find_rotate_order(a);
	index = 0;
	while (index != (a->size + a->first) + 1)
	{
		a->to_push[index++] = 0;
	}
	a->furthest_position = 0;
	a->nums_to_push = 0;
}