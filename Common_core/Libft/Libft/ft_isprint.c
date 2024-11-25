/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:08:36 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:22:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define TRUE 1
#define FALSE 0

int ft_isprint(int c);

int ft_isprint(int c)
{
    if (((c >= 0) && (c <= 31)) || (c == 127))
        return (FALSE);
    else
        return (TRUE);
}

/*
int	main()
{
	char	c;

	c = '^';
	if (ft_isprint((int)c) == TRUE)
		printf("\nTRUE\n");
	else
		printf("\nFALSE\n");
	return (0);
}*/
