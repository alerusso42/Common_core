/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:06:28 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/14 15:10:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	calc_size(char *s, t_printdata *data, size_t *size, int num);
static void		print_r(const char *s, t_printdata *data, size_t len, int num);

size_t	print_signed_int(int num, t_printdata *data)
{
	size_t	size;
	size_t	len;
	char	*string;
	char	*save;

	size = 0;
	save = ft_itoa(num);
	string = ft_strtrim(save, "-");
	if (save)
		free(save);
	if (!string)
		return (0);
	len = calc_size(string, data, &size, num);
	if ((data->is_minus_flag) && (num < 0))
		write(1, "-", 1);
	print_r(string, data, len, num);
	free(string);
	return (size);
}

static size_t	calc_size(char *s, t_printdata *data, size_t *size, int num)
{
	size_t	len;

	len = ft_strlen(s);
	*size = len;
	if ((num < 0) || (data->is_space_flag) || (data->is_expsign_flag))
		*size += 1;
	if (data->is_precision)
	{
		if (data->precision_length > len)
		{
			data->precision_length -= len;
			*size += data->precision_length;
		}
		else if (data->precision_length < len)
			data->is_precision = 0;
	}
	if (((data->is_width_zero) && (data->width_value > *size)) || 
		((data->is_width) && (data->width_value > *size)))
		{
			data->width_value -= *size;
			*size += data->width_value;
		}
	return (len);
}

static void	print_r(const char *s, t_printdata *data, size_t len, int num)
{
	if ((data->is_minus_flag) && (len))
	{
		if ((data->is_space_flag) && (num > 0))
			write(1, " ", 1);
		if ((data->is_expsign_flag) && (num > 0))
			write(1, "+", 1);
		write(1, s, len);
	}
	if (data->is_width)
		write_flags(data->width_value, SPACES);
	if (!(data->is_minus_flag) && (num < 0))
		write(1, "-", 1);
	if (data->is_zero_flag)
		write_flags(data->width_value, ZEROS);
	if (data->is_precision)
		write_flags(data->precision_length, PRECISION);
	if (!(data->is_minus_flag) && (len))
	{
		if ((data->is_space_flag) && (num > 0))
			write(1, " ", 1);
		if ((data->is_expsign_flag) && (num > 0))
			write(1, "+", 1);
		write(1, s, len);
	}
}
