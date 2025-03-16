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

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

void	ft_swap(int *x, int *y);
int		ft_pow(int base, int exponent);
int		ft_strcmp(char *s1, char *s2);

/*
	Return the absolute value of a number.
*/
int	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	if (num == INT_MIN)
		return (INT_MAX);
	return (num * -1);
}

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

// Doesn't work with negative numbers.
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
