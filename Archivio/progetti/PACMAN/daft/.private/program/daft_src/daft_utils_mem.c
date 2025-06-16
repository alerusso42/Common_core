/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:38:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/16 14:49:27 by alerusso         ###   ########.fr       */
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

int	_daft_resize_matr(char ***old_matr, int *size)
{
	char	**new_matr;
	int		i;

	if (!old_matr || !size)
		return (DAFT_LOG_MALLOC);
	if (!*size)
		*size = 2;
	else
		*size = *size * 2;
	new_matr = ft_calloc(*size + 1, sizeof(char *));
	if (!new_matr)
		return (DAFT_LOG_MALLOC);
	i = 0;
	while ((*old_matr) && (*old_matr)[i])
	{
		new_matr[i] = ft_strdup((*old_matr)[i]);
		if (!new_matr[i])
			return (free_matrix(new_matr), DAFT_LOG_MALLOC);
		++i;
	}
	free_matrix(*old_matr);
	*old_matr = new_matr;
	return (0);
}

t_daft_node	*_daft_start_list(int offset)
{
	t_daft_node	*list;

	list = ft_calloc(1, sizeof(t_daft_node));
	if (!list)
		return (NULL);
	list->offset = offset;
	return (list);
}

int	_daft_add_node_back(t_daft_node	*list, int offset)
{
	t_daft_node	*node;

	node = ft_calloc(1, sizeof(t_daft_node));
	if (!node)
		return (1);
	node->offset = offset;
	while (list->next)
		list = list->next;
	list->next = node;
	return (0);
}
