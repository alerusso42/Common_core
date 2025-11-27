/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:03:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 08:36:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_str	*str_cpy(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_cpy_str(this, other));
	else
		return (str_cpy_char(this, other));
}

t_str	*str_cpy_char(t_str *this, const char *other)
{
	int32_t	i;
	int32_t	j;

	if (str_check(this, other))
		return (_str_set_error(this, E_PARAM, "cpy"));
	i = this->i;
	j = 0;
	while (other[j] && i < this->capacity)
	{
		this->buff[i++] = other[j++];
	}
	this->i = i;
	return (this);
}

t_str	*str_cpy_str(t_str *this, const t_str *other)
{
	int32_t	i;
	int32_t	j;

	if (str_check(this, other))
		return (_str_set_error(this, E_PARAM, "cpy"));
	i = this->i;
	j = 0;
	while (other->buff[j] && i < this->capacity)
	{
		this->buff[i++] = other->buff[j++];
	}
	this->i = i;
	return (this);
}
