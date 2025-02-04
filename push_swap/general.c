/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:42:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:43:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

int	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	if (num == INT_MIN)
		return (INT_MAX);
	return (num * -1);
}

/*
	if size == 0 --------> half = 0
	if size == 1 --------> half = 1
	if size == even -----> half = size / 2
	if size == odd ------> half = (size / 2) + 1

	If you need the above half, calls num < half
	If you need the lower half, calls num >= half  
*/
void	find_half(t_stack *a, t_stack *b)
{
	if ((a != NULL) && (a->size == 0))
		a->half = a->first + 0;
	else if ((a != NULL) && (a->size == 1))
		a->half = a->first + 1;
	else if (a != NULL)
	{
		if (a->size % 2 == 0)
			a->half = a->first + (a->size / 2);
		else
			a->half = a->first + (a->size / 2) + 1;
	}
	if ((b != NULL) && (b->size == 0))
		b->half = b->first + 0;
	else if ((b != NULL) && (b->size == 1))
		b->half = b->first + 1;
	else if (b != NULL)
	{
		if (b->size % 2 == 0)
			b->half = b->first + (b->size / 2);
		else
			b->half = b->first + (b->size / 2) + 1;
	}
}

void	switch_data(t_data *one, t_data *two)
{
	static t_data	temp;

	temp = *one;
	*one = *two;
	*two = temp;
}

void	ft_rev_string(char *string)
{
	int	i;
	int	t;
	int	size;

	i = 0;
	size = ft_strlen(string);
	while (i < size / 2)
	{
		t = string[i];
		string[i] = string[size - 1 - i];
		string[size - 1 - i] = t;
		i++;
	}
}

char	*ft_binary(int num, char result[33], int mlen)
{
	int		index;

	index = 0;
	while (index != 14)
		result[index++] = 0;
	index = 0;
	while (index < mlen)
		result[++index] = 48;
	num = ft_abs(num);
	index = -1;
	while (num != 0)
	{
		result[++index] = (num % 2) + 48;
		num /= 2;
	}
	ft_rev_string(result);
	return (result);
}
