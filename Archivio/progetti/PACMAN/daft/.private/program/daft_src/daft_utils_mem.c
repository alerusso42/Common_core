/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:38:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/17 14:58:05 by codespace        ###   ########.fr       */
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

int	_daft_start_list(t_daft_node **list, int offset)
{
	*list = ft_calloc(1, sizeof(t_daft_node));
	if (!*list)
		return (1);
	(*list)->offset = offset;
	return (0);
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

void	_daft_free_old_mem(t_daft_data *data)
{
	if (!data->mem.type == NO_MEM)
		return ;
	else if (data->mem.type == STRING)
		SDL_free(data->mem.ptr);
	else if (data->mem.type == TWO_D_MATRIX)
		free_matrix(data->mem.ptr);
	else if (data->mem.type == THREE_D_MATRIX)
		free_three_d_matrix(data->mem.ptr);
	data->mem.ptr = NULL;
	data->mem.type = NO_MEM;
}
