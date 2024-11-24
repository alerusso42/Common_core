/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:05:17 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 11:20:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#define FULL_MEMORY 2

void *ft_calloc(size_t nmemb, size_t size);
char *ft_strcpy(char *dst, const char *src);
void *ft_memset(void *s, int c, size_t n);

int	main()
{
	char	*pointer;

	pointer = (char *)ft_calloc(7, 0);
	if (pointer == NULL)
		return (FULL_MEMORY);
	pointer = ft_strcpy(pointer, "sdv");
	printf("\n%s\n", pointer);
	free(pointer);
	return (0);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;

	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	else
	{
		ft_memset(pointer, 0, nmemb);
		return (pointer);
	}
}

void *ft_memset(void *s, int c, size_t n)
{
    char    *string_pointer;
    size_t    len;

    string_pointer = (char *)s;
    len = 0;
    while (string_pointer[len])
        ++len;
    while ((n--) && (len--))
    {
        *string_pointer++ = (unsigned char)c;
    }
    return (s);
}

char    *ft_strcpy(char *dst, const char *src)
{
	int		i;
    
	i = -1;
	while (src[++i])
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (dst);
}
