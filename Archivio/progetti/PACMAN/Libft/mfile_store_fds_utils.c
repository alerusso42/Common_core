/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_store_fds_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 08:43:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/19 11:31:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

int				fd_indexation(void);
t_manage_fds	*fd_database(bool delete);

int	fd_indexation(void)
{
	t_manage_fds	*data;
	int				i;

	data = fd_database(0);
	i = 1;
	while (data->fds[i].n && i != MAX_FILES)
		++i;
	if (i == MAX_FILES)
		return (0);
	data->fds[i].n = i;

	return (i);
}

t_manage_fds	*fd_database(bool delete)
{
	static t_manage_fds	data;

	if (delete)
	{
		data = (t_manage_fds){0};
	}
	return (&data);
}

#define POKEDEX "../../../../getnextline/updated_pokedex.txt"
#define TEST "../tests/long.txt"
#include <unistd.h>
#include <malloc.h>
#include <fcntl.h>
int main()
{
	t_fd	fd1 = openfd(POKEDEX, "r");
	t_fd	fd2 = openfd(TEST, "a+");
	char *s = NULL;
	int size = SDL_RWsize(fd1.p);
	s = malloc(size + 1);
	size = SDL_RWread(fd1.p, s, sizeof(char), size);
	s[size] = 0;
	char	*tmp = memchr(s, 'G', size);
	SDL_RWwrite(fd2.p, tmp, sizeof(char), 40);
    free(s);
	t_fd	fd;
	get_filedata(&fd, &s);
	switch_filedata(fd1);
	get_filedata(&fd, &s);
	switch_filedata(fd2);
	get_filedata(&fd, &s);
	del_filedata();
	return (0);
}
