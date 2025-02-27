/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:44:41 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 12:41:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*REVIEW - 
	RADIX SORT
	
	The radix sort checks the binary value of a number.

	If a bit is 0, will be put into stack b.
	If a bit is 1, the stack a will rotate.
	At the end of every cicle, it refills stack a with stack b.
	
	It does this process for all numbers, starting from the least
	significant bit, to the most significant bit.
	
	Example:
	17 (= 10001)	1) The first bits to watch are 101 (right column);	
	12 (= 01100)	2) Since at the first bit at the top we have 1, we RA;
	1  (= 00001)	3) Next, since we have a 0, we PB;
					4) Next we RA, because we have 1;
					5) Lastly, we refill pa with PA.
					6) We iterate for every column.
*/
void	radix_sort(t_stack *a, t_stack *b)
{
	static int		game_counter;
	int				binary;
	int				turn_counter;

	binary = 1;
	while (game_counter++ != a->max_num_len)
	{
		turn_counter = 0;
		while (turn_counter != a->size + b->size)
		{
			if (binary & a->data[a->first].n)
				ra();
			else
				pb();
			++turn_counter;
		}
		while (b->size != 0)
			pa();
		binary = binary << 1;
	}
}

/*REVIEW - 
	1)	If its already solved, stop;
	2)	Find the right order. Index the number if switch_indexation is
		ON;
	3)	If switch_choose_beststart_in_insertion is ON, perform an
		optimization in the first push to b;
	4)	Assure that stack a has not more than three elements.
		Hedge against limit cases (2 number stack and other weird 
		stuff);
	5)	Set the data to zero;
	6)	If the size of b is zero, perform a final rotation to order
		stack a, if needed;
	7)	INSERTION_LOOP
	8)	Check if the stack a is ordened.
*/
void	insertion_sort(t_stack *a, t_stack *b)
{
	if (checker() == 0)
		return ;
	indexation(a);
	if (a->switch_4_choose_beststart_in_insertion == ON)
	{
		best_start(a);
		move_unsorted_to_b(a);
	}
	assure_left_stack(a, b);
	set_data_to_zero(a, b);
	while ("Insertion loop!")
	{
		if (b->size == 0)
			final_rotation(a);
		else
		{
			find_smallest_bigger(a, b);
			find_half(a, b);
			update_cost(a, b);
			choose_cheepest(a, b);
			push_one(a, b);
		}
		if ((b->size == 0) && (checker() == 0))
			break ;
	}
}
