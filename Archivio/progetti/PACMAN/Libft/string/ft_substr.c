/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:13:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:46:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - str_substr
/*
	Extracts a substring from another string object.

	@input:		[t_str *this]----->	pointer to string object
				[const t_str *other]->pointer to another string object
				[int32_t start]--->	start index for substring
				[int32_t end]----->	end index for substring
	@return:	[t_str *]--------->	pointer to this
	@variables:	none
	@usage:	*-------------------------------*	
			|	str_substr(str, other, start, end);|
			|	//OR						|
			|	substr(str, other, start, end);	|
			|	//OR						|
			|	str->m->substr(&str, other, start, end);|
			*-------------------------------*
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	substring_lenght;
	size_t	size;
	char	*substring;

	substring_lenght = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	while ((s[start + substring_lenght]) && (substring_lenght < len))
		++substring_lenght;
	size = substring_lenght;
	substring = (char *)CALLOC(size + 1, 1);
	if (!substring)
		return (NULL);
	index = 0;
	while (index < substring_lenght)
	{
		substring[index] = s[start + index];
		++index;
	}
	substring[index] = '\0';
	return (substring);
}

t_str	*str_substr(t_str *this, const t_str *other, int32_t start, int32_t end)
{
	return (sdup(this, other)->m->cut(this, start, end));
}

/*
int	main(int argc, char *argv[])
{
	char	*sub_string;
	int		start;
	size_t	len;
	
	if (argc < 4)
	{
		printf("1) STRINGA; 2) START 3) LEN");
		return (42);	
	}
	start = atoi(argv[2]);
	len = (int)atoi(argv[3]);
	sub_string = ft_substr(argv[1], start, len);
	printf("\n%s\n", sub_string),
	free(sub_string);
	return (0);
}*/
