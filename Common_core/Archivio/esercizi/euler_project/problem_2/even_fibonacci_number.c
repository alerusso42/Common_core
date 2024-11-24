/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_fibonacci_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:23:32 by alerusso          #+#    #+#             */
/*   Updated: 2024/10/13 23:59:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "atoi.h"
#include "write_support.h"

int	sum_fibonacci(int max_fibo, int even_odd_all);
int	ft_fibonacci(int index_fibo);
int	magic_fibonacci(int num);

int	main(int argc, char *argv[])
{
	int	max_fibo;
	int	even_odd_all;

	if (argc != 3)
	{
		printf("Questo programma somma gli elementi");
		printf(" della sequenza di Fibo.\n");
		printf("Quando arriva oltre il numero x, smette");
		printf(" di sommare, e restituisce il risultato");
		printf(".\n In base all'utente, può sommare ");
		printf("solo numeri pari, dispari, o tutti.\n\n");
		printf("Necessita 2 argomenti, in quest'ordine: \n");
		printf("x: numero massimo che prende dalla sequenza");
		printf("\ny: se y è 1 prende solo pari, 2 solo");
		printf(" dispari, qualsiasi altro valore tutti.\n");
		return (42);
	}
	max_fibo = ft_atoi(argv[1]);
	even_odd_all = ft_atoi(argv[2]);
	//SOL 1: (la mia):
	ft_putnbr(sum_fibonacci(max_fibo, even_odd_all), 1);
	//SOL 2: (consiglio di project euler, non funge):
	//ft_putnbr(magic_fibonacci(3), 1);
	print("\n");
	return (0);
}

int	sum_fibonacci(int max_fibo, int even_odd_all)
{
	int	sum;
	int	index_fibo;
	int	temp_fibo;

	index_fibo = 0;
	temp_fibo = 0;
	sum = 0;
	--even_odd_all;
	while (temp_fibo < max_fibo)
	{
		if ((even_odd_all == 0) || (even_odd_all == 1))
		{
			if (temp_fibo % 2 == even_odd_all)
				sum += temp_fibo;
		}
		else
			sum += temp_fibo;
		temp_fibo = ft_fibonacci(index_fibo);
		++index_fibo;
	}
	return (sum);
}

int	ft_fibonacci(int index_fibo)
{
	if (index_fibo < 0)
		return (0);
	if (index_fibo == 0)
		return (1);
	if (index_fibo == 1)
		return (2);
	return ((ft_fibonacci(index_fibo - 1) + ft_fibonacci(index_fibo - 2)));
}

int	magic_fibonacci(int index_fibo)
{
	if (index_fibo < 0)
		return (0);
	if (index_fibo == 0)
		return (1);
	if (index_fibo == 1)
		return (2);
	return ((4 * ft_fibonacci(index_fibo - 1) + ft_fibonacci(index_fibo - 2)));
}
// E(n)=4*E(n-1)+E(n-2)
