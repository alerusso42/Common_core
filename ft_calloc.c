/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:05:17 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 16:42:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include "libft.h"
#define FULL_MEMORY 2

void 		*ft_calloc(size_t nmemb, size_t size);

/*
int	main()
{
	char	*pointer;

	pointer = (char *)ft_calloc(7, 0);
	if (pointer == NULL)
		return (FULL_MEMORY);
	pointer = ft_strcpy(pointer, "sdv");
	printf("\n%s\n", pointer);
	free(pointer);
	return (0);
}*/

void *ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;

	if ((nmemb == 0) || (size == 0))
		return (NULL);
	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	else
	{
		ft_memset(pointer, 0, nmemb);
		return (pointer);
	}
}
