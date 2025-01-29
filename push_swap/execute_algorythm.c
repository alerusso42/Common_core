/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:44:41 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/29 15:39:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	algorythm(void)
{
	static t_stack	*a;
	static t_stack	*b;
	static int		game_counter;
	int				binary;
	int				turn_counter;

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (!b)
		b = store_stacks(NULL, GET_B);
	binary = 1;
	while (game_counter++ != a->max_num_len)
	{
		turn_counter = 0;
		while (turn_counter != a->size + b->size)
		{
			if (binary & a->data[a->first])
				ra();
			else
				pb();
			++turn_counter;
		}
		while (b->size != 0)
			pa();
		binary = binary << 1;
	}
}