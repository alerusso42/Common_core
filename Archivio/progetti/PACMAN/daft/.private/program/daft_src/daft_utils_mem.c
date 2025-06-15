/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:38:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/16 00:42:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_daft_data	*_daft_get_memory(t_daft_data *new_data, bool update)
{
	static t_daft_data	*ptr;

	if (update)
		ptr = new_data;
	return (ptr);
}

int	resize_matr(char **old_matr, int *old_size)
{
	char	*new_matr;
	int		new_size;
	int		i;

	if (!old_matr || !old_size)
		return (DAFT_LOG_MALLOC);
	if (!*old_size)
		new_size = 2;
	else
		new_size = *old_size * 2;
	new_matr = ft_calloc(new_size + 1, sizeof(char *));
	if (!new_matr)
		return (DAFT_LOG_MALLOC);
	*old_size = new_size;
	i = 0;
	while (old_matr[i])
	{
		new_matr[i] = ft_strdup(old_matr[i]);
		++i;
	}
}
