/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:10:37 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 12:32:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

int	ft_realloc(void **content, size_t nmemb, size_t size)
{
	void	*re_content;

	re_content = ft_calloc(nmemb, size);
	if (!(re_content))
		return (1);
	ft_memcpy(re_content, *content, nmemb - size);
	free(*content);
	*content = re_content;
	return (0);
}
