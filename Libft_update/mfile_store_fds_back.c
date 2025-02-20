/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_store_fds_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:46:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 15:22:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

static int	add_file(int fd, char *filename, t_manage_fds *stock);
static int	switch_file(int which, t_manage_fds *stock, int mode, int fd);
static int	del_files(t_manage_fds *stock);
static int	give_data(int *fd, char **filename, t_manage_fds *stock);

/*
    FLAG = 0:   Add a new file
    FLAG = 1:   Switch fd
	FLAG = 2:	Close and free memory
	FLAG = 3:	Give data
	FLAG = 4:	Change fd
	
	DON'T USE THESE! USE THE OTHERS INSTEAD!
*/
int manage_fds(int *fd, char **filename, int which, int flag)
{
    static t_manage_fds	stock;

	if (flag == 0)
	{
		if ((!filename) || (!*filename) || (!fd) || (*fd < 0))
			return (2);
		return (add_file(*fd, *filename, &stock));
	}
	else if (flag == 1)
		return (switch_file(which, &stock, 0, 0));
	else if (flag == 2)
		return del_files(&stock);
	else if (flag == 3)
		return (give_data(fd, filename, &stock));
	else if (flag == 4)
		return (switch_file(which, &stock, *fd, 1));
	return (-1);
}

static int	add_file(int fd, char *filename, t_manage_fds *stock)
{
	if (stock->file_num - 1 == stock->max_files)
		return (1);
	stock->fds[stock->file_num] = fd;
	stock->curr_fd = fd;
	stock->curr_file = filename;
	stock->filenames[stock->file_num] = filename;
	stock->fd_index = stock->file_num;
	stock->file_num += 1;
	return (0);
}

/*
	Mode 0: switch current file;
	Mode 1: change selected fd into another;
*/
static int	switch_file(int which, t_manage_fds *stock, int mode, int fd)
{
	int	index;

	index = 0;
	while ((index < stock->file_num) && (stock->fds[index] != which))
	{
		++index;
	}
	if (index == stock->file_num)
		return (1);
	if (mode == 0)
	{
		stock->curr_fd = stock->fds[index];
		stock->fd_index = index;
		stock->curr_file = stock->filenames[index];
	}
	if (mode != 1)
		return (0);
	stock->fds[index] = fd;
	return (0);
}

static int	del_files(t_manage_fds *stock)
{
	int	index;

	index = 0;
	while (index < stock->file_num)
	{
		close(stock->fds[index]);
		++index;
	}
	*stock = (t_manage_fds){0};
	return (0);
}

static int	give_data(int *fd, char **filename, t_manage_fds *stock)
{
	if ((!fd) || (!filename))
		return (1);
	*fd = stock->curr_fd;
	*filename = stock->curr_file;
	return (0);
}