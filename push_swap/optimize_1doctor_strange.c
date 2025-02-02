/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_1doctor_strange.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:42:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/02 18:28:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	command_padding(int start, int end, char command, int padding_size)
{
	static t_stack	*a;

	if (!a)
		a = store_stacks(NULL, GET_A);
	while (padding_size--)
	{
		a->command_list[start] = command;
		++start;
	}
	while (start != end)
	{
		a->command_list[start] = DELETE;
		++start;
	}
}

void	reduce_pushes(char *commands, int *index, int size)
{
	static int	rotation_diff;
	static int	save_index;

	rotation_diff = 0;
	save_index = *index;
	while ((commands[*index] == PA) || (commands[*index] == PB))
	{
		if (commands[*index] == PA)
			rotation_diff--;
		else
			rotation_diff++;
		++(*index);
	}
	rotation_diff %= size;
	if (*index - save_index == ft_abs(rotation_diff))
		return ;
	if (rotation_diff > 0)
		command_padding(save_index, *index, PB, ft_abs(rotation_diff));
	else
		command_padding(save_index, *index, PA, ft_abs(rotation_diff));
}

void	reduce_rotations(char *commands, int *index, int size)
{
	static int	rotation_diff;
	static int	save_index;

	rotation_diff = 0;
	save_index = *index;
	while ((commands[*index] == RA) || (commands[*index] == RRA))
	{
		if (commands[*index] == RA)
			rotation_diff--;
		else
			rotation_diff++;
		++(*index);
	}
	rotation_diff %= size;
	if (*index - save_index == ft_abs(rotation_diff))
		return ;
	if (rotation_diff > 0)
		command_padding(save_index, *index, RRA, ft_abs(rotation_diff));
	else
		command_padding(save_index, *index, RA, ft_abs(rotation_diff));
}

void	doctor_strange(t_stack *a)
{
	int	index;

	index = 0;
	while (index != a->command_list_length)
	{
		if ((a->command_list[index] == RA) || (a->command_list[index] == RRA))
			reduce_rotations(a->command_list, &index, a->size);
		else if ((a->command_list[index] == PA) || \
		(a->command_list[index] == PB))
			reduce_pushes(a->command_list, &index, a->size);
		else
			++index;
	}
}

