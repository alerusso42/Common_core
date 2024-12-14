/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:43:14 by negambar          #+#    #+#             */
/*   Updated: 2024/11/26 11:12:35 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(char *s);
char	*gnl_substr(char const *s, unsigned int start, char stop_char);
char	*gnl_calloc(size_t count, size_t size);
char	*ft_get_line(int fd, char *buffer, char *nextl);
char	*gnl(int fd);
char	*ft_str(char *s);

#endif