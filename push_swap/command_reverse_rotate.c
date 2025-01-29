/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:15:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/29 15:13:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	rra(void)
{
	static t_stack	*a;
	static int		index;
	static int		temp;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (a->size <= 1)
		return ;
	temp = a->data[a->first];
	a->data[a->first] = a->data[a->last];
	index = a->first;
	while (index != a->last)
	{
		a->data[index + 1] = a->data[index + 1] ^ temp;
		temp = a->data[index + 1] ^ temp;
		a->data[index + 1] = a->data[index + 1] ^ temp;
		++index;
	}
	a->moves_num += 1;
	if (a->print_stuff == CORRECTION)
		l_printf("Move number %d: rra;\n", a->moves_num);
	else if (a->print_stuff == PRINT_MODIFICATIONS)
		print_stacks();
}

void	rrb(void)
{
	static t_stack	*b;
	static int		index;
	static int		temp;

	if (!b)
		b = store_stacks(NULL, GET_B);
	if (b->size <= 1)
		return ;
	temp = b->data[b->first];
	b->data[b->first] = b->data[b->last];
	index = b->first;
	while (index != b->last)
	{
		b->data[index + 1] = b->data[index + 1] ^ temp;
		temp = b->data[index + 1] ^ temp;
		b->data[index + 1] = b->data[index + 1] ^ temp;
		++index;
	}
	b->moves_num += 1;
	if (b->print_stuff == CORRECTION)
		l_printf("Move number %d: rrb;\n", b->moves_num);
	else if (b->print_stuff == PRINT_MODIFICATIONS)
		print_stacks();
}

void	rrr(void)
{
	static t_stack	*b;

	if (!b)
		b = store_stacks(NULL, GET_B);
	rra();
	rrb();
	b->moves_num -= 1;
	if (b->print_stuff == CORRECTION)
		l_printf("Move number %d: rrr;\n", b->moves_num);
	else if (b->print_stuff == PRINT_MODIFICATIONS)
		print_stacks();
}