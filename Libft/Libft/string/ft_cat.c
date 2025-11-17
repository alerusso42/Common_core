/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:09:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/17 19:25:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

/*REVIEW - cat_string

//Cat a string in another string, starting from start (included).
*/
static void	to_free(char *s1, char *s2, int which);

// usage: new = _cat_string(src, catstr, 4, 2);
//	src = "Hello";	catstr = " World"; start = 5; which_free = 2;
//	new = "Hello World"
//
//	which_free: 0 FREE NOTHING, 1 FREE src, 2 FREE catstr, 3 FREE BOTH	
char	*cat_string(char *src, char *catstr, size_t start, int which_free)
{
	size_t	i;
	char	*new;
	size_t	catstr_len;

	if (!src || !catstr)
		return (to_free(src, catstr, which_free), NULL);
	i = 0;
	while (src[i] && i < start)
		++i;
	if (i > start && !src[i])
		return (to_free(src, catstr, which_free), NULL);
	catstr_len = ft_strlen(catstr);
	new = (char *)ft_calloc(ft_strlen(src) + catstr_len + 2, sizeof(char));
	if (new)
	{
		ft_strlcpy(new, src, start + 2);
		ft_strlcpy(new + start, catstr, catstr_len + 2);
		if (src[i])
			sub_strcpy(new + start + catstr_len, src + start, "", EXCLUDE);
	}
	return (to_free(src, catstr, which_free), new);
}

static void	to_free(char *s1, char *s2, int which)
{
	if (which == 1 || which >= 3)
		FREE(s1);
	if (which == 2 || which >= 3)
		FREE(s2);
}

t_str *str_cat_str(t_str *s, t_str *s2, int32_t n)
{
	int32_t i;
	char   *new_s;

	if (str_check(s, s2))
		return (s);
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

t_str *str_cat_char(t_str *s, char *s2, int32_t n)
{
	int32_t i;
	int32_t len;
	char   *new_s;

	//checks
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
