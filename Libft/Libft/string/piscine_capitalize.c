/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_capitalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:01:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/12 20:20:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "piscine.h"

void	ft_toupper(char *str)
{
	while (str && *str)
	{
		*str -= ((*str >= 'a' && *str <= 'z') * 32);
		str++;
	}
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
