/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:03:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 20:24:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_str	*str_excpy(t_str *this, const void *other, const void *set)
{
	const char	*charset;

	if (_str_identifier(set) == true)
		charset = ((const t_str *)set)->buff;
	else
		charset = (const char *)set;
	if (_str_identifier(other) == true)
		return (str_scpy_str(this, other, charset, EXCLUDE));
	else
		return (str_scpy_char(this, other, charset, EXCLUDE));
}
