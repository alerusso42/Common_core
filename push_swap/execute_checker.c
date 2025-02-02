/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:05:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/02 18:27:54 by alerusso         ###   ########.fr       */
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
		if (a->data[index].n > a->data[index + 1].n)
		{
			return (1);
		}
		++index;
	}
	return (0);
}	