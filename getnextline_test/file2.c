/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:30:12 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/03 15:16:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	size_t	stop_process;
	char	*string_pointer;
	void	*pointer;

	pointer = NULL;
	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (!pointer)
		return (NULL);
	string_pointer = (char *)pointer;
	stop_process = 0;
	while (stop_process != total_size)
	{
		string_pointer[stop_process] = 0;
		++stop_process;
	}
	return (pointer);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*pointer;

	if ((!dest) && (!src))
		return (NULL);
	pointer = dest;
	while ((n--) && (dest))
	{
		*((char *)dest) = *((char *)src);
		++dest;
		++src;
	}
	*((char *)++dest) = 0;
	return (pointer);
}