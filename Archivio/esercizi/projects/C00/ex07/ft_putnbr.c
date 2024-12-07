/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:26:27 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/23 12:05:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	piedini_gardevoir(int *x_array, int is_pos_zero_or_neg, int i_array)
{
	int		t;

	if (is_pos_zero_or_neg == 0 || is_pos_zero_or_neg == 2)
	{
		if (is_pos_zero_or_neg == 2)
		{
			write(1, "-", 1);
		}
		while (i_array != 0)
		{
			t = x_array[i_array];
			t = t + '0';
			if (i_array < 10)
			{
				write(1, &t, 1);
			}
			i_array = i_array -1;
		}
		t = x_array[i_array];
		t = t + '0';
		write(1, &t, 1);
	}
}

void	mega_rayquaza(int nb, int *i_array, int is_pos_zero_or_neg)
{
	int	t_x;
	int	exp;

	if (is_pos_zero_or_neg == 0 || is_pos_zero_or_neg == 2)
	{
		t_x = nb;
		exp = 1;
		while (t_x >= 0 && *i_array != 12)
		{
			t_x = nb;
			t_x = t_x - exp;
			exp = exp * 10;
			*i_array = *i_array + 1;
		}
		*i_array = *i_array - 1;
		if (i_array == 0)
		{
			*i_array = 1;
		}
	}
}

void	wailord(int nb, int i_array, int is_pos_zero_or_neg)
{
	int	i_x;
	int	x_array[10];

	i_x = 0;
	if (is_pos_zero_or_neg == 0 || is_pos_zero_or_neg == 2)
	{
		while (i_x != i_array)
		{
			x_array[i_x] = nb % 10;
			nb = nb / 10;
			i_x = i_x + 1;
		}
	}
	i_x = 0;
	i_array = i_array -1;
	piedini_gardevoir(x_array, is_pos_zero_or_neg, i_array);
}

void	ft_putnbr(int nb)
{
	int	is_pos_zero_or_neg;
	int	i_array;

	i_array = 0;
	is_pos_zero_or_neg = 0;
	if (nb < 0)
	{
		is_pos_zero_or_neg = 2;
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			is_pos_zero_or_neg = 3;
		}
		else
		{
			nb = -nb;
		}
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		is_pos_zero_or_neg = 1;
	}
	mega_rayquaza(nb, &i_array, is_pos_zero_or_neg);
	wailord(nb, i_array, is_pos_zero_or_neg);
}
/*
int	main(int argc, char **argv)
{
	int	nb;

	if (argc != 2)
	{
		return (1);
	}
	nb = atoi(argv[1]);
	printf("ATOI: %d\n", nb);
	write(1, "ft_putnbr: ", 11);
	ft_putnbr(nb);
	return (0);
}*/
