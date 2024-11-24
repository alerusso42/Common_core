/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:56:46 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/25 17:57:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	checker;
	int	i;

	i = -1;
	checker = 1;
	while (str[++i])
	{
		if (!(str[i] >= 32 && str[i] != 127))
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
	char     *str1 = "";
	char    str2[12] = "KONO DIO DA";
	char    str3[40] = "\n\n";

	//checker = ft_str_is_printable(str1);
	printf("Empty case: %d", ft_str_is_printable(str1));
    //str[15] = "kono dio da";
	//ft_str_is_printable(str2);
	printf("\nRight case: %d", ft_str_is_printable(str2));
    //str[15] = "spazio per eventuali prove del correttore";
	//ft_str_is_printable(str3);
	printf("\nWrong case: %d", ft_str_is_printable(str3));
	return (0);	
}*/
