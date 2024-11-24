/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:36 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 12:23:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strrchr(const char *s, int c);

char *ft_strrchr(const char *s, int c)
{	
	char	*stock_ptr;

	stock_ptr = NULL;
	while (*s++ != '\0')
	{
		if (*s == c)
			stock_ptr = (char *)s;
	}
	if (c == 0)
		stock_ptr = (char *)s;
	return (stock_ptr);
}

int main()
{
    printf("%s\n", ft_strrchr("mega_rayquaza mega assurdo", 'm'));
    return (0);
}