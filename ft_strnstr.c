/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:33 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:25:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len);
static size_t 	string_len(const char *s);

/*
int main()
{
    printf("%s\n", ft_strnstr("mega_rayquaza mega assurdo", "ass", 30));
    return (0);
}*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*truncated_bigstring_pointer;
	char	*temp_ptr;
	int		little_index;
	int		stop_process;
	
	if (!(little))
		return ((char *)big);
	truncated_bigstring_pointer = NULL;
	temp_ptr = (char *)big;
	little_index = 0;
	stop_process = (int)string_len(little);
	while ((len--) && (big) && (little_index != stop_process)
		&& (*big != '\0'))
	{
		if (*big == little[little_index])
			++little_index;
		else
			little_index = 0;
		if (little_index == 1)
			temp_ptr = (char *)big;
		if (little_index == stop_process)
			truncated_bigstring_pointer = temp_ptr;
		++big;
	}
	return (truncated_bigstring_pointer);
}

static size_t string_len(const char *s)
{
    size_t  len;

    len = 0;
    while (s[len] != '\0')
        ++len;
    return (len);
}
