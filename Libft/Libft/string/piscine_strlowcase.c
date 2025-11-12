/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_strlowcase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:00:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/12 20:20:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_tolower(char *str)
{
	while (str && *str)
	{
		*str += ((*str >= 'A' && *str <= 'Z') * 32);
		str++;
	}
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
