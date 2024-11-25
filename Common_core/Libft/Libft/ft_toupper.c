/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:34:39 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:25:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int ft_toupper(int c);

int ft_toupper(int c)
{
    if ((c >= 'a') && (c <= 'z'))
        return (c - 32);
    return (c);
}

/*
int main(int argc, char *argv[])
{
    if (argc < 2)
        return (42);
    printf("%c\n", ft_toupper(argv[1][0]));
    return (0);
}*/