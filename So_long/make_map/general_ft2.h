/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ft2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:33:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/14 10:38:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_FT2_H
# define GENERAL_FT2_H
# include <stdio.h>
# include <malloc.h>
# include "general_ft.h"

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

#endif