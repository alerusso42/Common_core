/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:07:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/29 14:59:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	print_stacks()
{
	static int				index;
	static int		print_num;
	static t_stack	*a;
	static t_stack	*b;
	static int		total_size;

	if (a == NULL)
		a = store_stacks(NULL, GET_A);
	if (b == NULL)
		b = store_stacks(NULL, GET_B);
	index = 0;
	total_size = a->size + b->size;
	l_printf("\nPrint number %d:\n\n", print_num + 1);
	while (index != a->last + 1)
	{
		if ((a->data[index] <= 9999999) && (a->data[index] >= -999999))
			l_printf("%d\t\t%d\n", a->data[index], b->data[index]);
		else
			l_printf("%d\t%d\n", a->data[index], b->data[index]);
		++index;
	}
	++print_num;
	l_printf("\n----------------------------\nStack a\t\tStack b\n\nEND...\n");
	a->moves_num += b->moves_num;
}