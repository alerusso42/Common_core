/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:34 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/29 10:46:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) == TRUE) || (ft_isdigit(c) == TRUE))
		return (TRUE);
	else
		return (FALSE);
}

/*
int	main()
{
	char	c;

	c = '^';
	if (ft_isalnum((int)c) == TRUE)
		printf("\nTRUE\n");
	else
		printf("\nFALSE\n");
	return (0);
}*/
