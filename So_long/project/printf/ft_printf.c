/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 15:57:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	end_print(const char *s, t_printdata *data, va_list ptr, size_t c);
static int	type_print(char type, va_list ptr, size_t *counter, \
t_printdata *data);

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
*//*
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
}*/

// with bonus!
int	ft_printf(const char *str, ...)
{
	size_t			index;
	size_t			counter;
	va_list			ptr;
	t_printdata		*data;

	index = -1;
	counter = 0;
	data = NULL;
	va_start(ptr, str);
	while ((str) && (str[++index] != '\0'))
	{
		if ((str[index] == '%') && (str[index + 1] != '\0'))
		{
			if (validate_struct(str, &data, &index) == ERROR)
				counter += go_next(str, &index);
			else
				type_print(str[index], ptr, &counter, data);
		}
		else
		{
			write(1, &str[index], 1);
			++counter;
		}
	}
	return (end_print(str, data, ptr, counter));
}

static int	end_print(const char *s, t_printdata *data, va_list ptr, size_t c)
{
	if (data)
		free(data);
	va_end(ptr);
	if (!s)
		return (-1);
	return (c);
}

static int	type_print(char type, va_list ptr, size_t *counter, \
t_printdata *data)
{
	if (type == 'c')
		*counter += print_char((unsigned char)va_arg(ptr, int), data);
	else if (type == 's')
		*counter += print_string((t_uchar *)va_arg(ptr, t_uchar *), data);
	else if ((type == 'd') || (type == 'i'))
		*counter += print_signed_int((int)va_arg(ptr, int), data);
	else if (type == 'u')
		*counter += print_unsigned_int((size_t)va_arg(ptr, size_t), data);
	else if (type == 'x')
		*counter += print_lower_hex((size_t)va_arg(ptr, size_t), data);
	else if (type == 'X')
		*counter += print_upper_hex((size_t)va_arg(ptr, size_t), data);
	else if (type == 'p')
		*counter += print_address((void *)va_arg(ptr, void *), data);
	else if (type == '%')
		*counter += write(1, "%%", 1);
	else
		return (ERROR);
	return (0);
}
