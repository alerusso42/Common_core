/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:44:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 16:16:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	sub_strlen(char *s, char *charset, int mode);

t_str	*str_find_chr(t_str *this, char other)
{
	char	chr[2];

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	*chr = other;
	this->i = sub_strlen(this->buff + this->i, chr, EXCLUDE);
	return (this);
}

t_str	*str_find_char(t_str *this, const char *other)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = sub_strlen(this->buff + this->i, other, EXCLUDE);
	return (this);
}

t_str	*str_find_str(t_str *this, t_str *other)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = sub_strlen(this->buff + this->i, other->buff, EXCLUDE);
	return (this);
}
