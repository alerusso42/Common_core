/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:03:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 12:58:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	set_to_zero(t_data *data)
{
	data->cost = 0;
	data->lowest_bigger = 0;
	data->n = 0;
	data->to_push = NO;
}

/*REVIEW - 

	1)	If the size of the b stack is 0, stop;
	2)	Decrease the first member of a to one;
	3)	Increase the size of a to one;
	4)	Copy the top of b in the NEW top of a;
	5)	Erase the top of b;
	6)	Increase the first member of a to one;
	7)	Decrease the size of a to one;
*/
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
	set_to_zero(&b->data[b->first]);
	b->first += 1;
	b->size -= 1;
	command_counter(PA);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		l_printf("Move number %d: pa;\n", a->moves_num);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (a->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("pa\n");
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
	set_to_zero(&a->data[a->first]);
	a->first += 1;
	a->size -= 1;
	command_counter(PB);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		l_printf("Move number %d: pb;\n", a->moves_num);
	if (a->variable_1_mode == PRINT_MODIFICATIONS)
		print_stacks();
	else if (a->variable_1_mode == PRINT_FINAL_RESULT)
		l_printf("pb\n");
}
