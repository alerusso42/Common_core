/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:27:17 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/29 11:07:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include "libft.h"
#define TRUE 1
#define FALSE 0

static int	ft_strchr_boolean(const char *s, int c);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		starting_point;
	size_t	len;
	char	*trimmered_string;

	if ((!s1))
		return (NULL);
	if ((!set) || (*set == '\0') || (*s1 == '\0'))
		return (ft_strdup(s1));
	starting_point = 0;
	len = ft_strlen(s1);
	while ((s1[starting_point])
		&& (ft_strchr_boolean(set, s1[starting_point]) == TRUE))
		++starting_point;
	if (starting_point == (int)len)
		return (ft_strdup("\0"));
	while ((len > 0) && (ft_strchr_boolean(set, s1[len - 1]) == TRUE))
		--len;
	trimmered_string = ft_substr(s1, starting_point, len - starting_point);
	if (!trimmered_string)
		return (NULL);
	return (trimmered_string);
}

static int	ft_strchr_boolean(const char *s, int c)
{
	if (!s)
		return (FALSE);
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (TRUE);
		}
		++s;
	}
	if (c == 0)
		return (TRUE);
	return (FALSE);
}

/*
int	main(int argc, char *argv[])
{
	char	*s1;
	char	*s2;
	char	*stringhina;

	if (argc < 3)
	{
		printf("s1 = argv[1]; set = argv[2]");
		return (42);
	}
	s1= argv[1];
	s2 = argv[2];
	stringhina = ft_strtrim(s1, s2);
	printf("\n STRINGHE\ns1: %s;\nset: %s\n", s1, s2);
	printf("\n STRINGHINA:%s\n", stringhina);
	return (0);
}*/
