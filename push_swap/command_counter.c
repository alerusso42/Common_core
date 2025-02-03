/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:42:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/03 16:34:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	command_counter(unsigned char command)
{
	static t_stack	*a;
	static t_stack	*b;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (!b)
		b = store_stacks(NULL, GET_B);
	if (!a->command_list)
		return ;
	if (a->command_list_length == a->command_list_size)
	{
		if (ft_realloc((void **)&a->command_list, a->command_list_size * 2, \
		sizeof(char)) == 1)
		{
			free(a->command_list);
			a->command_list = NULL;
		}
		a->command_list_size *= 2;
	}
	a->command_list[a->command_list_length] = command;
	a->command_list_length += 1;
	a->moves_num += 1;
	b->moves_num = a->moves_num;
}