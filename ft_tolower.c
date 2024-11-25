/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:33:08 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:25:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int ft_tolower(int c);

int ft_tolower(int c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return (c + 32);
    return (c);
}

/*
int main(int argc, char *argv[])
{
    if (argc < 2)
        return (42);
    printf("%c\n", ft_tolower(argv[1][0]));
    return (0);
}*/
