/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:50:52 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/25 17:51:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		i;
	int		j;

	j = n;
	i = -1;
	while (src[++i] && i != j)
		dest[i] = src[i];
	--i;
	while (++i != j)
		dest[i] = '\0';
	return (dest);
}
/*
int    main(void)
{
    char    src[] = "boiade";
    char    dest[4];

    *dest = *ft_strncpy(dest, src, 4);
    printf("%s\n", dest);
    return (0);
}*/
