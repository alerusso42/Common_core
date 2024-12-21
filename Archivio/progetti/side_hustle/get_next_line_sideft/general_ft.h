/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/20 17:40:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_FT_H
# define GENERAL_FT_H
# include <unistd.h>

int		ft_memset(char *str, int size);
int		ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

int	ft_memset(char *str, int size)
{
	int	index;

	index = 0;
	while (index < size - 1)
	{
		str[index] = 'A';
		++index;
	}
	str[index] = '\0';
	return (0);
}

int	ft_strcpy(char *dest, char *src)
{
	int	index;

	if ((ft_strlen(dest) < ft_strlen(src)))
	{
		return (1);
	}
	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		++index;
	}
	dest[index] = src[index];
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

// Non è case sensitive.
int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = -1;
	diff = 0;
	while ((s1[++i] != '\0') && (s2[i] != '\0') && (diff < 3))
	{
		if (((s1[i] >= 97) && (s1[i] <= 122))
			&& ((s2[i] >= 65) && (s2[i] <= 90)))
		{
			if (s1[i] != (s2[i] + 32))
				diff += 1;
		}
		else if (((s1[i] >= 65) && (s1[i] <= 90))
			&& ((s2[i] >= 97) && (s2[i] <= 122)))
		{
			if (s1[i] != (s2[i] - 32))
				diff += 1;
		}
		else if ((s1[i] != s2[i]))
			diff += 1;
	}
	while ((s2[i++] != '\0') && (diff < 3))
		++diff;
	return (diff);
}

#endif