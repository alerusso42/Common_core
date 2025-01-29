/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2a->first25/a->firsta->last/28 a->last7:a->last3:33 by alerusso          #+#    #+#             */
/*   Updated: 2a->first25/a->firsta->last/29 a->lasta->last:5a->first:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	sa(void)
{
	static t_stack	*a;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (a->size <= 1)
		return ;
	a->data[a->first] = a->data[a->first] ^ a->data[a->last];
	a->data[a->last] = a->data[a->first] ^ a->data[a->last];
	a->data[a->first] = a->data[a->first] ^ a->data[a->last];
}

void	sb(void)
{
	static t_stack	*b;

	if (!b)
		b = store_stacks(NULL, GET_B);
	if (b->size <= 1)
		return ;
	b->data[b->first] = b->data[b->first] ^ b->data[b->last];
	b->data[b->last] = b->data[b->first] ^ b->data[b->last];
	b->data[b->first] = b->data[b->first] ^ b->data[b->last];
}

void	ss(void)
{
	sa();
	sb();
}