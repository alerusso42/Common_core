/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:31:27 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:24:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "libft.h"

char		**ft_split(char const *str, char *c);
static int	ft_alloc(char ***strings, char *str, char *charset, int str_num);
static void	how_many_strings(char *str, char *charset, int *str_num, int *i);
static int	is_charset(char cmp, char *charset);
static void	ft_copy(char **strings, char *str, char *charset, int str_num);

/*
int main(int argc, char *argv[])
{
    char    **strings;
	int		i;

	if (argc != 3)
	{
		printf("argv[1] = string, argv[2] = charset\n");
		return (42);
	}
	printf("Str: %s\n", argv[1]);
    printf("Charset: \"%s\"\n", argv[2]);
    strings = ft_split((char const *)argv[1], argv[2]);
	i = 0;
	do
    	printf("Stringa %d: %s\n", i + 1, strings[i]);
	while (strings[i++] != NULL);
	return (0);
}*/

char	**ft_split(char const *str, char *c)
{
	char	**strings;
	int		i;
	int		str_num;

	how_many_strings((char *)str, c, &str_num, &i);
	if (ft_alloc(&strings, (char *)str, c, str_num) == 42)
		return (NULL);
	ft_copy(strings, (char *)str, c, str_num);
	return (strings);
}

static void	how_many_strings(char *str, char *charset, int *str_num, int *i)
{
	*i = 0;
	*str_num = 0;
	while (str[*i] != '\0')
	{
		while ((is_charset(str[*i], charset) == 1) && (str[*i] != '\0'))
			++(*i);
		if (is_charset(str[*i], charset) == 0)
			++(*str_num);
		while ((is_charset(str[*i], charset) == 0) && (str[*i] != '\0'))
			++(*i);
	}
}

static int	is_charset(char cmp, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (cmp == charset[i])
			return (1);
		++i;
	}
	return (0);
}

static int	ft_alloc(char ***strings, char *str, char *charset, int str_num)
{
	int	str_len;
	int	i;

	*strings = (char **)malloc((str_num + 1) * sizeof(char *));
	if (*strings == NULL)
		return (42);
	str_num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while ((is_charset(str[i], charset) == 1) && (str[i] != '\0'))
			++i;
		--i;
		str_len = 0;
		while ((is_charset(str[++i], charset) == 0) && (str[i] != '\0'))
			++str_len;
		if (str_len != 0)
			(*strings)[str_num] = (char *)malloc((str_len + 1) * sizeof(char));
		if (((*strings)[str_num] == NULL) && (str_len != 0))
			return (42);
		if (str_len != 0)
			++str_num;
	}
	(*strings)[str_num] = (char *)malloc(sizeof(NULL));
	return (0);
}

static void	ft_copy(char **strings, char *str, char *charset, int str_num)
{
	int	i_str;
	int	i_matrix;

	i_str = 0;
	str_num = 0;
	while (str[i_str] != '\0')
	{
		i_matrix = 0;
		while ((is_charset(str[i_str], charset) == 1) && (str[i_str] != '\0'))
			++i_str;
		while ((is_charset(str[i_str], charset) == 0) && (str[i_str] != '\0'))
		{
			strings[str_num][i_matrix] = str[i_str];
			++i_matrix;
			++i_str;
		}
		strings[str_num][i_matrix] = '\0';
		if (i_matrix != 0)
			++str_num;
	}
	strings[str_num] = NULL;
}