/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:03:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/01 16:18:13 by alerusso         ###   ########.fr       */
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
	command_counter(PA);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		l_printf("Move number %d: pa;\n", a->moves_num);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (a->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("Move number %d: pa;\n", a->moves_num);
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
	command_counter(PB);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		l_printf("Move number %d: pb;\n", a->moves_num);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (a->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("Move number %d: pb;\n", a->moves_num);
}
