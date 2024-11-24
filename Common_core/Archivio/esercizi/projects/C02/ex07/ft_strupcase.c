/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:57:29 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/25 17:57:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
	}
	return (str);
}
/*
int    main(void)
{
    char    str2[15] = "kono dio da";
    char    str3[40] = "spazio per prove del correttore";
    
	printf("Before: %s", str2);
	printf("\nAfter: %s", ft_strupcase(str2));
	printf("\nTest: %s", ft_strupcase(str3));
	return (0);	
}*/
