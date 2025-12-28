/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:36:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 17:00:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - str_join
/*
	Appends the content of another string object or a char pointer
	to the current string object.

	@INDEX:		SET INDEX TO END OF JOINED CONTENT!
	@input:		[t_str *this]----->	pointer to string object
				[const void *other]->pointer to another string object
									or a char pointer
				[int32_t n]------->	number of characters to skip from other
	@return:	[t_str *]--------->	pointer to this
	@variables:	none
	@usage:	*-------------------------------*	
			|	str_join(str, other, n);	|
			|	//OR						|
			|	join(str, other, n);		|
			|	//OR						|
			|	str->m->join(&str, other, n);|
			*-------------------------------*
*/
t_str	*str_join(t_str *this, const void *other, int32_t n)
{
	if (_str_identifier(other) == true)
		return (str_join_str(this, other, n));
	else
		return (str_join_char(this, other, n));
}

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
	stringona = (char *)CALLOC(size + 1, 1);
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

char	*ft_strjoin_free(char *s1, char *s2, int mode)
{
	char	*join;

	if (s1 && !s2)
		join = ft_strdup(s1);
	else if (!s1 && s2)
		join = ft_strdup(s2);
	else
		join = ft_strjoin(s1, s2);
	if (mode == 1)
		FREE(s1);
	else if (mode == 2)
		FREE(s2);
	else if (mode > 2)
		FREE(s1), FREE(s2);
	return (join);
}

t_str *str_join_str(t_str *s, const t_str *s2, int32_t n)
{
	int32_t i;
	char   *new_s;

	if (str_check(s, s2) || n < 0 || n > s2->len)
		return (_str_set_error(s, E_PARAM, "join"));
	i = s->len + s2->len - n;
	new_s = CALLOC(i + 1, sizeof(char));
	if (!new_s)
		return (_str_set_error(s, E_ALLOC, NULL));
	ft_strlcpy(new_s, s->buff, s->i + 1);
	ft_strlcpy(new_s + s->i, s2->buff + n, INT_MAX);
	if (s->buff[s->i])
		ft_strlcpy(new_s + s->i + s2->len - n, s->buff + s->i, INT_MAX);
	FREE(s->buff);
	s->buff = new_s;
	s->len = i;
	s->i += s2->len - n;
	return (s);
}

t_str *str_join_char(t_str *s, const char *s2, int32_t n)
{
	int32_t i;
	int32_t len;
	char   *new_s;

	if (str_check(s, s2) || n < 0)
		return (_str_set_error(s, E_PARAM, "join"));
	len = ft_strlen(s2);
	if (len < n)
		return (_str_set_error(s, E_PARAM, "join"));
	i = s->len + len - n;
	new_s = CALLOC(i + 1, sizeof(char));
	if (!new_s)
		return (_str_set_error(s, E_ALLOC, "join"));
	ft_strlcpy(new_s, s->buff, s->i + 1);
	ft_strlcpy(new_s + s->i, s2 + n, INT_MAX);
	if (s->buff[s->i])
		ft_strlcpy(new_s + s->i + len - n, s->buff + s->i, INT_MAX);
	FREE(s->buff);
	s->buff = new_s;
	s->len = i;
	s->i += len - n;
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
