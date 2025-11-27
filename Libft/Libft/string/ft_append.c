/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:47:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 08:59:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_str	*str_app(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_app_str(this, other));
	else
		return (str_app_char(this, other));
}

t_str *str_app_str(t_str *s, const t_str *s2)
{
	int32_t	temp;

	if (!s || s->i == s->npos)
		return (s);
	temp = s->i;
	s->i = 0;
	str_join_str(s, s2, 0);
	if (s->i != s->npos)
		s->i = temp;
	return (s);
}

t_str *str_app_char(t_str *s, const char *s2)
{
	int32_t	temp;

	if (!s || s->i == s->npos)
		return (s);
	temp = s->i;
	s->i = 0;
	str_join_char(s, s2, 0);
	if (s->i != s->npos)
		s->i = temp;
	return (s);
}
