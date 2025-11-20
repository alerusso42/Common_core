/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/20 11:02:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int main()
{
    printf("%s\n", ft_strnstr("\tNome", "Nome", ft_strlen("Nome")));
    return (0);
}*/

char	*ft_strstr(const char *big, const char *little)
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

/*REVIEW - _ft_strrstr
	Like strrchr, but returns the last occurrence 
	of the string needle in the string haystack.
*/
char	*ft_strrstr(const char *haystack, const char *needle)
{
	int		needle_len;
	char	*last;

	needle_len = ft_strlen(needle);
	last = NULL;
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, needle_len))
			last = (char *)haystack;
		haystack++;
	}
	return (last);
}
