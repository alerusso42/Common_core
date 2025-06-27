/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_gnl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/05 01:04:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Memoria statica usata ---> (BUFFER_SIZE + 1) * ((MAX_FILES + 1) * 20)
#ifndef MFILE_GNL_H
# define MFILE_GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# ifndef MAX_FILES
#  define MAX_FILES 120
# endif
// Define usati nel programma
# define SHORTWORDS_LEN 4
# define MIDWORDS_LEN 10
// Librerie
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
	SDL_RWops	*p;
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

//		ORIGINAL GNL

char	*gnl();
char	*gnl_original_main_function(int fd, char buffer[BUFFER_SIZE + 1]);
char	*get(char **store_bytes, char buffer[BUFFER_SIZE + 1], int nl, int fd);
int		go_read(int fd, char buffer[BUFFER_SIZE + 1], char **new_line);
int		loop_read(char **new_line, int *control_read, size_t *end, int fd);
int		alloc_ft(void **content, void *new_content, size_t start, int mode);
int		find_end_line(size_t *start, char *string);
void	*calloc_memcpy(int size, void *dest, const void *src, int ft);
void	trim_readbytes(char *buffer);
char	*ft_strjoin_custom(char *s1, char *s2);
//		WRITE_LINE SETTINGS

int		set_maximum_word_len(int new_len);
int		set_maximum_words(int new_len);
//		INITIATE FILE

void	initiate_file_demo(int fd, char *name);
void	initiate_file(int fd, char *name, char **matrix);
//		CUSTOM GNL (DONT USE IT!!)

char	*get_next_line(int fd, int reset);
char	*read_from_buffer(char buffer[BUFFER_SIZE + 1], int fd, int bytes);
char	*get_next_line_main_function(int fd, char buffer[BUFFER_SIZE + 1]);
//		DONT USE THESE: ONLY FOR LIBRARY PURPOSES!

int		find_line(int fd, int num_search, va_list list);
int		find_number_line(int fd, char *filename, int num_search, ...);
//		EXPANDED MANAGE_FILE FUNCTIONS

int		num_line(int num_search, ...);
void	hold_space(int counter, int fd);
int		move_cursor(int line_num);
char	*read_line(int line_num, int position);
char	**read_all_line(int line_num);
int		write_line(int line_num, int position, char *string);
char	*get_n_line(int fd, int n);
int		reset_fd(t_fd fd);

#endif