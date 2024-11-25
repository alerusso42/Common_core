/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:37:29 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:21:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void ft_bzero(void *s, size_t n);

void ft_bzero(void *s, size_t n)
{
    char    *string_pointer;
    int     stop_process;
    
    string_pointer = (char *)s;
    stop_process = 0;
    while (stop_process != (int)n)
    {
        string_pointer[stop_process] = 0;
        ++stop_process;
    }
}