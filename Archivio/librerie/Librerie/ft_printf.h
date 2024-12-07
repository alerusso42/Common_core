/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/15 23:08:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <malloc.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		type_print(char type, va_list ptr);
void	ft_putnbr(int num);
void	print(char *str);

// ISTRUZIONI:
// Come printf. Per favore: non sbagliare gli specificatori
// di formato. Il compilatore non verrà a salvarti.
// Andrà tutto in segmentation fault. Fidati.
/*
int	main(void)
{
	char	c;
	int		x;
	char	*str;

	c = 'A';
	x = -42;
	str = "Vincere e vinceremo";
	printf("Char:%c\n Int:%d\n Char *:%s\n", c, x, str);
	printf("Stringa custom: \n");
	ft_printf("Char:%c\n Int:%d\n Char *:%s\n", c, x, str);
	return (0);
}
*/

int	ft_printf(const char *str, ...)
{
	int		index;
	va_list	ptr;

	index = 0;
	va_start(ptr, str);
	while (str[index] != '\0')
	{
		if ((str[index] == '%') && (str[index + 1] != '\0'))
		{
			if (type_print(str[++index], ptr) == 1)
				print("/UNKNOWN SPECIFIER/");
		}
		else
			write(1, &str[index], 1);
		++index;
	}
	va_end(ptr);
	return (1);
}

int	type_print(char type, va_list ptr)
{
	char	c;
	char	*s;
	int		d;

	if (type == 'c')
	{
		c = (char)va_arg(ptr, int);
		write(1, &c, 1);
	}
	else if (type == 's')
	{
		s = (char *)va_arg(ptr, char *);
		print(s);
	}
	else if (type == 'd')
	{
		d = (int)va_arg(ptr, int);
		ft_putnbr(d);
	}
	else
		return (1);
	return (0);
}

// Niente malloc: non sempre è concesso usarlo.
// Se lo vuoi usare, usa size_num + 2 come dimensione.
void	ft_putnbr(int num)
{
	char	str[12];
	int		temp_num;
	int		index;

	index = 0;
	if (num < 0)
		str[index++] = '-';
	if (num == 0)
		str[index] = '0';
	temp_num = num;
	while ((temp_num > 9) || (temp_num < -9))
	{
		index++;
		temp_num /= 10;
	}
	str[index + 1] = '\0';
	while (num != 0)
	{
		if (num < 0)
			str[index--] = (((num % 10) * -1) + 48);
		else
			str[index--] = ((num % 10) + 48);
		num /= 10;
	}
	print(str);
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

#endif