/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:31:02 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/14 14:47:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static size_t	calc_size(char *string, t_printdata *data, size_t *size);
static void	print_result(const char *string, t_printdata *data, size_t len);
static char	*ft_unsigned_itoa(unsigned int num);
static char	*alloc_string(char *allocated_string, size_t num, int *index);

size_t	print_unsigned_int(unsigned int num, t_printdata *data)
{
	size_t	size;
	size_t	len;
	char	*string;

	size = 0;
	string = ft_unsigned_itoa(num);
	if (!string)
		return (0);
	len = calc_size(string, data, &size);
	if ((data->is_minus_flag) && (len))
	{
		print_result(string, data, len);
	}
	if (data->is_width)
		write_flags(data->width_value, SPACES);
	if (data->is_zero_flag)
		write_flags(data->width_value, ZEROS);
	if (data->is_precision)
		write_flags(data->precision_length, PRECISION);
	if (!(data->is_minus_flag) && (len))
	{
		print_result(string, data, len);
	}
	free(string);
	return (size);
}

static size_t	calc_size(char *string, t_printdata *data, size_t *size)
{
	size_t	len;

	len = ft_strlen(string);
	*size = len;
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

static void	print_result(const char *string, t_printdata *data, size_t len)
{
	write(1, string, len);
}

static char	*ft_unsigned_itoa(unsigned int num)
{
	unsigned int	temp_num;
	int				index;
	char			*str;

	index = 0;
	temp_num = num;
	while (temp_num > 9)
	{
		index++;
		temp_num /= 10;
	}
	str = NULL;
	str = alloc_string(str, num, &index);
	if (!str)
		return (NULL);
	str[index + 1] = '\0';
	while (num != 0)
	{
		if (num < 0)
			str[index--] = (((num % 10) * -1) + 48);
		else
			str[index--] = ((num % 10) + 48);
		num /= 10;
	}
	return (str);
}

static char	*alloc_string(char *allocated_string, size_t num, int *index)
{
	allocated_string = (char *)ft_calloc((*index) + 2, sizeof(char));
	if (!allocated_string)
		return (NULL);
	if (num < 0)
	{
		allocated_string[0] = '-';
	}
	if (num == 0)
	{
		allocated_string[(*index)] = '0';
	}
	return (allocated_string);
}
