/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 17:24:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*free_matrix(char **matrix);
void	*free_three_d_matrix(char ***matrix);

// Memoria statica usata ---> (BUFFER_SIZE + 1) * ((MAX_FILES + 1) * 20)
#ifndef MFILE_H
# define MFILE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# ifndef MAX_FILES
#  define MAX_FILES 20
# endif
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <malloc.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft.h"

typedef struct s_fd
{
	int			p;
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
int				ft_open(const char *filename, const char *perm);
t_manage_fds	*fd_database(bool);
int				get_filedata(t_fd *fd, char **filename);
void			del_filedata(void);
int				switch_filedata(t_fd fd);
int				fd_indexation(void);
void			closefd(t_fd fd);
int				read_curr(t_manage_fds *data, int count);
int				readfd(t_fd	fd, char *buff, int count);
char			*get_static_buffer(int fd, bool reset, bool reset_all);
char			*gnl();
int				writefd(t_fd fd, const char *s, size_t len);
int				reset_fd(t_fd fd);

#endif