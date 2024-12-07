/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somma_variabile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:26 by alerusso          #+#    #+#             */
/*   Updated: 2024/10/17 18:46:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "atoi.h"
#include "write_support.h"

int	variadic(int n, ...);

int	main(int argc, char *argv[])
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	index;
	int	sum;

	if (argc == 1)
	{
		printf("\nIl programma prende in input un numero");
		printf(" variabile di argomenti, li converte ");
		printf("con atoi e li somma tra loro.");
		printf("Restituisce e printa la somma.");
		printf("Viene usata una funzione variadica");
		printf("\nInserisci degli argomenti.\n");
		return (42);
	}
	index = 1;
	sum = 0;
	while (index != argc)
	{
		while ((index != argc))
		{
			if (index % 4 == 1)
				a = ft_atoi(argv[index]);
			if (index % 4 == 2)
				b = ft_atoi(argv[index]);
			if (index % 4 == 3)
				c = ft_atoi(argv[index]);
			if (index % 4 == 0)
			{
				d = ft_atoi(argv[index]);
				++index;
				break ;
			}
			++index;
		}
		--index;
		if (index % 4 == 1)
			sum += variadic(1, a);
		if (index % 4 == 2)
			sum += variadic(2, a, b);
		if (index % 4 == 3)
			sum += variadic(3, a, b, c);
		if (index % 4 == 0)
			sum += variadic(4, a, b, c, d);
		++index;
	}
	ft_putnbr(sum, 1);
}
// Il programma prende 4 elementi per volta (a,b,c,d).
// Fa l'atoi sulla stringa puntata da argv[index].
// Quando il modulo di index % 4 = 4, ha finito un ciclo.
// Esce con break, torna indietro di un index per check.
// Verifica quanti elementi nel ciclo deve mandare a variadic.
// Variadic usa va_arg per aumentare sum e passare all'_
// _elemento successivo. 
// Quando index == argc, manda sum a ft_putnbr.
// ft_putnbr ha come secondo argomento 1: quindi stampa.

int	variadic(int elements_number, ...)
{
	int			sum;
	int			index;
	va_list		ptr;

	va_start(ptr, elements_number);

	index = 0;
	sum = 0;
	while (index != elements_number)
	{
		sum += va_arg(ptr, int);
		++index;
	}
	return (sum);
}
