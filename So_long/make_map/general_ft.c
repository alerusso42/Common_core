/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#   #+#            */
/*   Updated: 2025/01/18 10:21:48 by alerusso         ###  ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

void	ft_swap(int *x, int *y);
int		ft_memset(void *str, int size);
int		ft_strncpy(unsigned char *dest, unsigned char *src, unsigned char len);
int		ft_pow(int base, int exponent);
int		ft_strcmp(char *s1, char *s2);

/* 	ft_swap svolge un ruolo fondamentale nel processo di twist dei
	valori di t_random: usando il seed, vengono scambiati gli indici
	degli array in modo pseudocasuale (in modo artigianale).
*/
void	ft_swap(int *x, int *y)
{
	int	temp;

	if ((*x == -1) || (*y == -1))
		return ;
	temp = *x;
	*x = *y;
	*y = temp;
}

int	ft_memset(void *content, int size)
{
	int				index;
	unsigned char	*str;

	index = 0;
	str = (unsigned char *)content;
	while (index < size)
	{
		str[index] = 0;
		++index;
	}
	return (0);
}

int	ft_strncpy(unsigned char *dest, unsigned char *src, unsigned char len)
{
	int	index;

	index = 0;
	while (len-- != 0)
	{
		dest[index] = src[index];
		++index;
	}
	dest[index] = src[index];
	return (0);
}

// Non funziona con esponenti negativi.
int	ft_pow(int base, int exponent)
{
	if (base == 0)
		return (0);
	if (base == 1)
		return (1);
	if (exponent <= 0)
		return (1);
	if (exponent == 1)
		return (base);
	return (base * ft_pow(base, exponent - 1));
}

/*
	This strcmp is NOT case sensitive!
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = -1;
	diff = 0;
	while ((s1[++i] != '\0') && (s2[i] != '\0') && (diff < 3))
	{
		if (((s1[i] >= 97) && (s1[i] <= 122))
			&& ((s2[i] >= 65) && (s2[i] <= 90)))
		{
			if (s1[i] != (s2[i] + 32))
				diff += 1;
		}
		else if (((s1[i] >= 65) && (s1[i] <= 90))
			&& ((s2[i] >= 97) && (s2[i] <= 122)))
		{
			if (s1[i] != (s2[i] - 32))
				diff += 1;
		}
		else if ((s1[i] != s2[i]))
			diff += 1;
	}
	while ((s2[i++] != '\0') && (diff < 3))
		++diff;
	return (diff);
}
