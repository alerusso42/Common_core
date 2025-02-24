/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:10:37 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/24 11:20:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

int	ft_realloc(void **content, size_t nmemb, size_t size)
{
	void	*re_content;

	re_content = ft_calloc(nmemb, sizeof(void *));
	if (!(re_content))
		return (1);
	ft_memcpy(re_content, *content, nmemb * size);
	free(*content);
	*content = re_content;
	return (0);
}
