/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:07:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/17 15:00:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	free_filedata(t_daft_list *filedata);	

void daft_quit(void)
{
	t_daft_data	*data;
	int			i;

	data = _daft_get_memory(NULL, false);
	_daft_get_memory(NULL, true);
	if (!data)
		return ;
	del_filedata();
	_daft_free_old_mem(data);
	data->files_names = free_matrix(data->files_names);
	SDL_free(data->conf.default_flags);
	data->conf.default_flags = NULL;
	i = 0;
	if (!data->data_list)
		return (SDL_free(data));
	while (data->data_list[i])
	{
		free_filedata(data->data_list[i]);
		data->data_list[i] = NULL;
		++i;
	}
	SDL_free(data->data_list);
	data->data_list = NULL;
	SDL_free(data);
}

static void	free_filedata(t_daft_list *filedata)
{
	int			i;
	t_daft_node	*next;
	t_daft_node	*current;

	if (!filedata->node)
	{
		SDL_free(filedata);
		return ;
	}
	i = -1;
	while (++i < filedata->size)
	{
		if (filedata->node[i])
		{
			current = filedata->node[i];
			while (current)
			{
				next = current->next;
				SDL_free(current);
				current = next;
			}
		}
	}
	SDL_free(filedata->node);
	SDL_free(filedata);
}