/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:03:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 20:24:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_str	*str_ncpy(t_str *this, const void *other, int32_t start, int32_t n)
{
	if (_str_identifier(other) == true)
		return (str_ncpy_str(this, other, start, n));
	else
		return (str_ncpy_char(this, other, start, n));
}

t_str	*str_ncpy_char(t_str *this, const char *other, int32_t strt, int32_t n)
{
	int32_t	i;
	int32_t	j;

	if (str_check(this, other) || (int32_t)ft_strlen(other) < strt || strt < 0)
		return (_str_set_error(this, E_PARAM, "find"));
	i = this->i;
	j = strt;
	while (n-- && other[j] && i < this->capacity)
	{
		this->buff[i++] = other[j++];
	}
	return (this);
}

t_str	*str_ncpy_str(t_str *this, const t_str *other, int32_t strt, int32_t n)
{
	int32_t	i;
	int32_t	j;

	if (str_check(this, other) || other->len < strt || strt < 0)
		return (_str_set_error(this, E_PARAM, "find"));
	i = this->i;
	j = strt;
	while (n-- && other->buff[j] && i < this->capacity)
	{
		this->buff[i++] = other->buff[j++];
	}
	return (this);
}
