/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:01 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/29 14:53:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(int *n_array, int t_1, int n, int t_2)
{
	char	t;

	while (--t_1 != -1)
	{
		t = n_array[t_1] + '0';
		write(1, &t, 1);
	}
	t_1 = n - 1;
	t_2 = n - 2;
	if (n_array[t_1] != (10 - n) || n_array[t_2] != (11 - n))
		write(1, ", ", 2);
}

void	comparator(int t_1, int t_2, int *n_array, int n)
{
	int	check;

	check = 0;
	while (t_2 != -1)
	{
		if (n_array[t_1] < n_array[t_2])
		{
			check++;
		}
		--t_1;
		--t_2;
	}
	if (check == n - 1)
	{
		t_1 = n;
		printer(n_array, t_1, n, t_2);
	}
}

void	incrementator(int n, int *n_array, int t_increase)
{
	if (++n_array[t_increase] != 10)
	{
	}
	else
	{
		n_array[t_increase] = 0;
		++t_increase;
		incrementator(n, n_array, t_increase);
	}
}

void	ft_print_combn(int n)
{
	int	n_array[12];
	int	t_1;
	int	t_2;
	int	t_increase;

	t_1 = n - 1;
	while (t_1 != -1)
	{
		n_array[t_1] = 0;
		t_1 = t_1 - 1;
	}
	t_1 = n - 1;
	t_2 = n - 2;
	while ((n_array[t_1] != (11 - n) || n_array[t_2] != (10 - n)) && n != 1)
	{
		comparator(t_1, t_2, n_array, n);
		t_increase = 0;
		incrementator(n, n_array, t_increase);
		t_1 = n - 1;
		t_2 = n -2;
	}
	if (n == 1)
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
}

int	main(void)
{
	int	n;

	n = 5;
	ft_print_combn(n);
	return (0);
}
