/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:46:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 10:45:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

bool	_str_identifier(const void *p)
{
	const uint8_t	*s;
	int8_t			bytes;

	if (!p)
		return (false);
	s = (const uint8_t *)p;
	bytes = sizeof(uint64_t);
	while (bytes)
	{
		if (*s != 255)
			return (false);
		bytes--;
		++s;
	}
	return (true);
}
