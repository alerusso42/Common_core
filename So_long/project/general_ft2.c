/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ft2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:33:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 11:17:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"
/*
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;

	pointer = NULL;
	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	ft_memset((void *)pointer, total_size);
	return (pointer);
}


	
*/
// This strlen stops when finds \n or \0.
size_t	ft_strlen_newline(char *string)
{
	size_t	size;

	if (!string)
		return (0);
	size = 0;
	while ((string[size]) && (string[size] != '\n'))
		++size;
	return (size);
}
/*
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[i++])
		++src_len;
	if (size == 0)
	{
		return (src_len);
	}
	i = 0;
	while ((src[i]) && (i < (size - 1)))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return ((size_t)src_len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*stock_ptr;
	unsigned char	casted_c;

	stock_ptr = NULL;
	casted_c = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == casted_c)
		{
			stock_ptr = (unsigned char *)s;
		}
		++s;
	}
	if (casted_c == 0)
		stock_ptr = (unsigned char *)s;
	return ((char *)stock_ptr);
}
*/
