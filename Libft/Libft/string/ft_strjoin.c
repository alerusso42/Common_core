/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:36:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 17:59:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*stringona;
	int		index;
	int		size;

	if ((!s1) || (!s2))
		return (NULL);
	index = 0;
	while (s1[index])
		++index;
	size = index;
	index = 0;
	while (s2[index])
		++index;
	size += index;
	stringona = NULL;
	stringona = (char *)ft_calloc(size + 1, 1);
	if (!stringona)
		return (NULL);
	index = 0;
	stringona[0] = 0;
	while (*s1)
		stringona[index++] = *s1++;
	while (*s2)
		stringona[index++] = *s2++;
	return (stringona);
}

t_str *str_join_str(t_str *s, t_str *s2, int32_t n)
{
	int32_t i;
	char   *new_s;

	if (str_check(s, s2) || n < 0)
		return (_str_set_error(s, E_PARAM, "cat"));
	i = s->len + s2->len - n;
	new_s = ft_calloc(i + 1, sizeof(char));
	if (!new_s)
		return (_str_set_error(s, E_ALLOC, NULL));
	ft_strlcpy(new_s, s->buff, s->i + 1);
	ft_strlcpy(new_s + s->i, s2, INT_MAX);
	if (s->buff[s->i])
		ft_strlcpy(new_s + s->i + s2->len, s->buff + s->i, INT_MAX);
	FREE(s->buff);
	s->buff = new_s;
	return (s);
}

t_str *str_join_char(t_str *s, char *s2, int32_t n)
{
	int32_t i;
	int32_t len;
	char   *new_s;

	if (str_check(s, s2) || n < 0)
		return (_str_set_error(s, E_PARAM, "cat"));
	len = ft_strlen(s2);
	i = s->len + len - n;
	new_s = ft_calloc(i + 1, sizeof(char));
	if (!new_s)
		return (str_set_error(E_ALLOC));
	ft_strlcpy(new_s, s->buff, s->i + 1);
	ft_strlcpy(new_s + s->i, s2, INT_MAX);
	if (s->buff[s->i])
		ft_strlcpy(new_s + s->i + len, s->buff + s->i, INT_MAX);
	FREE(s->buff);
	s->buff = new_s;
	return (s);
}

/*
int	main(int argc, char *argv[])
{
	char	*s1;
	char	*s2;
	char	*stringona;

	if (argc < 3)
	{
		printf("s1 = argv[1]; s2 = argv[2]");
		return (42);
	}
	s1= argv[1];
	s2 = argv[2];
	stringona = ft_strjoin(s1, s2);
	printf("\n STRINGHE\ns1: %s;\ns2: %s\n", s1, s2);
	printf("\n STRINGONA:%s\n", stringona);
	return (0);
}
*/
