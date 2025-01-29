/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:05:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/29 15:09:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	variables(t_settings *settings, t_stack *a, t_stack *b)
{
	settings->variable_1_mode = PRINT_FINAL_RESULT;
	if (settings->variable_1_mode == PRINT_MODIFICATIONS)
	{
		a->print_stuff = PRINT_MODIFICATIONS;
		b->print_stuff = PRINT_MODIFICATIONS;
	}
	if (settings->variable_1_mode == CORRECTION)
	{
		a->print_stuff = CORRECTION;
		b->print_stuff = CORRECTION;
	}
}