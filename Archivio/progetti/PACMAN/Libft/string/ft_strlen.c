/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:33:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/15 17:07:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strlen(const char *s)
{
	size_t	strlen;

	strlen = 0;
	while ((*s++ != '\0'))
		++strlen;
	return (strlen);
}

int	str_get_len(t_str *str)
{
	if (str->len)
		return (str->len);
	return (str->end - str->begin);
}
