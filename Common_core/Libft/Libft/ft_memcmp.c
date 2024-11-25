/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:49 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:23:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	char	cmp;
	int		temp_n;
	char	*s1_pointer;
	char	*s2_pointer;

	i = -1;
	cmp = 0;
	temp_n = n;
	s1_pointer = (char *)s1;
	s2_pointer = (char *)s2;
	while ((s1_pointer[++i] || s2_pointer[i]) && (cmp == 0) && (temp_n != 0))
	{
		if (s1_pointer[i] != s2_pointer[i])
			cmp = s1_pointer[i] - s2_pointer[i];
		temp_n -= 1;
	}
	i = 0;
	if (s1_pointer[i] == 0 || s2_pointer[i] == 0)
		cmp = s1_pointer[i] - s2_pointer[i];
	return ((int)cmp);
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
