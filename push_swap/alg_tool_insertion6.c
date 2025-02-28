/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_tool_insertion6.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:53:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/28 13:51:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	order_three(t_stack *a);

/*
	If the size is not zero (therefore we optimed the 
		stacks), stop.
	Else If the size of a is already equal or less than 3,
		stop.
	Else, while the size of the stack a is not 3, push
		elements in b.
	
	Lastly, let's sort the three numbers:
	let's assume, for example, 0 1 2 (x, y, z).
	If needed, we perform a switch (see order_three ft);
	
	Then, there will be three possible combinations:
	0-1-2; 1-2-0; 2-0-1.

	If the middle number is bigger than the last, we
	perform a rra.
	Else, we perform ra.
*/
void	assure_left_stack(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		return ;
	if (a->size == 2)
	{
		sa();
		return ;
	}
	while (a->size > 3)
		pb();
	order_three(a);
	if ((a->data[a->first].n < a->data[a->first + 1].n) \
	&& (a->data[a->first + 1].n < a->data[a->first + 2].n))
		return ;
	if (a->data[a->first + 1].n > a->data[a->first + 2].n)
		rra();
	else
		ra();
}

/*
	If the three numbers are ordened, even if shifted,
	return, else switch two of them.

	For example, are valid: 0-1-2; 1-2-0; 2-0-1.
	Any other combination needs one switch to work.
*/
static void	order_three(t_stack *a)
{
	if ((a->data[a->first].n < a->data[a->first + 1].n) \
	&& (a->data[a->first + 1].n < a->data[a->first + 2].n))
		return ;
	if ((a->data[a->first + 1].n < a->data[a->first + 2].n) \
	&& (a->data[a->first + 2].n < a->data[a->first].n))
		return ;
	if ((a->data[a->first + 2].n < a->data[a->first].n) \
	&& (a->data[a->first].n < a->data[a->first + 1].n))
		return ;
	sa();
}
