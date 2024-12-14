/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:31:08 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/14 14:26:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	calc_size(char *string, t_printdata *data, size_t *size);
static void		print_result(const char *string, t_printdata *data, size_t len);
static char		*ft_hex_address(unsigned long long int num);
static void		ft_rev_int_tab(char *tab, int size);

static void	ft_rev_int_tab(char *tab, int size)
{
	int	i;
	int	t;

	i = 0;
	while (i < size / 2)
	{
		t = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = t;
		i++;
	}
}

// t_address = unsigned long long int
static char		*ft_hex_address(t_address num)
{
	char	*base;
	char	*conv_num;
	size_t	index;

	base = ft_calloc(17, 1);
	if (!base)
		return (NULL);
	conv_num = ft_calloc(50, 1);
	if (!conv_num)
		return (NULL);
	base = (char *)ft_memcpy((void *)base, (void *)"0123456789abcdef", 16);
	index = 0;
	conv_num[index] = '0';
	while (num)
	{
		conv_num[index] = base[num % 16];
		num /= 16;
		++index;
	}
	ft_rev_int_tab(conv_num, index);
	free(base);
	return (conv_num);
}

// t_address = unsigned long long int
size_t	print_address(t_address num, t_printdata *data)
{
	size_t	size;
	size_t	len;
	char	*string;

	if (num == 0)
		return (print_string("(nil)", data));
	size = 0;
	string = ft_hex_address(num);
	if (!string)
		return (0);
	len = calc_size(string, data, &size);
	if ((data->is_minus_flag) && (len))
		print_result(string, data, len);
	if (data->is_width)
		write_flags(data->width_value, SPACES);
	if (data->is_zero_flag)
		write_flags(data->width_value, ZEROS);
	if (data->is_precision)
		write_flags(data->precision_length, PRECISION);
	if (!(data->is_minus_flag) && (len))
		print_result(string, data, len);
	free(string);
	return (size);
}

static size_t	calc_size(char *string, t_printdata *data, size_t *size)
{
	size_t	len;

	len = ft_strlen(string);
	*size = len;
	if ((*string != '0') && (data->is_alt_form))
		*size += 2;
	if (((data->is_space_flag) || (data->is_expsign_flag)))
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

static void	print_result(const char *string, t_printdata *data, size_t len)
{
	if (data->is_space_flag)
		write(1, " ", 1);
	if (data->is_expsign_flag)
		write(1, "+", 1);
	if ((len) && (*string != '0'))
		write(1, "0x", 2);
	write(1, string, len);
}