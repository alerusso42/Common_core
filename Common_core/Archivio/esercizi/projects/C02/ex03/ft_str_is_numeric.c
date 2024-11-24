/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:53:23 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/25 17:53:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	checker;
	int	i;

	i = -1;
	checker = 1;
	while (str[++i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
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
	checker = ft_str_is_numeric(str) + '0';
	write(1, "Empty case: ", 12);
	write(1, &checker, 1);
	str = "4321122243211222";
	checker = ft_str_is_numeric(str) + '0';
	write(1, "\nRight case: ", 13);
	write(1, &checker, 1);
	str = "KONODIODA";
	checker = ft_str_is_numeric(str) + '0';
	write(1, "\nWrong case: ", 13);
	write(1, &checker, 1);
	return (0);
}*/
