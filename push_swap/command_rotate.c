/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:15:29 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/30 09:37:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	ra(void)
{
	static t_stack	*a;
	static int		index;
	static int		temp;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (a->size <= 1)
		return ;
	temp = a->data[a->last];
	a->data[a->last] = a->data[a->first];
	index = a->last;
	while (index != a->first)
	{
		a->data[index - 1] = a->data[index - 1] ^ temp;
		temp = a->data[index - 1] ^ temp;
		a->data[index - 1] = a->data[index - 1] ^ temp;
		--index;
	}
	if (a->variable_1_mode == CORRECTION)
		l_printf("Move number %d: ra;\n", a->moves_num);
	else if (a->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
}

void	rb(void)
{
	static t_stack	*b;
	static int		index;
	static int		temp;

	if (!b)
		b = store_stacks(NULL, GET_B);
	if (b->size <= 1)
		return ;
	temp = b->data[b->last];
	b->data[b->last] = b->data[b->first];
	index = b->last;
	while (index != b->first)
	{
		b->data[index - 1] = b->data[index - 1] ^ temp;
		temp = b->data[index - 1] ^ temp;
		b->data[index - 1] = b->data[index - 1] ^ temp;
		--index;
	}
	if (b->variable_1_mode == CORRECTION)
		l_printf("Move number %d: rb;\n", b->moves_num);
	else if (b->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
}

void	rr(void)
{
	static t_stack	*b;

	if (!b)
		b = store_stacks(NULL, GET_B);
	ra();
	rb();
	b->moves_num -= 1;
	if (b->variable_1_mode == CORRECTION)
		l_printf("Move number %d: rr;\n", b->moves_num);
	else if (b->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
}
