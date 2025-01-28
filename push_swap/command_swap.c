/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:13:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/28 17:22:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	swap(int *n1, int *n2)
{
	static int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void	sa(void)
{
	static t_stack	*a;

	if (!a)
		a = store_stacks(NULL, GET_A);
	swap(a->data[0], a->data[1]);
}

void	sb(void)
{
	static t_stack	*b;

	if (!b)
		b = store_stacks(NULL, GET_B);
	swap(b->data[0], b->data[1]);
}

void	ss(void)
{
	sa();
	sb();
}