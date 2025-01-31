/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_1push_guard.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:39:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/31 14:13:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	push_guard(int binary, t_stack *a)
{
	int	index;
	
	index = a->first;
	while ((index != a->last + 1) && ((a->data[index] & binary) != 0))
		++index;
	while ((index != a->last + 1) && ((a->data[index] & binary) != 1))
		++index;
	while (index != a->last + 1)
	{
		if ((a->data[index] & binary) == 0)
		{
			a->furthest_position = index;
			a->nums_to_push += 1;
			a->to_push[index] = 1;
		}
		++index;
	}
}