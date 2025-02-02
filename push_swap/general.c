/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:42:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/02 10:17:41 by alerusso         ###   ########.fr       */
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