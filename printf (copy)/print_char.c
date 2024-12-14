/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:50:12 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/12 15:28:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	calc_size(char character, t_printdata *data, size_t *size);

//*counter += print_char((char)va_arg(ptr, int), data);
size_t	print_char(char character, t_printdata *data)
{
	size_t	size;
	size_t	limit_print;

	size = 0;
	limit_print = 0;
	limit_print += calc_size(character, data, &size);
	if ((data->is_minus_flag) && (ft_isprint(character)) && (limit_print))
		write(1, &character, 1);
	if (data->is_width)
		write_flags(data->width_value, SPACES);
	if (data->is_zero_flag)
		write_flags(data->width_value, ZEROS);
	if (!(data->is_minus_flag) && (ft_isprint(character)) && (limit_print))
		write(1, &character, 1);
	return (size);	
}

static size_t	calc_size(char character, t_printdata *data, size_t *size)
{
	size_t	limit_print;
	
	limit_print = 1;
	if (ft_isprint(character))
		*size += 1;
	else
		limit_print = 0;
	if (data->is_precision)
	{
		if (data->precision_length == 0)
		{
			limit_print = 0;
			*size = 0;
		}
	}
	if (((data->is_width_zero) && (data->width_value > *size)) || 
		((data->is_width) && (data->width_value > *size)))
		{
			data->width_value -= *size;
			*size += data->width_value;
		}
	return (limit_print);
}
