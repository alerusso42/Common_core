/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:47:18 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 12:25:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <malloc.h>

void    *ft_memmove(void *dest, const void *src, size_t n);
char    *ft_strcpy(char *dst, const char *src);

int main(int argc, char *argv[])
{
    char    *destination;
    char    *source;
    size_t  n;
    
    if (argc < 3)
    {
        ft_printf("INSERISCI: \nargv[1] = dest;\n");
        ft_printf("argv[2] = source\n");
        ft_printf("argv[3] = n bytes da muovere.\n");
        
        
        return (42);
    }
    source = argv[2];
    if (atoi(argv[3]) < 0)
    {
        ft_printf("Allora, qui non siamo in villaggio ");
        ft_printf("turistico, e tu non fai ridere.\n");
        return (42);
    }
    n = (size_t)atoi(argv[3]);
    destination = (char *)malloc(8 * sizeof(char));
    destination = ft_strcpy(destination, argv[1]);
    destination = (char *)ft_memmove((void *)destination, (const void *)source, n);
    ft_printf("\n%s\n", destination);
    free(destination);
    return (0);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char    *dest_ptr;
    unsigned char    *src_ptr;

    dest_ptr = (unsigned char *)dest;
    src_ptr = (unsigned char *)src;
    if ((src == dest) || (n == 0))
        return (dest);
    if (dest < src)
    {
        while (n--)
            *dest_ptr++ = *src_ptr++;
        return (dest);
    }
    if (dest > src)
    {
        *dest_ptr += n;
        *src_ptr += n;
        while (n--)
            *(--dest_ptr) = *(--src_ptr);
        return (dest);
    }
    else
        return (dest);
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
