/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:05:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:45:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	apply_variables(t_settings *settings, t_stack *a, t_stack *b);

void	variables(t_settings *settings, t_stack *a, t_stack *b)
{
	settings->variable_1_mode = CORRECTION;
	settings->variable_2_which_algorythm = INSERTION_SORT;
	apply_variables(settings, a, b);
}

static void	apply_variables(t_settings *settings, t_stack *a, t_stack *b)
{
	if (settings->variable_1_mode == PRINT_MODIFICATIONS)
	{
		a->variable_1_mode = PRINT_MODIFICATIONS;
		b->variable_1_mode = PRINT_MODIFICATIONS;
	}
	if (settings->variable_1_mode == PRINT_FINAL_RESULT)
	{
		a->variable_1_mode = PRINT_FINAL_RESULT;
		b->variable_1_mode = PRINT_FINAL_RESULT;
	}
	if (settings->variable_1_mode == CORRECTION)
	{
		a->variable_1_mode = CORRECTION;
		b->variable_1_mode = CORRECTION;
	}
	a->variable_2_which_algorythm = settings->variable_2_which_algorythm;
	b->variable_2_which_algorythm = settings->variable_2_which_algorythm;
}
