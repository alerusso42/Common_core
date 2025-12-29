/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:21:38 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/29 17:21:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/mman.h>
# include <sys/unistd.h>
# include <sys/fcntl.h>

//FIXME - da togliere!
#include <valgrind/memcheck.h>

void *malloc(size_t size);
void free(void *ptr);
void _free(void *ptr);
void *_malloc(size_t size);
void *_realloc(void *ptr, size_t size);

//SECTION - testing

void *malloc_file(size_t size, const char *file);
void *malloc_virtualfile(size_t size, const char *file);
void *malloc_tempfile(size_t size);
void *malloc_anonymous(size_t size);

#endif