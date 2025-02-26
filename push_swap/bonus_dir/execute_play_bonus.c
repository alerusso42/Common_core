/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:44:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:43:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

int	victory_message(t_stack *a, t_stack *b, int mode)
{
	if (a->is_sort == NO)
		return (-1);
	(void)b;
	if (mode == PRINT)
		l_printf("\nEverything sorted in %d moves, GG!\n", a->moves_num);
	return (a->moves_num);
}

static void	help_message(void)
{
	l_printf("\nCOMMAND LIST:\n\nsa:\tswap two first elements of a;\n");
	l_printf("sb:\tswap two first elements of b;\n");
	l_printf("ss:\tboth sa and sb;\n");
	l_printf("pa:\tpush the top element of b in top of a;\n");
	l_printf("pb:\tpush the top element of a in top of b;\n");
	l_printf("ra:\tshift all elements of a to the top by one;\n");
	l_printf("rb:\tshift all elements of b to the top by one;\n");
	l_printf("rr:\tboth ra and rb;\n");
	l_printf("rra:\tshift all elements of a to the low by one;\n");
	l_printf("rrb:\tshift all elements of b to the low by one;\n");
	l_printf("rrr:\tboth rra and rrb;\n");
	l_printf("help:\tY'a know;\n");
	l_printf("stop:\tstop the program;\n");
	l_printf("mv:\tprints out the total moves done for now;\n");
	l_printf("check:\tchecks if you have won or not. If yes, stops.\n\n");
}

static int	other_commands2(char input[7])
{
	static t_stack	*a;

	if (a == NULL)
		a = store_stacks(NULL, GET_A);
	if (ft_strncmp(input, "mv", 2) == 0)
		l_printf("\n\nMOVES DONE FOR NOW: %d\n\n", a->moves_num);
	else
		return (1);
	return (0);
}

static int	other_commands(char input[7])
{
	if (ft_strncmp(input, "sb", 2) == 0)
		sb();
	else if (ft_strncmp(input, "ss", 2) == 0)
		ss();
	else if (ft_strncmp(input, "pa", 2) == 0)
		pa();
	else if (ft_strncmp(input, "pb", 2) == 0)
		pb();
	else if (ft_strncmp(input, "ra", 2) == 0)
		ra();
	else if (ft_strncmp(input, "rb", 2) == 0)
		rb();
	else if (ft_strncmp(input, "rra", 3) == 0)
		rra();
	else if (ft_strncmp(input, "rrb", 3) == 0)
		rrb();
	else if (ft_strncmp(input, "rrr", 3) == 0)
		rrr();
	else if (ft_strncmp(input, "rr", 2) == 0)
		rr();
	else if (ft_strncmp(input, "help", 4) == 0)
		help_message();
	else
		return (other_commands2(input));
	return (0);
}

int	play(void)
{
	static t_stack	*a;
	static t_stack	*b;
	char			input[7];

	if (!a)
		a = store_stacks(NULL, GET_A);
	if (!b)
		b = store_stacks(NULL, GET_B);
	while ("game_loop")
	{
		print_stacks();
		l_printf("\nPress \"help\" for commands list, else command.\n");
		read(0, input, 5);
		if (ft_strncmp(input, "sa", 2) == 0)
			sa();
		else if (other_commands(input) == 0)
			l_printf("");
		else if ((ft_strncmp(input, "check", 5) == 0) && (checker() == 0))
			return (victory_message(a, b, 1));
		else if (ft_strncmp(input, "stop", 2) == 0)
			return (0);
		else if (ft_strncmp(input, "check", 5) != 0)
			l_printf("\ninvalid user input!\n");
	}
	return (0);
}
