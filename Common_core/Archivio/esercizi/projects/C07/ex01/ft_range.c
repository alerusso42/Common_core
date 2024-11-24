/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/15 11:25:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int	*ft_range(int min, int max);
/*
int main(int argc, char *argv[])
{
    int min;
    int max;

	if (argc != 3)
	{
		printf("argv[1] = min, argv[2] = max\n");
		return (42);
	}
    min = atoi(argv[1]);
    max = atoi(argv[2]);
	printf("Intervallo: %d - %d\n", min, max);
    printf("Elenco:\n");
    ft_range(min, max);
	return (0);
}*/

int	*ft_range(int min, int max)
{
	unsigned int	froakie;
	int				i;
	int				*camillo;

	if (max <= min)
		return (NULL);
	froakie = max - min;
	camillo = (int *)malloc(froakie * sizeof(int));
	if (camillo == NULL)
		return (NULL);
	i = 0;
	while (froakie-- > 0)
	{
		camillo[i] = min + i;
		if (i == 2147483647)
		{
			min = 0;
			i = -1;
		}
		++i;
	}
	camillo[i] = min + i;
	return (camillo);
}
