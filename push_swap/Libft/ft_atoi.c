/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/27 14:44:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#define TOO_MUCH_SIGNS 0
#define TRUE 1

static long long int	ft_isspace(const char str);
static long long int	ft_size(const char *str, int *i);
static long long int	ft_issign(const char *str, int *i);
/*
int main()
{
    char    str[30] = "  \f\n\r \t \v ++-2147483646";
    int     number;

    number = atoi(str);
    printf("originale: %d\n", number);
    number = ft_atoi(str);
    printf("replica: %d\n", number);
    return (0);
}
*/

static long long int	ft_atoi(const char *nptr)
{
	static long long int	i;
	int	sign;
	static long long int	number;
	int	size_numb;

	i = 0;
	sign = 1;
	number = 0;
	while (ft_isspace(nptr[i]) == TRUE)
		++i;
	sign = ft_issign(nptr, &i);
	if (sign == TOO_MUCH_SIGNS)
		return (0);
	size_numb = ft_size(nptr, &i);
	while (ft_isdigit(nptr[i]) == TRUE)
	{
		number += (1 * size_numb) * (nptr[i] - '0');
		size_numb = size_numb / 10;
		++i;
	}
	number = number * sign;
	return (number);
}

static long long int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\f' || str == '\n')
		return (1);
	if (str == '\r' || str == '\t' || str == '\v')
		return (1);
	return (0);
}

static long long int	ft_issign(const char *str, int *i)
{
	int	sign;
	int	too_much_signs;

	sign = 1;
	too_much_signs = 2;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = sign * -1;
		++(*i);
		--too_much_signs;
		if (too_much_signs <= 0)
		{
			return (TOO_MUCH_SIGNS);
		}
	}
	return (sign);
}
// ft_size gives a multiple of 10.

static long long int	ft_size(const char *str, int *i)
{
	int	size_numb;
	int	make_power;
	int	local_i;

	make_power = 0;
	while (str[*i] == '0')
		++(*i);
	local_i = *i;
	while (ft_isdigit(str[local_i]) == 1)
	{
		++make_power;
		++local_i;
	}
	size_numb = 1;
	while ((make_power != 0) & (make_power != 1))
	{
		size_numb = size_numb * 10;
		--make_power;
	}
	if (make_power == 0)
		size_numb = 0;
	return (size_numb);
}
