/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:52 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 12:19:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *ft_memchr(const void *s, int c, size_t n);

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   *string;
    
    string = (unsigned char *)s;
	if (c == '\0')
		return ((void *)string);
    while ((*string != '\0') && (n--))
    {
        if (*string == c)
		{
        	return ((void *)string);
		}
		string++;
    }
    if (c == 0)
        return ((void *)string);
    return (NULL);
}

int main()
{
    printf("%s\n", (char *)ft_memchr("Mega_rayquaza", '\0', 2));
    return (0);
}