/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/14 16:51:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	printf("Printf vero: \n");
	printf("Char:%c\n Int:%d\n Char *:%s\n", c, x, str);
	printf("Printf custom: \n");
	ft_printf("Char:%c\n Int:%d\n Char *:%s\n", c, x, str);
	return (0);
}*/

int	ft_printf(const char *str, ...)
{
	size_t			index;
	size_t			counter;
	va_list			ptr;
	t_printdata		*data;

	index = 0;
	counter = 0;
	data = NULL;
	va_start(ptr, str);
	while (str[index] != '\0')
	{
		if ((str[index] == '%') && (str[index + 1] != '\0'))
		{
			if (validate_struct(str, &data, &index) == ERROR)
				counter = go_next(str, &index);
			else
				type_print(str[index], ptr, &counter, data);
		}
		else
		{
			write(1, &str[index], 1);
			++counter;
		}
		++index;
	}
	if (data)
		free(data);
	va_end(ptr);
	return (counter);
}

/*	unsigned int	is_minus_flag:1;
	unsigned int	is_alt_form:1;
	unsigned int	is_space_flag:1;
	unsigned int	is_expsign_flag:1;
	unsigned int	is_zero_flag:1;
	unsigned int	is_width:1;
	unsigned int	is_width_zero:1;
	unsigned int	width_value;
	unsigned int	is_precision:1;
	unsigned int	precision_length;
	void			*specifier;
	unsigned int	save_index_position;
*/
void	print_struct(t_printdata *data)
{
	printf("IS_MINUS FLAG: %d\n", data->is_minus_flag);
	printf("IS_ALT_FORM: %d\n", data->is_alt_form);
	printf("IS_SPACE_FLAG: %d\n", data->is_space_flag);
	printf("IS_EXPSIGN_FLAG: %d\n", data->is_expsign_flag);
	printf("IS_ZERO_FLAG: %d\n", data->is_zero_flag);
	printf("IS_WIDTH: %d\n", data->is_width);
	printf("IS_WIDTH_ZERO: %d\n", data->is_width_zero);
	printf("WIDTH_VALUE: %d\n", data->width_value);
	printf("IS_PRECISION: %d\n", data->is_precision);
	printf("PRECISION_LENGTH: %d\n\n", data->precision_length);
}

int		type_print(char type, va_list ptr, size_t *counter, t_printdata *data)
{
	if (type == 'c')
	{
		*counter += print_char((char)va_arg(ptr, int), data);
	}
	else if (type == 's')
	{
		*counter += print_string((char *)va_arg(ptr, char *), data);
	}
	else if ((type == 'd') || (type == 'i'))
	{
		*counter += print_signed_int((int)va_arg(ptr, int), data);
	}
	else if (type == 'u') 
	{
		*counter += print_unsigned_int((size_t)va_arg(ptr, size_t), data);
	}
	else if (type == 'x')
	{
		*counter += print_lower_hex((size_t)va_arg(ptr, size_t), data);
	}
	else if (type == 'X')
	{
		*counter += print_upper_hex((size_t)va_arg(ptr, size_t), data);
	}
	else if (type == 'p')
	{
		*counter += print_address((t_address)va_arg(ptr, t_address), data);
	}
	else if (type == '%')
	{
		*counter += write(1, "%%", 1);
	}
		return (ERROR);
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
void	print(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		++index;
	}
}
