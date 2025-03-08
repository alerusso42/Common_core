/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:37:29 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/30 14:50:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*string_pointer;
	size_t	stop_process;

	string_pointer = (char *)s;
	stop_process = 0;
	while (stop_process != n)
	{
		string_pointer[stop_process] = 0;
		++stop_process;
	}
}
