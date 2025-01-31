/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_2find_rotate_order.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:41:41 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/31 12:51:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	find_rotate_order(t_stack *a)
{
	int	half;

	half = a->size / 2;
	if ((half != 0) && (half % 2 == 0))
		half -= 1;
	if (a->furthest_position >= half)
		a->order = RRA;
	else
		a->order = RA;
}