/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:44:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 19:27:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strchr(const char *s, int c);

t_str	*str_rfind_chr(t_str *this, char other, int32_t n)
{
	int32_t	i;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "rfind"));
	i = (int32_t)(this->end - this->begin) - 1;
	while (i > this->i && this->buff[i] != other)
		i--;
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}

t_str	*str_rfind_char(t_str *this, const char *other, int32_t n)
{
	int32_t	i;
	int32_t	j;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "rfind"));
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

t_str	*str_rfind_str(t_str *this, t_str *other, int32_t n)
{
	int32_t	i;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "rfind"));
	i = (int32_t)(this->end - this->begin) - 1;
	while (i > this->i && this->buff[i] != *other->buff)
	{
		other->buff--;
		while (++other->buff)
			if (this->buff[i] == *other->buff)
				break ;
		i--;
	}
	other->buff = (int8_t *)other->begin;
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}
