/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:33:08 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 13:21:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
