/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:22:01 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/18 10:29:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	calc_size(t_uchar *string, t_printdata *data, size_t *size);

//*counter += print_t_uchar((t_uchar)va_arg(ptr, int), data);
size_t	print_string(t_uchar *string, t_printdata *data)
{
	size_t	size;
	size_t	limit_print;

	if (!string)
	{
		if ((data) && (data->is_precision) && (data->precision_length < 6))
			data->precision_length = 0;
		return (print_string((t_uchar *)"(null)", data));
	}
	size = 0;
	limit_print = calc_size(string, data, &size);
	if ((data->is_minus_flag) && (limit_print))
		write(1, string, limit_print);
	if (data->is_width)
		write_flags(data->width_value, SPACES);
	if (data->is_zero_flag)
		write_flags(data->width_value, ZEROS);
	if (!(data->is_minus_flag) && (limit_print))
		write(1, string, limit_print);
	return (size);
}

// ft_isprint_string(string);
static size_t	calc_size(t_uchar *string, t_printdata *data, size_t *size)
{
	size_t	limit_print;

	limit_print = ft_strlen((char *)string);
	*size = limit_print;
	if (data->is_precision)
	{
		if (data->precision_length > limit_print)
		{
			data->is_precision = 0;
		}
		else
		{
			limit_print = data->precision_length;
			*size = data->precision_length;
		}
	}
	if (((data->is_width_zero) && (data->width_value > *size)) || \
		((data->is_width) && (data->width_value > *size)))
	{
		data->width_value -= *size;
		*size += data->width_value;
	}
	else
		data->width_value = 0;
	return (limit_print);
}

/*
static size_t	ft_isprint_string(const t_uchar *string)
{
	size_t	len;
	size_t	print_counter;

	len = 0;
	print_counter = 0;
	while (string[len])
	{
		if (ft_isprint(string[len]))
		{
			++print_counter;
		}
		++len;
	}
	return (print_counter);
}*/
