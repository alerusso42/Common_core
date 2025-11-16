/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:39:37 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/16 07:08:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

/*REVIEW - _sub_strlen
	Count until the char is in the charset.
	TWO MODES:

	INCL: Count until the char is INCLUDED in the charset.
	EXCL: Count until the char is NOT INCLUDED in the charset.
*/
int	_sub_strlen(char *s, char *charset, int mode)
{
	int	i;

	i = 0;
	if (mode == INCL)
	{
		while (((s[i] != '\0')) && \
		(ft_strchr(charset, s[i])))
		{
			++i;
		}
	}
	else if (mode == EXCL)
	{
		while (((s[i] != '\0')) && \
		!(ft_strchr(charset, s[i])))
		{
			++i;
		}
	}
	return (i);
}

/*REVIEW - _sub_strcpy
	Copy until the char is in the charset.
	TWO MODES:

	INCL: Copy until the char is in the charset.
	EXCL: Copy until the char is NOT in the charset.
*/
int	_sub_strcpy(char *dest, char *src, char *charset, int mode)
{
	int	i;

	i = 0;
	if (mode == INCL)
	{
		while (((src[i] != '\0')) && \
		(ft_strchr(charset, src[i])))
		{
			dest[i] = src[i];
			++i;
		}
	}
	else if (mode == EXCL)
	{
		while (((src[i] != '\0')) && \
		!(ft_strchr(charset, src[i])))
		{
			dest[i] = src[i];
			++i;
		}
	}
	dest[i] = 0;
	return (i);
}

/*REVIEW - cut_string

//Cut a string from start to end (included).
	
Example:

string = "Hello world!"
start = 5
end = 5

string becomes: "Helloworld!\0"
*/
char	*_cut_string(char *string, size_t start, size_t end)
{
	unsigned int	temp;
	unsigned int	temp1;
	unsigned int	string_len;

	end++;
	if (!(string) || !(*string) || (start > end))
		return (NULL);
	string_len = 0;
	while (string[string_len])
		++string_len;
	temp = start;
	while ((start != end) && (string[start] != 0))
		string[start++] = 0;
	end = start;
	start = temp;
	temp = 0;
	temp1 = string_len;
	while (end != string_len--)
	{
		string[start + temp] = string[end + temp];
		++temp;
	}
	string[temp1 - (end - start)] = 0;
	return (string);
}
