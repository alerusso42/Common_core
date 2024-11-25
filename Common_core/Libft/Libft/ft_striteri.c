/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:25:16 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:31:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include "libft.h"
#define UN_BOTTO 100

void ft_striteri(char *s, void (*f)(unsigned int, char*));

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s);
		i++;
	}
	s[i] = '\0';
}

void	ft_uppercharacter(unsigned int index, char *c)
{
	c += index;
    if ((*c >= 'a') && (*c <= 'z') && (*c != '\0'))
        *c -= 32;
}

int	main()
{	
	char	*s;

	s = (char *)malloc(UN_BOTTO);
	if (!s)
		return (2);
	ft_strlcpy(s, "dslknsdlfbnwdljkfbwlfblsbf", UN_BOTTO);
	printf("\nStringa iniziale: \"%s\"\n", s);
	ft_striteri(s, *ft_uppercharacter);
	printf("Risultato: \"%s\"\n", s);
	free(s);
	return (0);
}
