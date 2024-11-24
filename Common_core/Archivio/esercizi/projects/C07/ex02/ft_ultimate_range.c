/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/15 11:47:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int	ft_ultimate_range(int **range, int min, int max);
/*
int main(int argc, char *argv[])
{
    int min;
    int max;
    int *camillo;
    int i;
    int size_camillo;

	if (argc != 3)
	{
		printf("argv[1] = min, argv[2] = max\n");
		return (42);
	}
    min = atoi(argv[1]);
    max = atoi(argv[2]);
    size_camillo = 0;
	printf("Intervallo: %d - %d\n", min, max);
    printf("Elementi: ");
    camillo = NULL;
    size_camillo = ft_ultimate_range(&camillo, min, max);
    printf("%d.\n",size_camillo);
    i = 0;
    printf("Elenco:\n");
    if ((camillo == NULL) || (size_camillo <= 0))
        return (42);
    printf("%d,", camillo[i]);
    while (++i < size_camillo)
    {
    }
    printf("%d.\n", camillo[--i]);
    free(camillo);
	return (0);
}*/

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(size * sizeof(int));
	if (range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		++i;
	}
	return (size);
}
