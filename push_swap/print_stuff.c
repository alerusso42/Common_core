/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:07:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 12:15:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*
	Why show binary? For radix sort.
*/
void	print_stacks(void)
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
		if ((a->data[index].n <= 9999999) && (a->data[index].n >= -999999))
			l_printf("\n%d\t\t%d", a->data[index].n, b->data[index].n);
		else if ((a->data[index].n != 0) && (b->data[index].n) != 0)
			l_printf("\n%d\t%d", a->data[index].n, b->data[index].n);
		if (a->switch_1_showbinary == ON)
			l_printf("\t%s\t%s", ft_binary(a->data[index].n, string, \
			a->max_num_len), ft_binary(b->data[index].n, string, \
			a->max_num_len));
	}
	l_printf("\n--------------------------\n\nStack a\t\tStack b\n\nEND...\n");
}

/*
	To print command on screen in a long detailed format.
*/
static void	print_command(char command)
{
	static int	count_commands = 1;

	if (command == RA)
		l_printf("Move number %d: ra;\n", count_commands++);
	else if (command == RRA)
		l_printf("Move number %d: rra;\n", count_commands++);
	else if (command == PA)
		l_printf("Move number %d: pa;\n", count_commands++);
	else if (command == PB)
		l_printf("Move number %d: pb;\n", count_commands++);
	else if (command == RB)
		l_printf("Move number %d: rb;\n", count_commands++);
	else if (command == RRB)
		l_printf("Move number %d: rrb;\n", count_commands++);
	else if (command == RR)
		l_printf("Move number %d: rr;\n", count_commands++);
	else if (command == RRR)
		l_printf("Move number %d: rrr;\n", count_commands++);
	else if (command == SA)
		l_printf("Move number %d: sa;\n", count_commands++);
	else if (command == SB)
		l_printf("Move number %d: sb;\n", count_commands++);
}

/*
	To print command on screen in a minimalistic format.
*/
static void	only_print_command(char command)
{
	if (command == RA)
		l_printf("ra\n");
	else if (command == RRA)
		l_printf("rra\n");
	else if (command == PA)
		l_printf("pa\n");
	else if (command == PB)
		l_printf("pb\n");
	else if (command == RB)
		l_printf("rb\n");
	else if (command == RRB)
		l_printf("rrb\n");
	else if (command == RR)
		l_printf("rr\n");
	else if (command == RRR)
		l_printf("rrr\n");
	else if (command == SA)
		l_printf("sa\n");
	else if (command == SB)
		l_printf("sb\n");
}

/*
	If we are in correction, uses only_print_command.
	Else, print_command.
*/
void	print_moves(void)
{
	static t_stack	*a;
	int				index;

	a = store_stacks(NULL, GET_A);
	index = 0;
	if (a->variable_1_mode != CORRECTION)
	{
		l_printf("\n");
		while (a->command_list[index] != 0)
		{
			print_command(a->command_list[index]);
			++index;
		}
	}
	else
	{
		while (a->command_list[index] != 0)
		{
			only_print_command(a->command_list[index]);
			++index;
		}
	}
}
