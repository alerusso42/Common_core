/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_trim_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:08:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:42:58 by alerusso         ###   ########.fr       */
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
	FREE((*line));
	(*line) = trimmered_line;
	return (0);
}
