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
# include <stdint.h>
# include <malloc.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <sys/mman.h>
# include <sys/unistd.h>
# include <sys/fcntl.h>

int	ft_printf(const char *str, ...);

# define DEBUG true
# if DEBUG == true
#  define PRINT(s, ...) ft_printf(s, ##__VA_ARGS__)
# else
#  define PRINT(s, ...)	(void)0
# endif
//FIXME - da togliere!
#include <valgrind/memcheck.h>

typedef struct s_sizelimit
{
	int			tiny;
	int			small;
	int			large;
}	t_sizelimit;

typedef struct s_alloc
{
	t_sizelimit	limits;
	void 		*ptr_max;
	void 		*ptr_min;
	void 		*ptr_start;
	void 		*ptr_curr;
	int			pagesize;
	size_t		offset;
	size_t		bytes_alloc;
	size_t		bytes_freed;
}	t_alloc;

typedef struct s_info
{
	size_t	bytes;
	size_t	kernel_offset;
}	t_info;

# define ALLOC_MAX_SIZE (UINT_MAX - (unsigned long)sizeof(t_info))
enum e_alloc
{
	ALLOC_TINY = (1 << 8),
	ALLOC_SMALL = (1 << 16),
	ALLOC_LARGE = (1 << 24),
};

enum e_alloc_flags
{
	PROT_RDWR = PROT_READ | PROT_WRITE,
	MAP_AP = MAP_ANONYMOUS | MAP_PRIVATE,
	MAP_APF = MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED,
};

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

//SECTION - utils

t_alloc	*_global_data(bool reset);
int	round_page(int n, int pagesize);

#endif