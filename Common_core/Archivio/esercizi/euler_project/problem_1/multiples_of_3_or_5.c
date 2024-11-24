/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiples_of_3_or_5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/10/13 22:04:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "atoi.h"
#include "write_support.h"

int		sum_multiples(int limit);
int		sum_multiples_2(int num, int limit);

// The program sums all the multiples of 3 or 5 until 1000; then sum the results
int	main(int argc, char *argv[])
{
	int	result;
	int	num_1;
	int	num_2;
	int	limit;

	if (argc == 2)
	{
		printf("\nLa soluzione mostrata è veloce, ma rischia l'overflow.");
		printf("\n");
		return (1);
	}
	if (argc != 4)
	{
		printf("\nIl programma restituisce la somma di tutti i multipli ");
		printf("di un numero x, sommata a quella del numero y.\n");
		printf("Esclude i multipli comuni ai due numeri: ");
		printf("per farlo, sottrae dal risultato la somma dei multipli ");
		printf("dell'mcm(x, y), ossia l'insieme dei multipli in comune. \n");
		printf("L'utente definisce x, y e fino a che multiplo vuole sommare.");
		printf("\n\nInserisci come argomenti, in ordine:\n");
		printf("primo numero;\n");
		printf("secondo numero;\n");
		printf("Multiplo massimo da analizzare.\n");
		printf("\nPer info sui problemi del programma,inserisci un argomento.");
		printf("\n");
		return (42);
	}
	num_1 = ft_atoi(argv[1]);
	num_2 = ft_atoi(argv[2]);
	limit = ft_atoi(argv[3]);
	/*SOL 1: 
	result = sum_multiples(1000);
	*/
	//SOL 2: 
	limit = 10;
	result = sum_multiples_2(num_1, limit) + sum_multiples_2(num_2, limit);
	result -= sum_multiples_2((num_1 * num_2), limit);
	ft_putnbr(result, 1);
	write(1, "\n", 1);
	return (0);
}

// Soluzione 1, additiva.
/*
int	sum_multiples(int limit)
{
	int	n;
	int	sum;

	if (limit <= 0)
		return (0);
	sum = 0;
	n = 1;
	while (n != limit)
	{
		if ((n % 3 == 0) || (n % 5 == 0))
			sum += n;
		++n;
	}
	return (sum);
}
*/
// Soluzione 2, sommando multipli di n1, n2 ed eliminando mcm (15).
// mcm viene ottenuto facendo n1 * n2, vedi main().
int	sum_multiples_2(int num, int limit)
{
	int	multiple;
	int	multiple_index;
	int	sum;

	if (limit < 0 || num > limit)
		return (0);
	multiple = 0;
	multiple_index = 1;
	sum = 0;
	while (multiple < limit)
	{
		sum += num * multiple_index;
		++multiple_index;
		multiple = num * multiple_index;
	}
	return (sum);
}
// multiple serve per check.