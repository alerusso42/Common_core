/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:15:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/11 14:50:04 by alerusso         ###   ########.fr       */
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
	static t_data	save;
	static t_data	temp;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (a->size <= 1)
		return ;
	save = a->data[a->first];
	a->data[a->first] = a->data[a->last];
	index = a->first - 1;
	while (++index != a->last)
	{
		temp = a->data[index + 1];
		a->data[index + 1] = save;
		save = temp;
	}
	if (a->block_print == ON)
		return ;
	command_counter(RRA);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		l_printf("Move number %d: rra;\n", a->moves_num);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (a->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("rra\n");
	//l_printf("rra\n");
}

void	rrb(void)
{
	static t_stack	*b;
	static int		index;
	static t_data	save;
	static t_data	temp;

	if (!b)
		b = store_stacks(NULL, GET_B);
	if (b->size <= 1)
		return ;
	save = b->data[b->first];
	b->data[b->first] = b->data[b->last];
	index = b->first - 1;
	while (++index != b->last)
	{
		temp = b->data[index + 1];
		b->data[index + 1] = save;
		save = temp;
	}
	if (b->block_print == ON)
		return ;
	b->moves_num += 1;
	command_counter(RRB);
	if (b->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (b->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("rrb\n");
	//l_printf("rrb\n");
}

void	rrr(void)
{
	static t_stack	*a;
	static t_stack	*b;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (!b)
		b = store_stacks(NULL, GET_B);
	a->block_print = ON;
	b->block_print = ON;
	rra();
	rrb();
	a->block_print = OFF;
	b->block_print = OFF;
	a->moves_num -= 1;
	command_counter(RRR);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		l_printf("Move number %d: rrr;\n", a->moves_num);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (a->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("rrr\n");
	//l_printf("rrr\n");
}
