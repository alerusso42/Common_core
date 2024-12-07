/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/15 10:57:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_fill(int *order, int argc);
int		ft_cmp(char *str1, char *str2);
void	ft_swap(int *num1, int *num2);
void	ft_print(char **argv, int *order, int argc);
// order è un array di int di valore crescente (0, 1, 2, 3).

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	order[60];

	if (argc < 2)
		return (0);
	i = 1;
	order[1] = 1;
	ft_fill(order, argc);
	while (i != argc)
	{
		j = i;
		while (j != argc)
		{
			if ((i != j) & (ft_cmp(argv[order[i]], argv[order[j]]) == 1))
				ft_swap(&order[i], &order[j]);
			++j;
		}
		++i;
	}
	ft_print(argv, order, argc);
	return (0);
}
//Il programma fa il confronto e scambia i numeri degli indici in order.

void	ft_fill(int *order, int argc)
{
	int	i;

	i = 2;
	while (i != argc)
	{
		order[i] = order[i -1] + 1;
		++i;
	}
}
// Fill riempie order con valori crescenti

int	ft_cmp(char *str1, char *str2)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	while ((str1[i] != '\0') & (cmp == 0))
	{
		if (str1[i] > str2[i])
			cmp = 1;
		else if (str1[i] < str2[i])
			cmp = -1;
		else
			++i;
	}
	return (cmp);
}
// Swap scambia due int di order

void	ft_swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
// print legge argv nell'ordine degli indici di order.

void	ft_print(char **argv, int *order, int argc)
{
	int	i_arg;
	int	i_word;
	int	i_order;

	i_order = 1;
	i_arg = order[i_order];
	while (argc != 1)
	{
		i_word = 0;
		while (argv[i_arg][i_word])
		{
			write(1, &argv[i_arg][i_word], 1);
			++i_word;
		}
		write(1, "\n", 1);
		i_arg = order[++i_order];
		--argc;
	}
}
