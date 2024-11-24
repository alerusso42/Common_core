/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:42:19 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 12:22:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

void    *ft_memset(void *s, int c, size_t n);

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

/*
int main(int argc, char *argv[])
{
    char    *string;
    int     c;
    size_t  n;
    
    if (argc < 4)
    {
        ft_printf("INSERISCI: \nargv[1] = string;\n");
        ft_printf("argv[2] = set character;\n");
        ft_printf("argv[3] = n bytes da settare.\n");
        return (42);
    }
    if (atoi(argv[3]) < 0)
    {
        ft_printf("Allora, qui non siamo in villaggio ");
        ft_printf("turistico, e tu non fai ridere.\n");
        return (42);
    }
    string = argv[1];
    c = argv[2][0];
    n = (size_t)atoi(argv[3]);
    string = (char *)ft_memset((void *)string, c, n);
    ft_printf("\n%s\n", string);
    return (0);
}*/
