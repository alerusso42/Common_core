/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_strlowcase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:00:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 13:08:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
	}
	return (str);
}
/*
int	main(void)
{
	char     *str1 = "";
	char    str2[12] = "KONO DIO DA";
	char    str3[40] = "SPAZIO PER EVENTUALI PROVE";

	ft_strlowcase(str1);
	printf("Empty case: %s", str1);
    //str[15] = "kono dio da";
	ft_strlowcase(str2);
	printf("\nRight case: %s", str2);
    //str[15] = "spazio per eventuali prove del correttore";
	ft_strlowcase(str3);
	printf("\nTest: %s", str3);
	return (0);
}*/
