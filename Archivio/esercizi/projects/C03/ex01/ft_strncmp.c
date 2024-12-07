/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:43:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/08/02 15:43:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int		i;
	int		is_different;
	char		cmp;
	int		temp_n;
	int		to_return;

	i = -1;
	is_different = 0;
	temp_n = n;
	while ((s1[++i] || s2[i]) && is_different == 0 && temp_n != 0)
	{
		if (s1[i] != s2[i])
			is_different = 1;
		if (is_different == 1)
			cmp = s1[i] - s2[i];
		temp_n -= 1;
	}
	i = 0;
	if (s1[i] == 0 || s2[i] == 0)
		cmp = s1[i] - s2[i];
	to_return = cmp - '\0';
	return (to_return);
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
	printf("Funzione fake: %d", ft_strncmp(argv[1], argv[2], n));
	printf("\nFunzione originale: %d", strncmp(argv[1], argv[2], n));
	return (0);
}*/
