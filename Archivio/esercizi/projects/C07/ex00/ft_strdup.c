/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/15 11:06:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

char	*ft_strdup(char *str);
/*
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Fai schifo;\n");
		return (42);
	}
	printf("Stringa originale: %s\n", argv[1]);
	printf("strdup: %s\n", strdup(argv[1]));	
	printf("fake: %s\n", ft_strdup(argv[1]));
	return (0);
}*/
//duplica una stringa usando la giusta memoria con malloc

char	*ft_strdup(char *str)
{
	int		n;
	char	*camillo;

	n = 0;
	while (str[n] != '\0')
		++n;
	camillo = (char *)malloc(n * sizeof(char));
	if (camillo == NULL)
		return (0);
	n = 0;
	camillo[n] = str[n];
	++n;
	while (str[n - 1] != '\0')
	{
		camillo[n] = str[n];
		++n;
	}
	return (camillo);
}
//uso do while perchè il primo carattere va sempre copiato