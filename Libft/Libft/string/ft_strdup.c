/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:05:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/15 17:00:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strdup(const char *str);

/*
int main(int argc, char *argv[])
{
    char    *string1;
    char    *string2;
    
	if (argc != 2)
	{
		printf("Fai schifo;\n");
		return (42);
	}
	printf("Stringa originale: %s\n", argv[1]);
	string1 = strdup(argv[1]);
    printf("strdup: %s\n", string1);	
	string2 = ft_strdup(argv[1]);
    printf("fake: %s\n", string2);
    free(string1);
    free(string2);
	return (0);
}*/
//duplica una stringa usando la giusta memoria con malloc

char	*ft_strdup(const char *str)
{
	int		n;
	char	*camillo;

	if (!str)
		return (NULL);
	n = 0;
	while (str[n] != '\0')
		++n;
	camillo = NULL;
	n += 1;
	camillo = (char *)CALLOC(n, sizeof(char));
	if (camillo == NULL)
		return (0);
	n = 0;
	while (str[n] != '\0')
	{
		camillo[n] = str[n];
		++n;
	}
	return (camillo);
}

t_str	*str_dup_char(t_str *this, const char *other)
{
	this->buff = (int8_t *)ft_strdup(other);
	return (this);
}

t_str	*str_dup_str(t_str *this, t_str *other)
{
	FREE(this->buff);
	this->buff = (int8_t *)ft_strdup((char *)other->buff);
	return (this);
}
