/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/20 20:35:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		++s;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

/*
int main()
{
    printf("%s\n", ft_strchr("Mega_rayquaza", 'w'));
    return (0);
}*/
