/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:07:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/17 22:58:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	free_filedata(t_daft_list *filedata);	

/*
//REVIEW -	daft_quit
//
	Reset daft memory.
	Always safe to calls, even multiple times.
*/
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

//	Filedata is the struct of files inner data (flags, filenames, hash data).
//	filedata->node is an array of lists.
//	Every node in the lists stores an offset.
//	A list is accessed using its index, given by the search string hash.
//	For collisions, every list has a next ptr.
/*
	This function frees:
		-	The filedata array;
		-	The filedata;
		-	The lists array (node);
		-	The lists (node[i]).
*/
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