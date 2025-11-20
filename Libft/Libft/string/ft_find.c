/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:44:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/20 21:42:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int32_t	ft_strstr_int(const char *, const char *);

t_str	*str_find_chr(t_str *this, char other)
{
	char	chr[2];

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	*chr = other;
	chr[1] = 0;
	this->i = ft_strstr_int(this->buff, chr);
	return (this);
}

t_str	*str_find_char(t_str *this, const char *other)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = ft_strstr_int(this->buff, other);
	return (this);
}

t_str	*str_find_str(t_str *this, t_str *other)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = ft_strstr_int(this->buff, other->buff);
	return (this);
}
