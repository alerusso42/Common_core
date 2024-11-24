/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:43 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 12:21:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int main()
{
    printf("%s\n", ft_strchr("Mega_rayquaza", 'w'));
    return (0);
}