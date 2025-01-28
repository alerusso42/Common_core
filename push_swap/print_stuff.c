/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:07:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/28 13:38:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	print_stacks(t_stack *a, t_stack *b)
{
	int			index;
	static int	print_num;

	index = a->first;
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
}