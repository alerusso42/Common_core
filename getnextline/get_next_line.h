/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:30:53 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/07 18:26:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
#define COUNTER 100000000
#define FORCE_READ_ONE_TEXT 4
#define TRUE 1
#define MALLOC 1
#define REALLOC 2
#define FREE 3
#define FULL_MEMORY 0
#define SUCCESS 1
#define ALLOCATION_SUCCESS 1
#define ERROR_READING_FILE -1
#define END_OF_FILE -1
#define NO_NEWLINE_FOUND 0
#define EMPTY_BUFFER 0
#define END_OR_CORRUPTION -1
#define EOF_OR_NEWLINE_FOUND 0
#define EOF_OR_NEWLINE_NOT_FOUND -1
#define WHEN_FOUND_EOF_OR_NEWLINE_STOPLOOP -1
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include <fcntl.h>
#include <limits.h>

char 	*get_next_line(int fd);
char 	*get_next_line_main_function(int fd, char buffer[BUFFER_SIZE + 1]);
int		go_read(int fd, char buffer[BUFFER_SIZE + 1], char **new_line);
int		alloc_ft(void **content, void *new_content, size_t start, int mode);
int		find_end_line(size_t *start, char *string);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, int n);
void	trim_readbytes(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
