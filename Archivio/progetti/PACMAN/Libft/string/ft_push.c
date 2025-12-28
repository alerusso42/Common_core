/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:47:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 08:56:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_str	*str_push(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_push_str(this, other));
	else
		return (str_push_char(this, other));
}

t_str *str_push_str(t_str *s, const t_str *s2)
{
	int32_t	temp;

	if (!s || s->i == s->npos)
		return (s);
	temp = s->i;
	s->i = s->len;
	str_join_str(s, s2, 0);
	if (s->i != s->npos)
		s->i = temp;
	return (s);
}

t_str *str_push_char(t_str *s, const char *s2)
{
	int32_t	temp;

	if (!s || s->i == s->npos)
		return (s);
	temp = s->i;
	s->i = s->len;
	str_join_char(s, s2, 0);
	if (s->i != s->npos)
		s->i = temp;
	return (s);
}
