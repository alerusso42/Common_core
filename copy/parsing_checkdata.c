/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checkdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:13:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 12:07:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static int	check_for_doubles(t_stack *a);
static bool	count_strings(char **matrix, int *counter);

/*
	For every num, check if every other one is different.
*/
static int	check_for_doubles(t_stack *a)
{
	int	control_from;
	int	control_to;

	if (a->size == 1)
		return (0);
	control_from = a->first + 1;
	while (control_from != a->last + 1)
	{
		control_to = control_from - 1;
		while (control_to != a->first - 1)
		{
			if (a->data[control_from].n == a->data[control_to].n)
				return (ER_REPEATED_NUM);
			--control_to;
		}
		control_from += 1;
	}
	return (0);
}

/*
	1)	If something is NULL, return MALLOC_ERROR;
	2)	Calculate the number of numbers (lol).
*/
static bool	count_strings(char **matrix, int *counter)
{
	if ((!matrix) || (!matrix[0]))
		return (ER_MALLOC_ERROR);
	while (*matrix)
	{
		*counter += 1;
		++matrix;
	}
	return (0);
}

/*
	1)	Alloc 3D matrix (for multiple strings in argument, like
		"3 5 6" "1 -2 7" "0");
	2)	For every argc, split every number;
	3)	Alloc the data for the stacks structs;
	4)	Fill the stacks with the matrix values;
	5)	Free the matrix;
	6)	Check repeated num;
	7)	Find the biggest number in a.
*/
int	parsing(int argc, char *argv[], t_stack **a, t_stack **b)
{
	char		***matrix;
	static int	matrix_index;
	static int	count_num;
	int			error;

	matrix = (char ***)ft_calloc(argc + 1, sizeof(char *));
	if (!matrix)
		return (ER_MALLOC_ERROR);
	while (argc --)
	{
		matrix[matrix_index] = ft_split(argv[matrix_index + 1], ' ');
		if (count_strings(matrix[matrix_index], &count_num))
			return (free_three_d_matrix(matrix), ER_MALLOC_ERROR);
		++matrix_index;
	}
	error = get_data(count_num, a, b);
	if (error != 0)
		return (free_three_d_matrix(matrix), free_memory(a, b), error);
	error = fill_stacks(*a, matrix);
	if (error != 0)
		return (free_three_d_matrix(matrix), free_memory(a, b), error);
	free_three_d_matrix(matrix);
	if (check_for_doubles(*a))
		return (ER_REPEATED_NUM);
	return (find_biggest(*a), 0);
}
