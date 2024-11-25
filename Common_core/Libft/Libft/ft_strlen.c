/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:33:36 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:25:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t ft_strlen(const char *s);

size_t ft_strlen(const char *s)
{
	size_t	strlen;

	strlen = 0;
	while ((*s++ != '\0'))
		++strlen;
	return (strlen);
}
