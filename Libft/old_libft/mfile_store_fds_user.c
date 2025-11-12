/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_store_fds_user.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:46:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/28 15:08:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

int	manage_fds(int *fd, char **filename, int which, int flag);

/*
	Give back current data.

	Give the address of a fd and a string.
*/
int	get_filedata(int *fd, char **filename)
{
	return (manage_fds(fd, filename, 0, 3));
}

/*
	Give a new fd and filename to the stock.

	They will be set as the current.

	If it fails (bad arg, other issues, return
	an error value different than 0).

	Else, return 0 on success.
	You should always check that it does not fail.
*/
int	give_filedata(int fd, char *filename)
{
	char	*dup_filename;

	dup_filename = ft_strdup(filename);
	return (manage_fds(&fd, &dup_filename, 0, 0));
}

/*
	Close every fd.
	Reset the stock.

	WARNING: 	the stock is NOT allocated with malloc.
				let this function manage close files.
*/
int	del_filedata(void)
{
	return (manage_fds(NULL, NULL, 0, 2));
}

/*
	Update the fd set as the current.
*/
int	switch_filedata(int fd)
{
	return (manage_fds(NULL, NULL, fd, 1));
}

/*
	Update an fd, for example when using reset_fd.
*/
int	update_filedata(int old_fd, int new_fd)
{
	return (manage_fds(&new_fd, NULL, old_fd, 4));
}
