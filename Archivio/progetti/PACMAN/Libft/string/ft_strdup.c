/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:05:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 17:02:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strdup(const char *str);

t_str	*str_sdup(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_sdup_str(this, other));
	else
		return (str_sdup_char(this, other));
}

char	*ft_strdup(const char *str)
{
	int		n;
	char	*camillo;

	if (!str)
		return (NULL);
	n = 0;
	while (str[n] != '\0')
		++n;
	camillo = (char *)CALLOC(n + 1, sizeof(char));
	if (camillo == NULL)
		return (0);
	n = 0;
	while (str[n] != '\0')
	{
		camillo[n] = str[n];
		++n;
	}
	return (camillo);
}

t_str	*str_sdup_char(t_str *this, const char *other)
{
	int	i;
	int	j;

	if (!other)
	{
		FREE(this->buff);
		this->buff = NULL;
		this->capacity = 0;
		this->len = 0;
		return (this);
	}
	i = ft_strlen(other);
	this->len = i;
	if (this->capacity < i)
		if (_str_reset(this, i)->err != 0)
			return (this);
	i = 0;
	j = 0;
	while (other[j])
		this->buff[i++] = other[j++];
	this->buff[i] = 0;
	return (this);
}

t_str	*str_sdup_str(t_str *this, const t_str *other)
{
	int	i;
	int	j;

	if (!other->buff)
	{
		FREE(this->buff);
		this->buff = NULL;
		this->capacity = 0;
		this->len = 0;
		return (this);
	}
	i = other->len;
	this->len = i;
	if (this->capacity < i)
		if (_str_reset(this, i)->err != 0)
			return (this);
	i = 0;
	j = 0;
	while (other->buff[j])
		this->buff[i++] = other->buff[j++];
	this->buff[i] = 0;
	return (this);
}
