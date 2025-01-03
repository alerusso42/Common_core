/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:08:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/03 18:14:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>

static size_t	ft_strlen(const char *string)
{
	unsigned int	index;

	index = 0;
	while (string[index])
		++index;
	return (index);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*pointer;

	if ((!dest) && (!src))
		return (NULL);
	pointer = dest;
	while ((n--) && (dest))
	{
		*((char *)dest) = *((char *)src);
		++dest;
		++src;
	}
	return (pointer);
}