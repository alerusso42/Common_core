/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:05:32 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/29 10:38:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define TRUE 1
#define FALSE 0

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (TRUE);
	else
		return (FALSE);
}

/*
int	main()
{
	char	c;

	c = '^';
	if (ft_isascii((int)c) == TRUE)
		printf("\nTRUE\n");
	else
		printf("\nFALSE\n");
	return (0);
}*/
