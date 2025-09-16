/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:12:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:42:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(t_data *data, int err_type)
{
	free_memory(data);
	exit(err_type);
}

void	free_memory(t_data *data)
{
	FREE(data->hash_table);
	FREE(data->collision);
	del_filedata();
}

void	alloc_memory(t_data *data)
{
	int	i;

	data->hash_table = (t_hash *)ft_calloc(data->hash_size, sizeof(t_hash));
	if (!data->hash_table)
		error(data, ER_MALLOC);
	data->collision = (int *)ft_calloc(data->hash_size, sizeof(int));
	if (!data->collision)
		error(data, ER_MALLOC);
	i = -1;
	while (++i != data->hash_size)
		data->hash_table[i].key = -1;
}
