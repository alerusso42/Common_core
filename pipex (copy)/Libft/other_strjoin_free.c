/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_strjoin_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:26:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 14:26:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*stringona;
	int		index;
	int		size;

	if ((!s1) || (!s2))
		return (free(s1), free(s2), NULL);
	index = 0;
	while (s1[index])
		++index;
	size = index;
	index = 0;
	while (s2[index])
		++index;
	size += index;
	stringona = (char *)ft_calloc(size + 2, sizeof(char));
	if (!stringona)
		return (free(s1), free(s2), NULL);
	index = -1;
	while (s1[++index])
		stringona[index] = s1[index];
	size = -1;
	while (s2[++size])
		stringona[index++] = s2[size];
	return (free(s1), free(s2), stringona);
}
