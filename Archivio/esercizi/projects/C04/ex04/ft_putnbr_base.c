/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/13 10:16:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		find_base(char *base);
int		convert_nbr_base(int nbr, char *base, int base_len, char *print);
char	convert_nbr_values(int temp, char *base);
/*
int main(int argc, char *argv[])
{
	int nbr;

	if (argc != 3)
	{
		printf("Inserisci il numero e la base.");
		return (42);
	}
	nbr = atoi(argv[1]);
	printf("Numero in int: %d\n", nbr);
	ft_putnbr_base(nbr, argv[2]);
	return (0);
}
*/
// Il programma fa una normale conversione, poi prende
// gli indici della base per trasformare il numero

void	ft_putnbr_base(int nbr, char *base)
{
	char	print[37];
	int		print_index;
	int		base_len;
	int		sign;

	base_len = find_base(base);
	print[0] = '0';
	print[1] = '\0';
	sign = 0;
	if ((nbr != 0) & (base_len != -1))
		sign = convert_nbr_base(nbr, base, base_len, print);
	print_index = 0;
	if (sign == -1)
		write(1, "-", 1);
	while (print[print_index])
		++print_index;
	--print_index;
	while ((print_index != -1) & (base_len != -1))
	{
		write(1, &print[print_index], 1);
		--print_index;
	}
}
// viene usato base_len = -1 come valore di controllo.

int	find_base(char *base)
{
	int		i;
	int		i2;
	char	temp;
	int		base_len;

	i = -1;
	base_len = 0;
	while ((base[++i] != '\0') & (base_len != -1))
	{
		i2 = 0;
		temp = base[i];
		while ((base[i2] != '\0') & (base_len != -1))
		{
			if ((temp == base[i2]) & (i != i2))
				base_len = -1;
			if (temp == '+' || temp == '-')
				base_len = -1;
			++i2;
		}
		if (base_len != -1)
			++base_len;
	}
	if (base_len < 2)
		base_len = -1;
	return (base_len);
}
/* Restituisce l'array di valori da stampare e il segno.
   il min int lo gestisce calcolando ogni cifra da sola.*/

int	convert_nbr_base(int nbr, char *base, int base_len, char *print)
{
	int	sign;
	int	i;
	int	temp;

	sign = 1;
	if (nbr < 0)
		sign = -1;
	i = 0;
	while (nbr != 0)
	{
		temp = nbr % base_len;
		nbr = nbr / base_len;
		temp = temp * sign;
		print[i] = convert_nbr_values(temp, base);
		++i;
	}
	print[i] = '\0';
	return (sign);
}
// il numero ottenuto viene usato come indice della base
// per poi essere convertito

char	convert_nbr_values(int temp, char *base)
{
	int		i;
	char	converted_value;

	i = temp;
	converted_value = base[i];
	return (converted_value);
}
