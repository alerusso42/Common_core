/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:06:42 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/23 14:26:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>

static size_t ft_strlen(const char *s)
{
	size_t	strlen;

	strlen = 0;
	while ((*s++ != '\0'))
		++strlen;
	return (strlen);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	i;
	char *s2;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static char	ft_toupper(unsigned int index, char c)
{
	if (index)
		++index;
    if ((c >= 'a') && (c <= 'z'))
        return (c - 32);
    return (c);
}

int	main()
{	
	char	*s = "JolL7y";

	printf("\nStringa iniziale: \"%s\"\n", s);
	s = ft_strmapi(s, *ft_toupper);
	printf("Risultato: \"%s\"\n", s);
	free(s);
	return (0);
}
