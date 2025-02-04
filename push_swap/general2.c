/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:11:23 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:43:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	set_data_to_zero(t_stack *a, t_stack *b)
{
	int	index;

	index = a->first;
	while (index != a->last + 1)
	{
		a->data[index].to_push = NO;
		++index;
	}
	index = b->first;
	while (index != b->last + 1)
	{
		b->data[index].to_push = NO;
		++index;
	}
}
