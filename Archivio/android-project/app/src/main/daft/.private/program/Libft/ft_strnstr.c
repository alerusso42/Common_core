/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/17 21:26:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int main()
{
    printf("%s\n", ft_strnstr("\tNome", "Nome", ft_strlen("Nome")));
    return (0);
}*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_index;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	big_index = 0;
	while (big[big_index] && big_index <= len)
	{
		if (ft_memcmp(big + big_index, little, little_len) == 0)
			return ((char *)big + big_index);
		big_index++;
	}
	return (NULL);
}
