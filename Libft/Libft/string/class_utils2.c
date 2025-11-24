/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:46:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 17:48:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

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

int		str_get_start_index(t_str *str)
{
	return (str->i);
}

void	str_set_start_index(t_str *str, int i)
{
	str->i = i;
}
