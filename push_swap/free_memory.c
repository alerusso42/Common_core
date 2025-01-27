/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:06:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/27 11:53:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*
	Free everything, receiving the address of the structs.

	If one of them is not allocated, it does not core dump.
*/
void	free_memory(t_stack **a, t_stack **b)
{
	if ((a) && (*a))
	{
		if ((*a)->data)
		{
			free((*a)->data);
			(*a)->data = NULL;
		}
		free(*a);
		*a = NULL;
	}
		if ((b) && (*b))
	{
		if ((*b)->data)
		{
			free((*b)->data);
			(*b)->data = NULL;
		}
		free(*b);
		*b = NULL;
	}
}