/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:34 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 12:18:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define TRUE 1
#define FALSE 0

int ft_isdigit(int c);

int ft_isdigit(int c)
{
    if ((c >= '0') && (c <= '9'))
        return (TRUE);
    else
        return (FALSE);
}

int	main()
{
	char	c;

	c = '^';
	if (ft_isdigit((int)c) == TRUE)
		printf("\nTRUE\n");
	else
		printf("\nFALSE\n");
	return (0);
}
