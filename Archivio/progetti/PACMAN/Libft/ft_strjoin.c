/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:36:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/17 21:25:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*stringona;
	int		index;
	int		size;

	if ((!s1) || (!s2))
		return (NULL);
	index = 0;
	while (s1[index])
		++index;
	size = index;
	index = 0;
	while (s2[index])
		++index;
	size += index;
	stringona = NULL;
	stringona = (char *)ft_calloc(size + 1, 1);
	if (!stringona)
		return (NULL);
	index = 0;
	stringona[0] = 0;
	while (*s1)
		stringona[index++] = *s1++;
	while (*s2)
		stringona[index++] = *s2++;
	return (stringona);
}

/*
int	main(int argc, char *argv[])
{
	char	*s1;
	char	*s2;
	char	*stringona;

	if (argc < 3)
	{
		printf("s1 = argv[1]; s2 = argv[2]");
		return (42);
	}
	s1= argv[1];
	s2 = argv[2];
	stringona = ft_strjoin(s1, s2);
	printf("\n STRINGHE\ns1: %s;\ns2: %s\n", s1, s2);
	printf("\n STRINGONA:%s\n", stringona);
	return (0);
}
*/
