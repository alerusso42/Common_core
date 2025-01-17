/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ft2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:33:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/17 12:09:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_FT2_H
# define GENERAL_FT2_H
# include <stdio.h>
# include <malloc.h>
# include "general_ft.h"
# include <unistd.h>
# include <fcntl.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;

	pointer = NULL;
	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	ft_memset((void *)pointer, total_size);
	return (pointer);
}

/*
	This strlen stops when finds \n or \0.
*/
size_t	ft_strlen(char *string)
{
	size_t	size;

	if (!string)
		return (0);
	size = 0;
	while ((string[size]) && (string[size] != '\n'))
		++size;
	return (size);
}

#endif