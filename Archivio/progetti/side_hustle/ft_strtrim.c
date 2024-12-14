/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:21:09 by negambar          #+#    #+#             */
/*   Updated: 2024/12/14 16:56:15 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gioco.h"
#include <stdio.h>

char	*strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;

	start = 0;
	len = strlen((char *)s1);
	if (s1 == NULL)
		return (NULL);
	while (s1[start] && strchr(set, s1[start]))
	{
		start++;
	}
	if (start == len)
	{
		return (strdup(""));
	}
	while (len > 0 && strchr(set, s1[len - 1]))
	{
		len--;
	}
	return (substr(s1, start, len - start));
}

char	*fun(unsigned int start, unsigned int lent, size_t len, const char *s)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (start >= lent)
	{
		str = (char *)malloc(1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	if (len > lent - start)
		len = lent - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	lent;

	lent = strlen(s);
	if (s == NULL)
		return (NULL);
	return (fun(start, lent, len, s));
}

char	*ft_strchr1(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (strdup((char *)&s[i]));
		i--;
	}
	return (NULL);
}
