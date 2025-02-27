/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:57:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 12:43:21 by alerusso         ###   ########.fr       */
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
	switch_data(&a->data[a->first], &a->data[a->first + 1]);
	if (a->block_print == ON)
		return ;
	command_counter(SA);
	l_printf("sa\n");
}

void	sb(void)
{
	static t_stack	*b;

	if (!b)
		b = store_stacks(NULL, GET_B);
	if (b->size <= 1)
		return ;
	switch_data(&b->data[b->first], &b->data[b->first + 1]);
	if (b->block_print == ON)
		return ;
	command_counter(SB);
	l_printf("sb\n");
}

void	ss(void)
{
	static t_stack	*a;
	static t_stack	*b;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (!b)
		b = store_stacks(NULL, GET_B);
	a->block_print = ON;
	b->block_print = ON;
	sa();
	sb();
	a->block_print = OFF;
	b->block_print = OFF;
	command_counter(SS);
	l_printf("ss\n");
}
