/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:06:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/02 18:34:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	free_stack_b(t_stack **b)
{
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
		if ((*a)->command_list)
		{
			free((*a)->command_list);
			(*a)->command_list = NULL;
		}
		free(*a);
		*a = NULL;
	}
	free_stack_b(b);
}

void	free_three_d_matrix(char ***matrix)
{
	int	index_one;
	int	index_two;

	index_one = 0;
	if (!matrix)
		return ;
	while (matrix[index_one])
	{
		index_two = 0;
		while (matrix[index_one][index_two])
		{
			free(matrix[index_one][index_two]);
			matrix[index_one][index_two] = NULL;
			++index_two;
		}
		free(matrix[index_one]);
		matrix[index_one] = NULL;
		++index_one;
	}
	free(matrix);
}