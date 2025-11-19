/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:53:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 16:17:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	sub_strlen(char *s, char *charset, int mode);

t_str	*str_diff_chr(t_str *this, char other, int32_t n)
{
	char	chr[2];

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	*chr = other;
	this->i = sub_strlen(this->buff + this->i, chr, INCLUDE);
	return (this);
}

t_str	*str_diff_char(t_str *this, const char *other, int32_t n)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = sub_strlen(this->buff + this->i, other, INCLUDE);
	return (this);
}

t_str	*str_diff_str(t_str *this, t_str *other, int32_t n)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = sub_strlen(this->buff + this->i, other->buff, INCLUDE);
	return (this);
}
