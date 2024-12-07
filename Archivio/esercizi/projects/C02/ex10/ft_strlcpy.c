/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:02:21 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/25 18:02:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bsd/string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
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
	while (src[++i] && i < j - 1)
	{
		dest[i] = src[i];
	}
	if (i < j)
		dest[i] = '\0';
	return (src_len);
}
/*
int    main(void)
{
    char    	src[] = "";
    char    	dest[10];
    unsigned int	size = 3;
	
	printf("Prima della modifica: ");
    	printf("Size: %u\n", size);
    	printf("Src: %s\n", src);
   	printf("Dest: %s\n", dest);
    	printf("Strlcpy di Temu: ");
    	printf("%u\n", ft_strlcpy(dest, src, size));
    	printf("Size: %u\n", size);
   	printf("Src: %s\n", src);
   	printf("Dest: %s\n", dest);
    return (0);
}*/
