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
# include "../all.h"

int	ft_printf(const char *str, ...);

# define DEBUG true
# if DEBUG == true
#  define PRINT(s, ...) ft_printf(s, ##__VA_ARGS__)
# else
#  define PRINT(s, ...)	(void)0
# endif
//FIXME - da togliere!
#include <valgrind/memcheck.h>

//allocation bigger than UINT LIMIT - sizeof(t_list *) causes underflow
# define ALLOC_MAX_SIZE (UINT_MAX - (unsigned long)sizeof(t_list *))

/*
	when malloc is called, a t_mem node is created.
	it represent ptr data.
	t_mem nodes are gathered by t_memzone var "area"

	flags area a bitmask of e_mem_flags
*/
typedef	struct s_mem
{
	uint32_t	size;
	uint32_t	head_offset;//distanza da head
	void		*ptr;
	uint8_t		flags;
}	t_mem;

enum	e_mem_flags
{
	MEM_FREED = 1 << 0,
	MEM_TINY = 1 << 1,
};

/*
	when mmap is called, a t_memzone node is created.
	it represent mmaped zone data.
	t_memzone nodes are gathered by t_alloc.
*/
typedef	struct s_memzone
{
	t_list		*area;
	t_list		*first_free_area;//a partire da sinistra, prima area disponibile
	uint32_t	size;
	uint32_t	free_space;
	uint32_t	longest_chunk;
}	t_memzone;

/*
	stores the maximum size for every mmap zone type.
*/
typedef struct s_sizelimit
{
	uint32_t	tiny;
	uint32_t	small;
	uint32_t	large;
}	t_sizelimit;

/*
tiny allocation are less than ALLOC_TINY rounded by pagesize.
small allocation are less than ALLOC_SMALL rounded by pagesize.
large allocation are bigger than ALLOC_SMALL rounded by pagesize.
*/
enum e_alloc
{
	ALLOC_TINY = (1 << 9),
	ALLOC_SMALL = (1 << 12),
};

typedef struct s_alloc
{
	t_sizelimit	limit;
	t_memzone	*lst_tiny;
	t_memzone	*lst_small;
	t_memzone	*lst_large;
	void 		*ptr_max;
	void 		*ptr_min;
	void 		*ptr_start;
	void 		*ptr_curr;
	int			pagesize;
	uint32_t	bytes_alloc;
	uint32_t	bytes_freed;
}	t_alloc;

enum e_alloc_flags
{
	PROT_RDWR = PROT_READ | PROT_WRITE,
	MAP_AP = MAP_ANONYMOUS | MAP_PRIVATE,
	MAP_APF = MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED,
};

void 	*malloc(uint32_t size);
void 	free(void *ptr);
void 	_free(void *ptr);
void 	*_malloc(uint32_t size);
void 	*_realloc(void *ptr, uint32_t size);

//SECTION - testing

void 	*malloc_file(uint32_t size, const char *file);
void 	*malloc_virtualfile(uint32_t size, const char *file);
void 	*malloc_tempfile(uint32_t size);
void	*malloc_anonymous(uint32_t size);
void 	print_extreme(void *p, t_alloc *dt, bool print);

//SECTION - utils

t_alloc	*_global_data(bool reset);
int		round_page(int n, int pagesize);
void	*malloc_error(char *s);

#endif