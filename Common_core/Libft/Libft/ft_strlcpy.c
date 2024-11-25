/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:29:30 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:25:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	int		src_len;

	j = size;
	i = -1;
	src_len = 0;
	while (src[++i])
		++src_len;
	i = -1;
	while (src[++i] && i < j)
	{
		dst[i] = src[i];
	}
	if (i < j)
		dst[i] = '\0';
	return ((size_t)i);
}

/*
int    main(int argc, char *argv[])
{
    char    *src;
    char    dest[50];
    size_t  size;

    if ((argc < 3) || atoi(argv[2]) < 0)
    {
        printf("argv[1]: source \nargv[2]: size\n");
        return (42);
    }
    src = argv[1];
    dest[0] = '\0';
    size = (size_t)atoi(argv[2]);
	printf("Prima della modifica: ");
        printf("Size: %zu\n", size);
        printf("Src: %s\n", src);
   	    printf("Dest: %s\n", dest);
    printf("\nStrlcpy di Temu: \n");
    	printf("Byte copiati: %zu\n", ft_strlcpy(dest, src, size));
    	printf("Size: %zu\n", size);
   	printf("Src: %s\n", src);
   	printf("Dest: %s\n", dest);
    return (0);
}*/
