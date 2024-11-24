/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/15 12:29:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_atoi_base(char *str, char *base);
int		find_base(char *base);
int		ft_atoi(char *str, char *base, int base_len, int i);
int		ft_exp(int base, int power);
int		convert_nbr_values(char temp, char *base);
char	*ft_putnbr_base(int nbr, char *base, char *print);
void	convert_from_base10(int nbr, char *base, int base_len, char *print);
void	ft_strcpy(char **dest, char *src);
// ft_atoi_base scorre fino a trovare il primo "numero".
// inizialmente controlla la base:
// se find_base torna il valore di errore -1, ritorna 0.
// per numero si intende un valore inserito nella base.
// registra il segno, e infine entra in ft_atoi.

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_len;
	int	converted_num;
	int	sign;

	i = 0;
	base_len = find_base(base);
	if (base_len == -1)
		return (0);
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		++i;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		++i;
	}
	while (str[i] == base[0])
		++i;
	converted_num = ft_atoi(str, base, base_len, i);
	converted_num = converted_num * sign;
	return (converted_num);
}
// find_base è stata copiata dal precedente esercizio.

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
// ft_atoi fa 5 cose: 
// 1)registra la grandezza del numero(101); 
// 2)torna all'inizio del numero(106);
// 3)converte il valore di str[i] in un int(109);
// 4)fa il prodotto tra la potenza della base e l'int 
//   trovato in precedenza (112). 
//   v. formula decimale-binario.
// 5) aumenta ezio_greggio, il numero da tornare, per
// un numero di volte pari alla grandezza del numero(107).
// NOTA: il controllo a (110) è superfluo: la funzione non
// troverà mai un valore di str[i] illegale.

int	ft_atoi(char *str, char *base, int base_len, int i)
{
	int	value;
	int	ezio_greggio;
	int	size_num;

	ezio_greggio = 0;
	size_num = 0;
	while (convert_nbr_values(str[i], base) != -1)
	{
		++size_num;
		++i;
	}
	i -= size_num;
	while (size_num != 0)
	{
		value = convert_nbr_values(str[i], base);
		if (value == -1)
			return (ezio_greggio);
		ezio_greggio += (value) * (ft_exp(base_len, size_num));
		size_num -= 1;
		++i;
	}
	return (ezio_greggio);
}
// ft_exp restituisce il risultato di:
// base^(power - 1). 
// power viene ridotto perchè deriva da base_len.
// es: per base 2, la potenza massima è 2 - 1(power - 1).

int	ft_exp(int base, int power)
{
	int	temp_base;

	temp_base = base;
	power -= 1;
	if (power == 0)
		return (1);
	while (power != 1)
	{
		base = temp_base * base;
		--power;
	}
	return (base);
}
// Analilzza la base per capire a che numero corrisponde
// il valore su cui sta puntando str[i].

int	convert_nbr_values(char temp, char *base)
{
	int	i;
	int	converted_value;

	converted_value = -1;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == temp)
		{
			converted_value = i;
			return (converted_value);
		}
		++i;
	}
	return (converted_value);
}
