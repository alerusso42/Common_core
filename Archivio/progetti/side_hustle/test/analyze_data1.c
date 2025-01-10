/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_data1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:48:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/10 02:34:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*(get_char(type, data_name, fd, filename)*/

void	*get_char(char *type, char *data_name, int fd, char *filename)
{
	unsigned char	unsigned_char;
	char			regular_char;
	char			*buffer;
	char			*object_name;
	int				line_num;

	object_name = set_object_name(NULL, 1);
	if (*type == 'u')// Se il tipo e unsigned 
	{
		unsigned_char = 0;
		line_num = find_number_line(fd, filename, 2, object_name, data_name);
		if (line_num < 0)
		{
			return ((void *)unsigned_char);
		}
		buffer = read_line(fd, filename, line_num, 1);
		if (!buffer)
		{
			return ((void *)unsigned_char);
		}
		unsigned_char = *buffer;
		free(buffer);
		return ((void *)unsigned_char);
	}
}