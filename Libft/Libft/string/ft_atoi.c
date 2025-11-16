/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/16 07:04:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static long long int	atoi_parse_result(long long int res, char sign);

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

/*
	Atoi modified: 	if there are too much signs, returns LLONG_MAX;
					if there are non digit characters, returns LLONG_MIN.
*/

# include <string.h>
long long int	ft_atoi(const char *nptr)
{
	long long int	pow;
	long long int	res;
	int				start;
	int				i;

	res = 0;
	pow = 1;
	i = 0;
	while (strchr(" \n\t\f\t\v\r", nptr[i]))
		i++;
	start = i;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		return (LLONG_MAX);
	while (strchr("0123456789", nptr[i]))
		i++;
	if (start == i)
		return (E_ATOI_FAIL);
	while (i != start)
	{
		res += (nptr[i--] - '0') * pow;
		pow *= 10;
	}
	return (atoi_parse_result(res, nptr[start]));
}


err		str_atoi(t_str *str, int *n)
{
	int				start;
	long long int	res;

	*n = 0;
	start = str->i;
	while (strchr(" \n\t\f\t\v\r", str->buff[start]))
		start++;
	res = ft_atoi(str->buff + start);
	if (res == LLONG_MAX)
		return (E_ATOI_FAIL);
	*n = (int)res;
	return (E_EXIT_SUCCESS);
}

static long long int	atoi_parse_result(long long int res, char sign)
{
	if (res == 2147483648 && sign == '-')
		res = INT_MIN;
	else if (res > 2147483647)
		return (LLONG_MAX);
	else if (sign == '-')
		res = res * -1;
	return (res);
}
