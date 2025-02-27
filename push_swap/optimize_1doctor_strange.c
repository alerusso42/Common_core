/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_1doctor_strange.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:42:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 12:01:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*
	1)	Insert the command while there is a diff (padding_size);
	2)	For the others member of the sequence, put a placeholder
		value (DELETE).
*/
void	command_padding(int start, int end, char command, int padding_size)
{
	t_stack	*a;

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

/*
	1)	Calc push diff for every command RA/RRA;
	2)	If push_diff exceedes the size of the stack, make a %;
	3)	If the absolute value of push_diff is equal to the
		lenght of the current sequence, do nothing;
	4)	Else, print only the necessary pushes. 
*/
void	reduce_pushes(char *commands, int *index, int size)
{
	int	push_diff;
	int	save_index;

	push_diff = 0;
	save_index = *index;
	while ((commands[*index] == PA) || (commands[*index] == PB))
	{
		if (commands[*index] == PA)
			push_diff--;
		else
			push_diff++;
		++(*index);
	}
	push_diff %= size;
	if (*index - save_index == ft_abs(push_diff))
		return ;
	if (push_diff > 0)
		command_padding(save_index, *index, PB, ft_abs(push_diff));
	else
		command_padding(save_index, *index, PA, ft_abs(push_diff));
}

/*
	1)	Calc rotations diff for every command RA/RRA;
	2)	If rotation_diff exceedes the size of the stack, make a %;
	3)	If the absolute value of rotations_diff is equal to the
		lenght of the current sequence, do nothing;
	4)	Else, print only the necessary rotations. 
*/
void	reduce_rotations(char *commands, int *index, int size)
{
	int	rotation_diff;
	int	save_index;

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

/*
	The strongest optimization.
	And the least useful.
	But the coolest.

	If a->switch_doctor_strange == ON, before print the resulting moves:

	1)	If there are useless rotations  it deletes them
		(ex: RA, RRA, RA, RRA, RA 	becomes -> RA);
	2)	Same for pushes.
	
*/
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
