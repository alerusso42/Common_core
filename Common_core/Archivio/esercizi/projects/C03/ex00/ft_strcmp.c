/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:42:32 by alerusso          #+#    #+#             */
/*   Updated: 2024/08/02 15:42:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s)
{
	int		i;
	int		is_different;
	char	cmp;
	int	to_return;

	i = -1;
	is_different = 0;
	while ((s1[++i] || s[i]) && is_different == 0)
	{
		if (s1[i] != s[i])
			is_different = 1;
		if (is_different == 1)
			cmp = s1[i] - s[i];
	}
	i = 0;
	if (s1[i] == 0 || s[i] == 0)
		cmp = s1[i] - s[i];
	to_return = cmp - '\0';
	return (to_return);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Inserire le due stringhe come argomenti.(Gabibbo)");
		return (42);
	}
	if (argc == 42)
	{
		printf("Pisa merda");
		return (42);
	}
	printf("Funzione originale: %d", strcmp(argv[1], argv[2]));
	printf("\nFunzione fake: %d", ft_strcmp(argv[1], argv[2]));
	return (0);
}*/
