/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:36 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/20 18:01:23 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Memoria statica usata ---> BUFFER_SIZE * 4000
// Define per il debug
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define COUNTER 100000000
# define FORCE_READ_ONE_TEXT 0
// Define usati nel programma
# define FIND 1
# define GET 2
# define MOVE 3
# define SHORTWORDS_LEN 4
# define MIDWORDS_LEN 10
# define RESET -2
# define MALLOC 1
# define REALLOC 2
# define FREE 3
# define CALLOC 4
# define MEMCPY 5
# define FULL_MEMORY -1
# define SUCCESS 1
# define NO_NEWLINE_FOUND 0
# define EOF_OR_NEWLINE_FOUND 1
# define EOF_OR_NEWLINE_NOT_FOUND -1
# define EMPTY_BUFFER 0
# define END_OR_CORRUPTION -1
// Librerie
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <malloc.h>
# include <fcntl.h>
# include <limits.h>
# include "../gioco.h"

typedef unsigned char	t_ob;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char	*ft_itoa(int num);
void	initiate_file(int fd, char *name);
char	*get_next_line(int fd, int reset);
int		find_number_line(int fd, char *filename, int num_search, ...);
void	hold_space(int counter, int fd);
int		move_cursor(int fd, char *filename, int line_num);
char	*get_next_line_main_function(int fd, char buffer[BUFFER_SIZE + 1]);
char	*get(char **store_bytes, char buffer[BUFFER_SIZE + 1], int nl, int fd);
int		go_read(int fd, char buffer[BUFFER_SIZE + 1], char **new_line);
int		loop_read(char **new_line, int *control_read, size_t *end, int fd);
int		alloc_ft(void **content, void *new_content, size_t start, int mode);
int		find_end_line(size_t *start, char *string);
void	*calloc_memcpy(int size, void *dest, const void *src, int ft);
void	trim_readbytes(char *buffer);
char	*ft_strjoin_custom(char *s1, char *s2);
int		write_short_line(int fd, char *filename, int line_num, int position, char *string);
char	*line_fgm(int flag, int fd, int num_search, ...);

#endif