/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_filldata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:13:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/29 12:14:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

int	fill_stacks(t_stack *a, char ***matrix)
{
	int				matrix_index;
	int				string_index;
	int				count_nums;
	long long int	atoi_result;

	matrix_index = 0;
	count_nums = 0;
	while (matrix[matrix_index])
	{
		string_index = 0;
		while (matrix[matrix_index][string_index])
		{
			atoi_result = ft_atoi(matrix[matrix_index][string_index]);
			if ((atoi_result > INT_MAX) || (atoi_result < INT_MIN))
				return (ER_ATOI);
			a->data[count_nums] = atoi_result;
			++count_nums;
			++string_index;
		}
		++matrix_index;
	}
	a->size = count_nums;
	return (0);
}

int	get_data(int count_num, t_stack **a, t_stack **b)
{
	int	error_type;

	error_type = alloc_data(a, b, (count_num));
	if (error_type != 0)
		return (error_type);
	(*a)->last = count_num - 1;
	(*a)->first = 0;
	(*b)->last = count_num - 1;
	(*b)->first = count_num;
	(*b)->size = 0;
	(*a)->moves_num = 0;
	store_stacks(*a, FILL_A);
	store_stacks(*b, FILL_B);
	return (0);
}