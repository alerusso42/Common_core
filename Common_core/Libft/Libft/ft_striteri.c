/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:25:16 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/23 14:53:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#define UN_BOTTO 100

void ft_striteri(char *s, void (*f)(unsigned int, char*));
static size_t  ft_strlcpy(char *dst, const char *src, size_t size);

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

void	ft_toupper(unsigned int index, char *c)
{
	c += index;
    if ((*c >= 'a') && (*c <= 'z') && (*c != '\0'))
        *c -= 32;
}

static size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	int		src_len;

	j = size;
	i = -1;
	src_len = 0;
	while (src[++i])
		++src_len;
	i = -1;
	while (src[++i] && i < j)
	{
		dst[i] = src[i];
	}
	if (i < j)
		dst[i] = '\0';
	return ((size_t)i);
}

int	main()
{	
	char	*s;

	s = (char *)malloc(UN_BOTTO);
	if (!s)
		return (2);
	ft_strlcpy(s, "dslknsdlfbnwdljkfbwlfblsbf", UN_BOTTO);
	printf("\nStringa iniziale: \"%s\"\n", s);
	ft_striteri(s, *ft_toupper);
	printf("Risultato: \"%s\"\n", s);
	free(s);
	return (0);
}
