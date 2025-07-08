/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_gnl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 16:55:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Memoria statica usata ---> (BUFFER_SIZE + 1) * ((MAX_FILES + 1) * 20)
#ifndef MFILE_GNL_H
# define MFILE_GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# ifndef MAX_FILES
#  define MAX_FILES 20
# endif
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <malloc.h>
# include <fcntl.h>
# include <limits.h>
# include "structs.h"
# include "libft.h"
# include "other.h"

typedef unsigned char	t_ob;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_fd
{
	SDL_IOStream	*p;
	int			n;
}	t_fd;

typedef struct s_manage_fds
{
	char	buffer[MAX_FILES + 1][BUFFER_SIZE + 1];
	t_fd	fds[MAX_FILES + 1];
	char	*filenames[MAX_FILES + 1];
	t_fd	curr_fd;
	char	*curr_file;
	int		last;
}			t_manage_fds;

//		SDL_SUPPORT

t_fd			openfd(const char *filename, const char *permissions);
t_manage_fds	*fd_database(bool delete);
int				get_filedata(t_fd *fd, char **filename);
void			del_filedata(void);
int				switch_filedata(t_fd fd);
int				fd_indexation(void);
void			closefd(t_fd fd);
int				read_curr(t_manage_fds	*data, int count);
int				readfd(t_fd	fd, char *buff, int count);
char			*get_static_buffer(int fd, bool reset, bool reset_all);
char			*gnl();
int				writefd(SDL_IOStream *fd, const char *s, size_t size, size_t len);
int				reset_fd(t_fd fd);

#endif