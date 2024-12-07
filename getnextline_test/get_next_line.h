/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:30:53 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/04 14:23:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define CHUNK 32
#define TRUE 1
#define MALLOC 1
#define REALLOC 2
#define FREE 3
#define ERROR_READING_FILE -1
#define END_OF_FILE -1
#define EOF_OR_NEWLINE_NOT_FOUND -1
#define WHEN_FOUND_EOF_OR_NEWLINE_STOPLOOP -1
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include <fcntl.h>

char 	*get_next_line(int fd);
void	*alloc_system(void *content, size_t start, size_t end, short int mode);
int		find_end_line(size_t *start, size_t end, char *string, int bytes_read);
int		ft_readfile(char **string, int fd, size_t *start, int *bytes_read);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
