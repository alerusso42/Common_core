/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_add_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:05:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 23:00:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_str	*str_addr(t_str *this, char c)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "add_right"));
	if (this->capacity <= this->len)
		if (str_srealloc(this, 0)->err != 0)
			return (this);
	this->buff[this->len++] = c;
	this->buff[this->len] = '\0';
	return (0);
}

t_str	*str_addl(t_str *this, char c)
{
	int32_t	i;

	if (str_check(this, NULL) || c == '\0')
		return (_str_set_error(this, E_PARAM, "add_left"));
	if (this->capacity <= this->len)
		if (str_srealloc(this, 0)->err != 0)
			return (this);
	this->buff[this->len + 1] = '\0';
	i = this->len++;
	while (i)
	{
		this->buff[i] = this->buff[i - 1];
		i--;
	}
	this->buff[0] = c;
	return (0);
}
