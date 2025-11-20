/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:05:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/20 22:43:39 by alerusso         ###   ########.fr       */
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
	camillo = (char *)CALLOC(n + 1, sizeof(char));
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

t_str	*str_sdup_char(t_str *this, const char *other)
{
	int	i;
	int	j;

	if (!other)
	{
		FREE(this->buff);
		this->buff = NULL;
		this->capacity = 0;
		this->len = 0;
		return (this);
	}
	i = ft_strlen(other);
	this->len = i;
	if (this->capacity < i)
		if (_str_reset(this, i)->err != 0)
			return (this);
	i = 0;
	j = 0;
	while (other[j])
		this->buff[i++] = other[j++];
	this->buff[i] = 0;
	return (this);
}

t_str	*str_sdup_str(t_str *this, t_str *other)
{
	int	i;
	int	j;

	if (!other->buff)
	{
		FREE(this->buff);
		this->buff = NULL;
		this->capacity = 0;
		this->len = 0;
		return (this);
	}
	i = other->len;
	this->len = i;
	if (this->capacity < i)
		if (_str_reset(this, i)->err != 0)
			return (this);
	i = 0;
	j = 0;
	while (other->buff[j])
		this->buff[i++] = other->buff[j++];
	this->buff[i] = 0;
	return (this);
}
