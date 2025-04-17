/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/17 21:20:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	byte;

	string = (unsigned char *)s;
	byte = (unsigned char)c;
	while ((string) && (n--))
	{
		if (*string == byte)
		{
			return ((void *)string);
		}
		string++;
	}
	return (NULL);
}

/*
int main()
{
    printf("%s\n", (char *)ft_memchr("Mega_rayquaza", '\0', 2));
    return (0);
}*/
