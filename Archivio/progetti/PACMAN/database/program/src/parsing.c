/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:49:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/05 01:19:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_float(t_data *data, char *str, double *result);
int		num_size(int n);
int		file_size(t_data *data);
int		count_char(char *str, char c);

void	parse_args(t_data *data, char *argv[])
{
	long long int	atoi_check;
	double			hash_size_modifier;

	data->data_fd = openfd(argv[1], "r");
	if (!data->data_fd.n)
		error(data, ER_OPEN);
	data->hash_fd = openfd(argv[2], "w");
	if (!data->data_fd.n)
		error(data, ER_OPEN);
	atoi_check = ft_atoi(argv[3]);
	if (atoi_check > INT_MAX || atoi_check < INT_MIN)
		error(data, ER_ATOI);
	data->file_num = (int)atoi_check;
	ft_strlcpy(data->separator, argv[4], 2);
	data->flags = argv[5];
	if (!data->separator[0] || !data->flags[0])
		error(data, ER_ATOI);
	make_float(data, argv[6], &hash_size_modifier);
	data->hash_size = file_size(data) * hash_size_modifier;
	if (!data->hash_size)
		error(data, ER_ATOI);
}

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

int		file_size(t_data *data)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		line_num;

	line_num = 0;
	bytes_read = readfd(data->data_fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = 0;
		line_num += count_char(buffer, '\n');
		bytes_read = readfd(data->data_fd, buffer, BUFFER_SIZE);
	}
	reset_fd(data->data_fd);
	return (line_num + 1);
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
