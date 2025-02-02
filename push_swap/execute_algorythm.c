/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:44:41 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/02 12:38:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*
	RADIX SORT
	
	The radix sort checks the binary value of a number.

	If a bit is 0, will be put into stack b.
	If a bit is 1, the stack a will rotate.
	At the end of every cicle, it refills stack a with stack b.
	
	It does this process for all numbers, starting from the least
	significant bit, the most significant bit.
	
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
			if (binary & a->data[a->first])
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

void	insertion_sort(t_stack *a, t_stack *b)
{
	
}