/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:45 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/31 14:58:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	cut_string(char **string, size_t start, size_t end)
{
	unsigned int	temp;
	unsigned int	string_len;

	end++;
	if (!(string) || !(*string) || (start > end))
		return (1);
	string_len = 0;
	while ((*string)[string_len])
		++string_len;
	temp = start;
	while ((start != end) && ((*string)[start] != 0))
		(*string)[start++] = 0;
	end = start;
	start = temp;
	temp = 0;
	while (end != string_len)
	{
		(*string)[start + temp] = (*string)[end + temp];
		--string_len;
		++temp;
	}
	return (0);
}

char	*read_from_buffer(char buffer[BUFFER_SIZE + 1], int fd, int bytes)
{
	int		len;
	char	*bytes_read;
	int		index;

	bytes_read = (char *)malloc((bytes + 2) * sizeof(char));
	if ((!bytes_read) || (!bytes))
		return (NULL);
	len = 0;
	while (buffer[len] != 0)
		++len;
	index = 0;
	if ((!len) && (bytes--) && (read(fd, bytes_read + index++, 1) < 1))
		return (free(bytes_read), NULL);
	while ((bytes) && (len--))
	{
		bytes_read[index] = buffer[index];
		++index;
		--bytes;
	}
	if (index)
		cut_string(&buffer, 0, index - 1);
	while (bytes--)
		if (read(fd, bytes_read + index++, 1) < 1)
			break ;
	bytes_read[index] = 0;
	return (bytes_read);
}