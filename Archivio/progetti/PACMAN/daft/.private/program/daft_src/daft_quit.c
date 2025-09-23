/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:07:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/23 18:23:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static void	free_filedata(t_daft_list *filedata);	
static void	update_filedata(t_daft_data *data);

/*
//REVIEW -	daft_quit
//
	Reset daft memory.
	Always safe to call, even multiple times.
*/
void daft_quit(void)
{
	t_daft_data	*data;
	int			i;

	data = _daft_get_memory(NULL, false);
	_daft_get_memory(NULL, true);
	if (!data)
		return ;
	update_filedata(data);
	_daft_free_mem(data, -1);
	del_filedata();
	data->files_names = free_matrix(data->files_names);
	FREE(data->conf.default_flags);
	data->conf.default_flags = NULL;
	FREE(data->error_message);
	data->error_message = NULL;
	i = 0;
	if (!data->data_list)
		return (FREE(data));
	while (data->data_list[i])
	{
		free_filedata(data->data_list[i]);
		data->data_list[i] = NULL;
		++i;
	}
	FREE(data->data_list);
	data->data_list = NULL;
	FREE(data);
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
		FREE(filedata);
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
				FREE(current);
				current = next;
			}
		}
	}
	FREE(filedata->node);
	FREE(filedata);
}

static void	update_filedata(t_daft_data *data)
{
	int	i;

	if (!data->data_list)
		return ;
	i = 0;
	while (data->data_list[i])
	{
		if (data->data_list[i]->edit)
			_daft_update_data(data, i);
		if (data->data_list[i]->append)
			_daft_append_data(data, data->data_list[i], i);
		if (data->data_list[i]->edit || data->data_list[i]->append)
			_daft_edit_hash_file(data->data_list[i], i);
		++i;
	}
}
