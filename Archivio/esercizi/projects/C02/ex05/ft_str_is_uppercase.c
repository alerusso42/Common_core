/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:55:23 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/25 17:55:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	checker;
	int	i;

	i = -1;
	checker = 1;
	while (str[++i])
	{
		if (!(str[i] >= 65 && str[i] <= 90))
		{
			--checker;
			break ;
		}
	}
	return (checker);
}
/*
int	main(void)
{
	int		checker;
	char	*str;

	str = "";
	checker = ft_str_is_uppercase(str) + '0';
	write(1, "Empty case: ", 12);
	write(1, &checker, 1);
	str = "KONODIODA";
	checker = ft_str_is_uppercase(str) + '0';
	write(1, "\nRight case: ", 13);
	write(1, &checker, 1);
	str = "konodioda";
	checker = ft_str_is_uppercase(str) + '0';
	write(1, "\nWrong case: ", 13);
	write(1, &checker, 1);
	return (0);
}*/
