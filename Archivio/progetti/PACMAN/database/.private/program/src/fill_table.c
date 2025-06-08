/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:17:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/05 14:38:04 by codespace        ###   ########.fr       */
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
