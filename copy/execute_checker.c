/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:05:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/07 10:58:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*
	Checks if everything is bigger than its previous.
*/
int	checker(void)
{
	static t_stack	*a;
	static t_stack	*b;
	static int		index;

	if (a == NULL)
		a = store_stacks(NULL, GET_A);
	if (b == NULL)
		b = store_stacks(NULL, GET_B);
	if (b->size != 0)
		return (1);
	index = 0;
	while (index != a->size - 1)
	{
		if (a->data[index].n > a->data[index + 1].n)
		{
			return (1);
		}
		++index;
	}
	return (0);
}

/*
static void	commands(t_stack *a, int index)
{
	if (a->command_list[index] == SA)
		sa();
	else if (a->command_list[index] == SB)
		sb();
	else if (a->command_list[index] == PA)
		pa();
	else if (a->command_list[index] == PB)
		pb();
	else if (a->command_list[index] == RA)
		ra();
	else if (a->command_list[index] == RB)
		rb();
	else if (a->command_list[index] == RR)
		rr();
	else if (a->command_list[index] == RRA)
		rra();
	else if (a->command_list[index] == RRB)
		rrb();
	else
		rrr();
}*/

int	test(void)
{
	char	*command;
	int		error;

	command = get_next_line(0);
	error = 0;
	while (command && error != 1)
	{
		error = get_command(command);
		free(command);
		command = get_next_line(0);
	}
	if (error != 1 && checker() == 0)
		return (l_printf("OK\n"), 0);
	else
		return (l_printf("KO\n"), 1);
}
