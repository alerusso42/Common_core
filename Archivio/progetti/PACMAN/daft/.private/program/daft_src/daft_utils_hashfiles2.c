/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_hashfiles2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:06:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/16 19:41:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_one(t_daft_node *node, char *offsets);

int	_daft_get_data2(t_daft_list *file)
{
	char	*line;

	line = gnl();
	while (line)
	{
		if (get_one(file->node[(int)ft_atoi(line)], line) != 0)
			return (SDL_free(line), DAFT_LOG_MALLOC);
		SDL_free(line);
		line = gnl();
	}
	return (0);
}

static int	get_one(t_daft_node *node, char *offsets)
{
	bool	first_allocation;
	int		i;
	int		offset;

	first_allocation = true;
	i = sub_strlen(offsets, " \t", EXCLUDE);
	while (offsets[i])
	{
		i += 1;
		offset = (int)ft_atoi(offsets + i);
		if (first_allocation == true)
		{
			if (_daft_start_list(offset) != 0)
				return (_daft_log(DAFT_LOG_MALLOC));
			first_allocation = false;
		}
		else
		{
			if (_daft_add_node_back(node, offset) != 0)
				return (_daft_log(DAFT_LOG_MALLOC));
		}
		i = sub_strlen(offsets + i, " ", EXCLUDE);
	}
	return (0);
}
