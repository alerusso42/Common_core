/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/20 21:42:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_strcmp(const char *s1, const char *s2);

/*
int main()
{
    printf("%s\n", ft_strnstr("\tNome", "Nome", ft_strlen("Nome")));
    return (0);
}*/

char	*ft_strstr(const char *big, const char *little)
{
	size_t	big_index;

	if (*little == '\0')
		return ((char *)big);
	big_index = 0;
	while (big[big_index])
	{
		if (ft_strcmp(big + big_index, little) == 0)
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
	char	*last;

	last = NULL;
	while (*haystack)
	{
		if (!ft_strcmp(haystack, needle))
			last = (char *)haystack;
		haystack++;
	}
	return (last);
}

int32_t	ft_strstr_int(const char *big, const char *little)
{
	size_t	big_index;

	if (*little == '\0')
		return (0);
	big_index = 0;
	while (big[big_index])
	{
		if (ft_strcmp(big + big_index, little) == 0)
			return (big_index);
		big_index++;
	}
	return (INT32_MAX);
}

/*REVIEW - _ft_strrstr
	Like strrchr, but returns the last occurrence 
	of the string needle in the string haystack.
*/
int32_t	ft_strrstr_int(const char *haystack, const char *needle)
{
	int32_t	last;
	int32_t	i;

	if (!needle || !haystack)
		return (0);
	last = INT_MAX;
	i = 0;
	while (haystack[i])
	{
		if (!ft_strcmp(haystack, needle))
			last = i;
		i++;
	}
	return (last);
}
