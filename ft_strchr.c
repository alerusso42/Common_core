/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:43 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:24:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char *ft_strchr(const char *s, int c);

char *ft_strchr(const char *s, int c)
{
    while (*s++ != '\0')
    {
        if (*s == c)
        	return ((char *)s);
    }
    if (c == 0)
        return ((char *)s);
    return (NULL);
}

/*
int main()
{
    printf("%s\n", ft_strchr("Mega_rayquaza", 'w'));
    return (0);
}*/