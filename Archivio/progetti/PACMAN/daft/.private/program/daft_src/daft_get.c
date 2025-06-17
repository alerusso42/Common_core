/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:44:50 by codespace         #+#    #+#             */
/*   Updated: 2025/06/17 09:52:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*daft_get(char *search)
{
	t_daft_data	*data;
	int			hash_result;
	int			offset;
	t_fd		fd;
	void		*mem;

	if (!search)
		return (NULL);
	data = _daft_get_memory(NULL, false);
	if (!data)
		return (0);
	hash_result = _daft_hash(data->data_list[data->current_file], search);
	//da mettere in un while
	if (!data->data_list[data->current_file]->node[hash_result])
		return (NULL);
	offset = data->data_list[data->current_file]->node[hash_result]->offset;
	fd = openfd(data->data_list[data->current_file]->filename, "r");
	if (!fd.n)
		return (NULL);
	SDL_RWseek(fd.p, offset, 0);
	mem = gnl();
	closefd(fd);
	return (mem);
}
