/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_support.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/10/17 18:43:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <unistd.h>

char	*ft_putnbr(int num, int print_no_yes);
int		check_size(int num);
char	*ft_convert_int(int num, int size_num, char *str);
void	print(char *str);

// ISTRUZIONI
// 1) Per printare con write una stringa:
// 	print("Ciao mondo!");
// 2) Per printare con write un int:
// 	ft_putnbr(number, 1);
// Restituisce il risultato come stringa (int to ascii).
// Se il secondo argomento è 1, printa anche il risultato.
/*
int	main(void)
{
	ft_putnbr(-2147483647 - 1, 1);
	return (0);
}*/
/*
ft_putnbr riceve in input due numeri, e restituisce il primo numero in
tipo char * (str).
Se il secondo numero è 1, oltre a restituire str, printa str usando la
funzione write.
Non è stato usato malloc, perchè non sempre la funzione
free è concessa nei progetti.
*/

char	*ft_putnbr(int num, int print_no_yes)
{
	char	str[38];
	int		size_num;

	size_num = check_size(num);
	if (num < 0)
		str[0] = '-';
	if (num != 0)
		ft_convert_int(num, size_num, str);
	else
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if (print_no_yes == 1)
		print(str);
	return (str);
}

int	check_size(int num)
{
	int	size_num;

	size_num = 0;
	while (num != 0)
	{
		num /= 10;
		++size_num;
	}
	return (size_num);
}

char	*ft_convert_int(int num, int size_num, char *str)
{
	int	index;
	int	pow_ten;
	int	sign;

	pow_ten = 1;
	sign = 1;
	while (--size_num > 0)
		pow_ten *= 10;
	index = 0;
	if (num < 0)
	{
		++index;
		sign = -1;
	}
	while ((num != 0) && (pow_ten != 0))
	{
		str[index] = (char)(sign * (num / pow_ten) + 48);
		num -= pow_ten * (num / pow_ten);
		pow_ten /= 10;
		++index;
	}
	str[index] = '\0';
	return (str);
}

// Printa una stringa con write.
void	print(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		++index;
	}
}
