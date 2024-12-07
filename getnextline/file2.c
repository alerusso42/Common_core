/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:30:12 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/07 18:24:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	size_t	stop_process;
	char	*string_pointer;
	void	*pointer;

	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (!pointer)
		return (NULL);
	string_pointer = (char *)pointer;
	stop_process = -1;
	while (++stop_process != total_size)
		string_pointer[stop_process] = 0;
	return (pointer);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	void	*pointer;

	if ((!dest) && (!src))
		return (NULL);
	pointer = dest;
	while ((n-- > 0) && (dest + 1) && (src + 1))
	{
		*((char *)dest) = *((char *)src);
		++dest;
		++src;
	}
	*((char *)dest) = 0;
	return (pointer);
}

int	find_end_line(size_t *start, char *string)
{
	int	save;
	int	index;
	
	save = -1;
	index = *start;
	while (index >= 0)
	{
		if ((string[index] == '\n') || (string[index] == '\n'))
			save = index;
		index -= 1;
	}
	if (save == -1)
		return (EOF_OR_NEWLINE_NOT_FOUND);
	*start = (size_t)save;
	return (EOF_OR_NEWLINE_FOUND);
}

int	alloc_ft(void **content, void *new_content, size_t start, int mode)
{
	size_t	nmemb;
	void	*re_content;

	nmemb = (start + 1);
	if (mode == MALLOC)
	{
		*content = ft_calloc((nmemb + 1) * 2, sizeof(char));
		if (!(*content))
			return (FULL_MEMORY);
		return (ALLOCATION_SUCCESS);
	}
	if (mode == REALLOC)
	{
		re_content = ft_calloc((nmemb) * 2, sizeof(char));
		if (!(re_content))
			return (FULL_MEMORY);
		ft_memcpy(re_content, new_content, nmemb * sizeof(char));
		free(*content);
		*content = re_content;
		return (ALLOCATION_SUCCESS);
	}
	if ((mode == FREE) && (*content))
		free(*content);
	*content = NULL;
	return (-1);//allocation_success
}

void trim_readbytes(char *buffer) 
{
	int old_index;
    int new_index;
	
    if (!buffer)
	{
        return ;
	}
	old_index = 0;
	new_index = 0;
    while (buffer[old_index] != '\0' && buffer[old_index] != '\n') 
	{
        ++old_index;
    }
    if (buffer[old_index] == '\n') 
	{
        ++old_index;
    }
    while (buffer[old_index] != '\0') 
	{
        buffer[new_index++] = buffer[old_index++];
    }
    buffer[new_index] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*stringona;
	int		index;
	int		size;

	if ((!s1) || (!s2))
		return (NULL);
	index = -1;
	while (s1[++index]);
	size = index;
	index = -1;
	while (s2[++index]);
	size += index;
	stringona = (char *)ft_calloc(size + 1, 1);
	if (!stringona)
		return (NULL);
	index = -1;
	while (s1[++index])
		stringona[index] = s1[index];
	size = -1;
	while (s2[++size])
		stringona[index++] = s2[size];
	free(s1);
	free(s2);
	return (stringona);
}
