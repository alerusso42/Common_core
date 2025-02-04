/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:57:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:57:49 by alerusso         ###   ########.fr       */
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
	command_counter(SA);
}

void	sb(void)
{
	static t_stack	*b;

	if (!b)
		b = store_stacks(NULL, GET_B);
	if (b->size <= 1)
		return ;
	switch_data(&b->data[b->first], &b->data[b->first + 1]);
	command_counter(SB);
}

void	ss(void)
{
	static t_stack	*a;

	if (!a)
		a = store_stacks(NULL, GET_B);
	sa();
	sb();
	a->moves_num -= 2;
	command_counter(SS);
}
