/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:08:36 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/21 12:18:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main()
{
	char	c;

	c = '^';
	if (ft_isprint((int)c) == TRUE)
		printf("\nTRUE\n");
	else
		printf("\nFALSE\n");
	return (0);
}
