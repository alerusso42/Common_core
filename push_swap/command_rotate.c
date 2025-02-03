/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:15:29 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/03 19:42:53 by alerusso         ###   ########.fr       */
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
	static t_data	save;
	static t_data	temp;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (a->size <= 1)
		return ;
	save = a->data[a->last];
	a->data[a->last] = a->data[a->first];
	index = a->last + 1;
	while (--index != a->first)
	{
		temp = a->data[index - 1];
		a->data[index - 1] = save;
		save = temp;
	}
	command_counter(RA);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		l_printf("Move number %d: ra;\n", a->moves_num);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (a->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("Move number %d: ra;\n", a->moves_num);
}

void	rb(void)
{
	static t_stack	*b;
	static int		index;
	static t_data	save;
	static t_data	temp;

	if (!b)
		b = store_stacks(NULL, GET_B);
	if (b->size <= 1)
		return ;
	save = b->data[b->last];
	b->data[b->last] = b->data[b->first];
	index = b->last + 1;
	while (--index != b->first)
	{
		temp = b->data[index - 1];
		b->data[index - 1] = save;
		save = temp;
	}
	command_counter(RB);
	if (b->variable_1_mode == PRINT_MODIFICATIONS)
		l_printf("Move number %d: rb;\n", b->moves_num);
	if (b->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (b->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("Move number %d: rb;\n", b->moves_num);
}

void	rr(void)
{
	static t_stack	*a;

	if (!a)
		a = store_stacks(NULL, GET_A);
	ra();
	rb();
	a->moves_num -= 2;
	command_counter(RR);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		l_printf("Move number %d: rr;\n", a->moves_num);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (a->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("Move number %d: rr;\n", a->moves_num);
}
