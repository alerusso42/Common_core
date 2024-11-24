/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:05:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 13:20:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

char	*ft_strdup(const char *str);

/*
int main(int argc, char *argv[])
{
    char    *string1;
    char    *string2;
    
	if (argc != 2)
	{
		printf("Fai schifo;\n");
		return (42);
	}
	printf("Stringa originale: %s\n", argv[1]);
	string1 = strdup(argv[1]);
    printf("strdup: %s\n", string1);	
	string2 = ft_strdup(argv[1]);
    printf("fake: %s\n", string2);
    free(string1);
    free(string2);
	return (0);
}*/
//duplica una stringa usando la giusta memoria con malloc

char	*ft_strdup(const char *str)
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
