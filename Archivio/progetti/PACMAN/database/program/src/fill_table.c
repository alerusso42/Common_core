/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:17:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/05 01:07:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_hash_table(t_data *data)
{
	char	*line;
	int		bytes_read;
	int		line_num;
	int		i;
	int		cursor;

	bytes_read = 0;
	line_num = 1;
	i = 0;
	cursor = 0;
	line = gnl();
	while (line)
	{
		bytes_read += ft_strlen(line);
		i = sub_strlen(line, data->separator, EXCLUDE);
		if (line[i])
		{
			data->hash_table[line_num].key = ft_hash(data, line);
			data->hash_table[line_num].pos = cursor;
		}
		cursor = bytes_read;
		++line_num;
		SDL_free(line);
		line = gnl();
	}
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
			data->hash_table[i].key > *lowest_key && \
			i != *struct_i)
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