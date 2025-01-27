/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:13:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/27 14:50:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	find_half(t_stack *a, t_stack *b, int argc);
static void	find_apexes(t_stack *a, t_stack *b, int argc);
static int	fill_stacks(t_stack *a, t_stack *b, char *argv[]);
static int	check_for_doubles(t_stack *a, t_stack *b);

static void	find_half(t_stack *a, t_stack *b, int argc)
{
	argc *= 3;
	argc /= 2;
	a->center = argc;
	b->center = argc;
}

static void	find_apexes(t_stack *a, t_stack *b, int argc)
{
	if (argc == 1)
	{
		a->first = 1;
		b->last = 1;
	}
	else if (argc % 2 == 0)
	{
	 	a->first = a->center - (argc / 2);
		b->first = b->center - (argc / 2);
		a->last = a->center + ((argc / 2) - 1);
		b->last = b->center + ((argc / 2) - 1);
	}
	else
	{
	 	a->first = a->center - (argc / 2);
		b->first = b->center - (argc / 2);
		a->last = a->center + (argc / 2);
		b->last = b->center + (argc / 2);
	}
}

static int	check_for_doubles(t_stack *a, t_stack *b)
{
	
}

static int	fill_stacks(t_stack *a, t_stack *b, char *argv[])
{
	while (argv)
	{
		
		++argv;
	}
}

int	get_data(int argc, char *argv[], t_stack **a, t_stack **b)
{
	int	error_type;

	error_type = alloc_data(a, b, (argc - 1));
	if (error_type != 0)
		return (error_type);
	find_half(*a, *b, argc);
	find_apexes(*a, *b, argc - 1);
	error_type = fill_stacks(*a, *b, argv);
	if (error_type != 0)
		return (error_type);
	return (0);
}