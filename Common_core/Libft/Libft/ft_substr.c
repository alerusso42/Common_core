/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:13:25 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:25:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len);

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	int		index;
	int		substring_lenght;
	int		size;
	char	*substring;

	substring_lenght = 0;
	while (s[start + substring_lenght])
		++substring_lenght;
	substring_lenght += 1;
	if (substring_lenght < (int)len)
		size = substring_lenght;
	else
		size = (int)len;
	substring = (char *)malloc(size);
	if (!substring)
		return (NULL);
	index = -1;
	while (++index != size)
	{
		substring[index] = s[start + index];
	}
	return (substring);
}

int	main(int argc, char *argv[])
{
	char	*sub_string;
	int		start;
	size_t	len;
	
	if (argc < 4)
	{
		printf("1) STRINGA; 2) START 3) LEN");
		return (42);	
	}
	start = atoi(argv[2]);
	len = (int)atoi(argv[3]);
	sub_string = ft_substr(argv[1], start, len);
	printf("\n%s\n", sub_string),
	free(sub_string);
	return (0);
}