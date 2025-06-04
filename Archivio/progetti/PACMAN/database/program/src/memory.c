/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:12:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/04 21:02:51 by alerusso         ###   ########.fr       */
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
	SDL_free(data->hash_table);
	del_filedata();
	return ;
}

void	alloc_memory(t_data *data)
{
	data->hash_table = (t_hash *)ft_calloc(data->hash_size, sizeof(t_hash));
	if (!data->hash_table)
		error(data, ER_MALLOC);
}