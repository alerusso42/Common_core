/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 18:04:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0 || !s1 || !s2)
		return (s1 > s2 - s1 < s2);
	while ((--n) && (*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
	{
		++s1;
		++s2;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int32_t	str_ncmp_char(t_str *this, char *other, int32_t n)
{
	register int32_t	n1;

	if (str_check(this, NULL) || n < 0)
		return (_str_set_error(this, E_PARAM, "ncmp"));
	n1 = this->i;
	while (n && this->buff[n1] && *other && this->buff[n1] == *other)
	{
		++n1;
		++other;
		--n;
	}
	return ((uint8_t)(this->buff[n1]) - (uint8_t)(*other));
}

int32_t	str_ncmp_str(t_str *this, t_str *other, int32_t n)
{
	register int32_t	n1;
	register int32_t	n2;

	if (str_check(this, NULL) || n < 0)
		return (_str_set_error(this, E_PARAM, "ncmp"));
	n1 = this->i;
	n2 = other->i;
	while (n && this->buff[n1] && other->buff[n2] \
		&& this->buff[n1] == other->buff[n2])
	{
		++n1;
		++n2;
		--n;
	}
	return ((uint8_t)(this->buff[n1]) - (uint8_t)(other->buff[n2]));
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Inserisci le 2 stringhe, poi il numero di confronti da fare");
		return (42);
	}
	if (argc == 42)
	{
		printf("Pisa merda");
		return (42);
	}
	int n = argv[3][0] - '0';
	printf("Funzione fake: %d", ft_strncmp(argv[1], argv[2], n));
	return (0);
}*/
