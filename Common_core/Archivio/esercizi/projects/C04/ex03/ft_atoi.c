/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/13 10:09:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str);
int	ft_isspace(char str);
int	ft_size(char *str, int *i);
int	ft_issign(char *str, int *i);
int	ft_isdigit(char str);
/*
int main()
{
    char    str[30] = "  \f\n\r \t \v ++-2147483646";
    int     ezio_greggio;

    ezio_greggio = atoi(str);
    printf("originale: %d\n", ezio_greggio);
    ezio_greggio = ft_atoi(str);
    printf("replica: %d\n", ezio_greggio);
    return (0);
}
*/

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	ezio_greggio;
	int	size_numb;

	i = 0;
	sign = 1;
	ezio_greggio = 0;
	while (ft_isspace(str[i]) == 1)
		++i;
	sign = ft_issign(str, &i);
	size_numb = ft_size(str, &i);
	while (ft_isdigit(str[i]) == 1)
	{
		ezio_greggio += (1 * size_numb) * (str[i] - '0');
		size_numb = size_numb / 10;
		++i;
	}
	ezio_greggio = ezio_greggio * sign;
	return (ezio_greggio);
}
// ft_atoi gestisce da sola tutti i casi limite!

int	ft_isspace(char str)
{
	if (str == ' ' || str == '\f' || str == '\n')
		return (1);
	if (str == '\r' || str == '\t' || str == '\v')
		return (1);
	return (0);
}

int	ft_issign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = sign * -1;
		++(*i);
	}
	return (sign);
}
// ft_size restituisce un multiplo di 10.

int	ft_size(char *str, int *i)
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

int	ft_isdigit(char str)
{
	if ((str >= '0') & (str <= '9'))
		return (1);
	return (0);
}
