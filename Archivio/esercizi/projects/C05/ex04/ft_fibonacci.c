/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/13 11:14:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_fibonacci(int index);
/*
int main(int argc, char *argv[])
{
    int index;

    if (argc != 2)
    {
        printf("Arg[1] = index sequenza fibonacci\n");
        return (42);
    }
    index = atoi(argv[1]);
    printf("Il %d° elemento della sequenza è: ", index);
    printf("%d\n", ft_fibonacci(index));
    return (0);
}*/

int	ft_fibonacci(int index)
{
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index < 0)
		return (-1);
	return ((ft_fibonacci(index - 1)) + (ft_fibonacci(index - 2)));
}
