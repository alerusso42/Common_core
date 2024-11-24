/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:15:56 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 13:18:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

int ft_isalpha(int c);

int ft_isalpha(int c)
{
    if ((c >= 'a') && (c <= 'z'))
        return (TRUE);
    if ((c >= 'A') && (c <= 'Z'))
        return (TRUE);
	else
    	return (FALSE);
}

/*
int	main()
{
	char	c;

	c = '^';
	if (ft_isalpha((int)c) == TRUE)
		printf("\nTRUE\n");
	else
		printf("\nFALSE\n");
	return (0);
}*/
