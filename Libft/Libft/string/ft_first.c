/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:44:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 10:44:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_str	*str_first(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_first_str(this, other));
	else
		return (str_first_char(this, other));
}

t_str	*str_first_chr(t_str *this, char other)
{
	char	chr[2];

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	*chr = other;
	this->i = sub_strlen(this->buff + this->i, chr, EXCLUDE);
	return (this);
}

t_str	*str_first_char(t_str *this, const char *other)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = sub_strlen(this->buff + this->i, other, EXCLUDE);
	return (this);
}

t_str	*str_first_str(t_str *this, t_str *other)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = sub_strlen(this->buff + this->i, other->buff, EXCLUDE);
	return (this);
}
