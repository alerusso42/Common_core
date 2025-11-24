/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:46:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 22:43:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//SECTION - public

int		str_get_start_index(t_str *str)
{
	return (str->i);
}

void	str_set_start_index(t_str *str, int i)
{
	str->i = i;
}

//SECTION - private

bool	_str_identifier(const void *p)
{
	const uint8_t	*s;
	uint64_t		id;
	int8_t			bytes;

	if (!p)
		return (false);
	s = (const uint8_t *)p;
	id = _STR_IDENTIFIER;
	bytes = sizeof(uint64_t);
	while (bytes)
	{
		if (*s != (id & 255))
			return (false);
		bytes--;
		++s;
		id >>= 8;
	}
	return (true);
}

t_str	*_str_reset(t_str *this, int i)
{
	this->capacity = -1;
	FREE(this->buff);
	this->buff = CALLOC(i + 1, sizeof(char));
	if (!this->buff)
		return (_str_set_error(this, E_ALLOC, "dup"));
	this->capacity = i;
	_str_set(this);
	return (this);
}
