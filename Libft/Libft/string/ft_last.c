/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:44:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 17:33:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_str	*str_last(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_last_str(this, other));
	else
		return (str_last_char(this, other));
}

t_str	*str_last_chr(t_str *this, char other)
{
	int32_t	i;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "last"));
	i = (int32_t)(this->end - this->begin) - 1;
	while (i > this->i && this->buff[i] != other)
		i--;
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}

t_str	*str_last_char(t_str *this, const char *other)
{
	int32_t	i;
	int32_t	j;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "last"));
	i = (int32_t)(this->end - this->begin) - 1;
	j = 0;
	while (i > this->i && this->buff[i] != other[j])
	{
		j = -1;
		while (other[++j])
			if (this->buff[i] == other[j])
				break ;
		i--;
	}
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}

t_str	*str_last_str(t_str *this, const t_str *other)
{
	int32_t	i;
	int32_t	j;
	
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "last"));
	i = (int32_t)(this->end - this->begin) - 1;
	while (i > this->i && this->buff[i] != other->buff[j])
	{
		j = 0;
		while (other->buff[j])
		{
			if (this->buff[i] == other->buff[j])
				break ;
			++j;
		}
		i--;
	}
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}
