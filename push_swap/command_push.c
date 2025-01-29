/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:03:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/29 15:12:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	pa(void)
{
	static t_stack	*a;
	static t_stack	*b;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (!b)
		b = store_stacks(NULL, GET_B);
	if (b->size == 0)
		return ;
	a->first -= 1;
	a->size += 1;
	a->data[a->first] = b->data[b->first];
	b->data[b->first] = 0;
	b->first += 1;
	b->size -= 1;
	a->moves_num += 1;
	if (a->print_stuff == CORRECTION)
		l_printf("Move number %d: pa;\n", a->moves_num);
	else if (a->print_stuff == PRINT_MODIFICATIONS)
		print_stacks();
}

void	pb(void)
{
	static t_stack	*a;
	static t_stack	*b;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (!b)
		b = store_stacks(NULL, GET_B);
	if (a->size == 0)
		return ;
	b->first -= 1;
	b->size += 1;
	b->data[b->first] = a->data[a->first];
	a->data[a->first] = 0;
	a->first += 1;
	a->size -= 1;
	a->moves_num += 1;
	if (a->print_stuff == CORRECTION)
		l_printf("Move number %d: pb;\n", a->moves_num);
	else if (a->print_stuff == PRINT_MODIFICATIONS)
		print_stacks();
}
