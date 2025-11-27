/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:10:37 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 16:44:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_realloc(void **content, size_t nmemb, size_t size)
{
	void	*re_content;

	re_content = ft_calloc(nmemb, sizeof(void *));
	if (!(re_content))
		return (1);
	ft_memcpy(re_content, *content, nmemb * size);
	FREE(*content);
	*content = re_content;
	return (0);
}
