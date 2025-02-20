/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sub_string_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:24:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 12:32:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

/*
    RULES:

    1)  MAKE SURE YOUR DEST STRING IS BIG ENOUGH!
	2)	YOU MUST SET DEST TO ZERO;
	3)	IF YOU WANT OTHER ASCII TYPE, YOU CAN:
		THIS FUNCTION GOES ON UNTIL IT FINDS A '\0'.
    4)  GIVE ONE OF THE FOLLOWING VALUES:

    -  	 ALPHA,	(53 bytes needed)
	-    UPPER_ALPHA,
	-    LOWER_ALPHA,
	-    DIGIT,
	-    ALPHANUM
*/
void    copy_stringset(char *dest, int charset_type)
{
	if (!dest)
		return ;
	while (*dest != 0)
		++dest;
	if (charset_type == ALPHA)
   		ft_strlcpy(dest, "abcdefghijklmnopqrstuvwxyz\
        ABCDEFGHIJKLMNOPQRSTUVWXYZ", 52);
	else if (charset_type == LOWER_ALPHA)
		ft_strlcpy(dest, "abcdefghijklmnopqrstuvwxyz", 26);
	else if (charset_type == UPPER_ALPHA)
		ft_strlcpy(dest, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
	else if (charset_type == DIGIT)
		ft_strlcpy(dest, "0123456789", 10);
	else if (charset_type == ALPHANUM)
		ft_strlcpy(dest, "abcdefghijklmnopqrstuvwxyz\
        ABCDEFGHIJKLMNOPQRSTUVWXYZ\
		0123456789", 62);
}

void    copy_customset(char *dest, char *charset)
{
	if ((!dest) || (!charset))
		return ;
	while (*dest != 0)
		++dest;
	ft_strlcpy(dest, charset, ft_strlen(charset));
}

/*
	Count until the char is in the charset.
*/
int	sub_strlen(char *s, char *charset)
{
	int	i;

	i = 0;
	while (((s[i] != '\0')) && \
    (ft_strchr(charset, s[i])))
	{
		++i;
	}
	return (i);
}

/*
	Copy until the char is in the charset.
*/
int	sub_strcpy(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (((src[i] != '\0')) && \
    (ft_strchr(charset, src[i])))
	{
		dest[i] = src[i];
		++i;
	}
	return (i);
}
