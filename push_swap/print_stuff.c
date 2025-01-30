/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:07:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/30 11:19:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	print_stacks()
{
	static int		index;
	static int		print_num;
	static t_stack	*a;
	static t_stack	*b;
	static char		string[33];

	if (a == NULL)
		a = store_stacks(NULL, GET_A);
	if (b == NULL)
		b = store_stacks(NULL, GET_B);
	index = -1;
	l_printf("\nPrint number %d:\n\n", ++print_num);
	while (++index != a->last + 1)
	{
		if ((a->data[index] <= 9999999) && (a->data[index] >= -999999))
			l_printf("\n%d\t\t%d", a->data[index], b->data[index]);
		else if ((a->data[index] != 0) && (b->data[index]) != 0)
			l_printf("\n%d\t%d", a->data[index], b->data[index]);
		if (a->switch_1_showbinary == ON)
			l_printf("\t%s", ft_binary(a->data[index], string, a->max_num_len));
		if (a->switch_1_showbinary == ON)
			l_printf("\t%s", ft_binary(b->data[index], string, a->max_num_len));
	}
	a->moves_num += b->moves_num;
	l_printf("\n--------------------------\n\nStack a\t\tStack b\n\nEND...\n");
}