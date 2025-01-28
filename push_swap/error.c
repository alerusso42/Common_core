/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:37:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/28 12:10:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*
	Error print the error string related to the error type it receives.
	read "push_define_list.h" for the complete list.
	During the correction, all strings except one will be muted.
*/
int	error(int error_type)
{
	if (error_type == ER_BAD_ARGC)
	{
		l_printf("\nThis project aims to sort a stack of number.\n\n");	
		l_printf("Please insert with argv arguments in form of characters ");
		l_printf("(ex: 1 3 9 K a 4) or strings (ex: \"1 3 9\" \"K a 4\") or ");
		l_printf("both.\nThe program should be able to print error and exit");
		l_printf(" if you insert something different from a number or you ");
		l_printf("repeat one or more numbers.\nIf everything goes well, the");
		l_printf(" program prints out the moves it has taken to sort.\nThis ");
		l_printf("message and the other will be disabled due to subject.\n");
		return (ER_BAD_ARGC);
	}
	else if (error_type == ER_BAD_CHAR)
		return (l_printf("\nOne char is illegal, sir\n"), ER_BAD_CHAR);
	else if (error_type == ER_MALLOC_ERROR)
		return (l_printf("\nMalloc error, sir (LOL)\n"), ER_MALLOC_ERROR);
	else if (error_type == ER_REPEATED_NUM)
		return (l_printf("\nYou repeat some numbers, sir\n"), ER_REPEATED_NUM);
	else if (error_type == ER_SIZE_OVERFLOW)
		return (l_printf("\nSize surpassed max_int, sir\n"), ER_SIZE_OVERFLOW);
	else if (error_type == ER_STACK_CORRUPTION)
		return (l_printf("\nStack corruption, sir\n"), ER_STACK_CORRUPTION);
	else
		return (l_printf("Error\n"), 1);
}