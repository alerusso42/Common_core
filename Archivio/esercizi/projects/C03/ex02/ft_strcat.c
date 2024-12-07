/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:44:08 by alerusso          #+#    #+#             */
/*   Updated: 2024/08/02 15:44:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_strcpy(char *dest, char *dest_copy, char *argv)
{
	int	i;

	i = -1;
	if (argv[0] == '\0')
	{
		dest[0] = '\0';
		dest_copy[0] = '\0';
	}
	else
	{
		while (argv[++i])
		{
			dest[i] = argv[i];
			dest_copy[i] = argv[i];
		}
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	len_dest;
	int	i;

	i = 0;
	len_dest = -1;
	while (dest[++len_dest])
	{
	}
	i = -1;
	while (src[++i])
	{
		dest[len_dest] = src[i];
		++len_dest;
	}
	dest[len_dest] = '\0';
	return (dest);
}
/*
int    main(int argc, char *argv[])
{
	char			dest[70];
	char			dest_copy[70];
	
	if (argc == 42)
    {
        printf("Pisa merda");
        return (42);
    }
    if (argc != 3)
    {
        printf("Inserire dest, src. (e i 3 numerini dietro la carta)");
        return (42);
    }
	ft_strcpy(dest, dest_copy, argv[1]);
    printf("Funzione fake: %s", ft_strcat(dest, argv[2]));
    printf("\nFunzione originale: %s", strcat(dest_copy, argv[2]));
    return (0);
}*/
