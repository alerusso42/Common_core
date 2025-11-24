/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_diff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:53:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 10:44:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strchr(const char *s, int c);

t_str	*str_rdiff(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_rdiff_str(this, other));
	else
		return (str_rdiff_char(this, other));
}

t_str	*str_rdiff_chr(t_str *this, char other)
{
	int32_t	i;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "rdiff"));
	i = (int32_t)(this->end - this->begin) - 1;
	while (i > this->i && this->buff[i] == other)
		i--;
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}

t_str	*str_rdiff_char(t_str *this, const char *other)
{
	int32_t	i;
	int32_t	j;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "rdiff"));
	i = (int32_t)(this->end - this->begin) - 1;
	j = 0;
	while (i > this->i && this->buff[i] == other[j])
	{
		j = -1;
		while (other[++j])
			if (this->buff[i] != other[j])
				break ;
		i--;
	}
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}

t_str	*str_rdiff_str(t_str *this, t_str *other)
{
	int32_t	i;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "rdiff"));
	i = (int32_t)(this->end - this->begin) - 1;
	while (i > this->i && this->buff[i] == *other->buff)
	{
		other->buff--;
		while (++other->buff)
			if (this->buff[i] != *other->buff)
				break ;
		i--;
	}
	other->buff = (char *)other->begin;
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}
