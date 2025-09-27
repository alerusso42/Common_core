/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:49 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/17 21:20:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_pointer;
	unsigned char	*s2_pointer;

	s1_pointer = (unsigned char *)s1;
	s2_pointer = (unsigned char *)s2;
	while ((s1_pointer) && (s2_pointer) && (n--))
	{
		if (*s1_pointer != *s2_pointer)
		{
			if (*s1_pointer > *s2_pointer)
				return (1);
			return (-1);
		}
		++s1_pointer;
		++s2_pointer;
	}
	return (0);
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Inserisci le 2 stringhe, poi il numero di confronti da fare");
		return (42);
	}
	if (argc == 42)
	{
		printf("Pisa merda");
		return (42);
	}
	int n = argv[3][0] - '0';
	printf("Funzione fake: %d", ft_memcmp(argv[1], argv[2], n));
	return (0);
}*/
