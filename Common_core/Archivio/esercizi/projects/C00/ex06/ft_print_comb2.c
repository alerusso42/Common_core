/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:08:04 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/23 12:08:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	printer(int x, int y)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = x / 10;
	b = x % 10;
	c = y / 10;
	d = y % 10;
	a = a + '0';
	b = b + '0';
	c = c + '0';
	d = d + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (x != 98 || y != 99)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	increment(int *x, int *y)
{
	if (*y != 99)
		*y += 1;
	else
	{
		*x += 1;
		*y = 0;
	}
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != 99 || y != 99)
	{
		if (x < y)
			printer(x, y);
		increment(&x, &y);
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
