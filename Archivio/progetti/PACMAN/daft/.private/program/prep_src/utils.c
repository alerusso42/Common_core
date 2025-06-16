/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:33:07 by codespace         #+#    #+#             */
/*   Updated: 2025/06/16 17:40:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_float(t_data *data, char *str, double *result)
{
	long long int	atoi_check;
	int				dot_i;
	int				decimal_part;

	atoi_check = 0;
	dot_i = sub_strlen(str, ".", EXCLUDE);
	if (str[dot_i])
		atoi_check = ft_atoi(str + dot_i + 1);
	if (atoi_check > INT_MAX || atoi_check < INT_MIN)
		error(data, ER_ATOI);
	decimal_part = atoi_check;
	str[dot_i] = 0;
	atoi_check = ft_atoi(str);
	if (atoi_check > INT_MAX || atoi_check < INT_MIN)
		error(data, ER_ATOI);
	*result = atoi_check;
	dot_i = num_size(decimal_part);
	while (decimal_part)
	{
		*result += (decimal_part % 10) / (double)dot_i;
		decimal_part /= 10;
		dot_i /= 10;
	}
}

int	num_size(int n)
{
	int	i;

	i = 1;
	while (n)
	{
		n /= 10;
		i *= 10;
	}
	return (i);
}

int		count_char(char *str, char c)
{
	int	counter;

	counter = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			counter += 1;
		++str;
	}
	return (counter);
}

int	ft_abs(int n)
{
	if (n == INT_MIN)
		return (INT_MAX);
	if (n < 0)
		n *= -1;
	return (n);
}

void	find_lowest_key(t_data *data, int *lowest_key, int *struct_i)
{
	int	i;
	int	curr_lowest;
	int	curr_i;

	i = 1;
	curr_lowest = INT_MAX;
	curr_i = 0;
	while (i != data->hash_size)
	{
		if (data->hash_table[i].key && \
			data->hash_table[i].key < curr_lowest && \
			data->hash_table[i].key >= *lowest_key && \
			i != *struct_i && \
			collision_check(data, data->hash_table[i].key) == 0)
		{
			curr_lowest = data->hash_table[i].key;
			curr_i = i;
		}
		++i;
	}
	*lowest_key = curr_lowest;
	*struct_i = curr_i;
	if (curr_lowest == INT_MAX)
		*lowest_key = 0;
}
