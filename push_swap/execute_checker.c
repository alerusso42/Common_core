/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:05:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/29 12:34:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

int	checker(void)
{
	static t_stack *a;
	static int		index;

	if (a == NULL)
		a = store_stacks(NULL, GET_A);
	index = 0;
	while (index != a->size - 1)
	{
		if (a->data[index] > a->data[index + 1])
		{
			l_printf("\nYou still have to sort something... try harder.\n");
			return (1);
		}
		++index;
	}
	l_printf("\nEverything sorted in %d moves, GG!\n", a->moves_num);
	return (0);
}	