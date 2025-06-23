/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:15:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 04:46:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool	unsensitive_check(char c1, char c2);

int	sub_strcmp(const char *s1, const char *s2, char *charset)
{
	if (!s1 || !s2)
		return (0);
	while (!ft_strchr(charset, *s1) && !ft_strchr(charset, *s2) && \
	 unsensitive_check(*s1, *s2) == true)
	{
		++s1;
		++s2;
	}
	if (*s1 && ft_strchr(charset, *s1))
		return (0 - *s2);
	else if (*s2 && ft_strchr(charset, *s2))
		return (*s1 - 0);
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int	unsensitive_strncmp(const char *s1, const char *s2, int n)
{
	if (n == 0)
		return (0);
	while ((--n) && (*s1 != '\0') && (*s2 != '\0') && \
	 unsensitive_check(*s1, *s2) == true)
	{
		++s1;
		++s2;
	}
	if (unsensitive_check(*s1, *s2) == true)
		return (0);
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

bool	unsensitive_check(char c1, char c2)
{
	if (c1 == c2)
		return (true);
	else if (c1 >= 'A' && c1 <= 'Z')
		c1 += 32;
	else if (c1 >= 'a' && c1 <= 'z')
		c1 -= 32;
	if (c1 == c2)
		return (true);
	return (false);
}

int	move_str(char *s, char c, int moves)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] && count != moves)
	{
		if (s[i] == c)
			++count;
		++i;
	}
	return (i);
}
