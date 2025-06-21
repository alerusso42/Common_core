/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_capitalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:01:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 14:30:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "piscine.h"

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	checker;
	int	first_character_switch;

	checker = 0;
	i = -1;
	first_character_switch = 1;
	while (str[++i])
	{
		if ((checker == 0) && (str[i] >= 65 && str[i] <= 90))
			str[i] = str[i] + 32;
		if (checker == 1)
			if (--checker == 0 && (str[i] >= 97 && str[i] <= 122))
				str[i] = str[i] - 32;
		if (!(str[i] >= 97 && str[i] <= 122))
			if (!(str[i] >= 65 && str[i] <= 90))
				if (!(str[i] >= 48 && str[i] <= 57))
					checker = 1;
		if (first_character_switch-- == 1)
			if (str[i] >= 97 && str[i] <= 122)
				str[i] = str[i] - 32;
	}
	return (str);
}
/*
int	main(void)
{
	char     *str1 = "";
	char    str2[20] = "kONO dIO  42 dA";
	char    str3[40] = "SPAZIO PER EVENTUALI PROVE";
	
	printf("Test1: %s", str1);
	ft_strcapitalize(str1);
	printf("\nTest1: %s", str1);
    //str[15] = "kono dio da";
    printf("\nTest2: %s", str2);
	ft_strcapitalize(str2);
	printf("\nTest2: %s", str2);
    //str[15] = "spazio per eventuali prove del correttore";
    printf("\nTest3: %s", str3);
	ft_strcapitalize(str3);
	printf("\nTest3: %s", str3);
	return (0);
}*/
