/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:07:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/16 14:40:46 by alerusso         ###   ########.fr       */
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
	data->files_names = free_matrix(data->files_names);
	free(data->conf.default_flags);
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
	i = 0;
	while (filedata->node[i])
	{
		current = filedata->node[i];
		while (current)
		{
			next = current->next;
			SDL_free(current);
			current = next;
		}
		++i;
	}
}