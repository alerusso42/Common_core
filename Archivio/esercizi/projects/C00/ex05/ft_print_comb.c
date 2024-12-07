/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:01 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/20 09:31:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(char array[])
{
	write(1, &array[0], 1);
	write(1, &array[1], 1);
	write(1, &array[2], 1);
	if (array[0] != '7' || array[1] != '8' || array[2] != '9')
	{
		write(1, ", ", 2);
	}
}

void	increment(char array[])
{
	if (array[2] < '9')
	{
		array[2]++;
	}
	else
	{
		array[2] = '0';
		if (array [1] < '9')
		{
			array[1]++;
		}
		else
		{
			array[1] = '0';
			if (array [0] < '9')
			{
				array[0]++;
			}
		}
	}
}

void	ft_print_comb(void)
{
	char	array[3];

	array[0] = '0';
	array[1] = '1';
	array[2] = '2';
	while (array[0] != '7' || array[1] != '9' || array[2] != '0')
	{
		if (array[0] < array[1] && array[1] < array[2])
		{
			printer(array);
			increment(array);
		}
		else
		{
			increment(array);
		}
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}*/
