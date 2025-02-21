/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_trim_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:08:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 12:32:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

int	trim_only_right(char **line, char *trimset)
{
	char			*trimmered_line;
	unsigned int	index;

	index = 0;
	while (ft_strchr(trimset, (*line)[index]) == NULL)
	{
		index++;
	}
	trimmered_line = ft_substr((*line), 0, index);
	if (!trimmered_line)
		return (1);
	free((*line));
	(*line) = trimmered_line;
	return (0);
}
