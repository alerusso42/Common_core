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

//allocation bigger than UINT_MAX - sizeof(t_list *) causes underflow
# define ALLOC_MAX_SIZE (UINT_MAX - (uint32_t)sizeof(t_list *))

/*SECTION - structs representation
STRUCT		UTILITY				EXAMPLE
________________________________________________________________________________
t_alloc		|Stores:			|
			|1)alloc. metadata	|bytes alloc./freed, pagesize*1, ...
			|2)memzone size		|tiny, small, large block area/zone size
			|3)t_memzone lists	|tiny, small, large area. memory given by t_pool
			|					|
t_memzone	|store:				|TINY_ZONE|SMALL_ZONE|TINY_ZONE|LARGE_ZONE|...|
			|1)user data;		|	
			|2)t_area bytelist*2|	
			|					|	
t_area		|malloc returned ptr|	ptr = malloc(42)
			|metadata			|	ptr = header t_area + 42 bytes requested
________________________________________________________________________________
*1 pagesize is the size of kernel disks pages. mmaped size must a multiple of it
*2 bytelist is a list that moves using pointer arithmetic 
________________________________________________________________________________

//NOTE - EXAMPLE OF t_area
h = t_area header --> sizeof(t_area) = 9
b = bytes requested
	_____________________________________________	___________________
	|			ZONE OF 256 BYTES				|	|ZONE OF 4096 BYTES|
	|156 bytes allocated, 100 bytes free		|-->|__________________| -> ...
	|h9b16   +   h9b2   + h9b100   + h9b2 =		|		
	|25 byte +  11 byte + 109 byte + 11 byte 	|		
	|	|			|		|			|		|
next|	25			11		109			0		|
prev|	0			25		11			109		|
info|	alloc.		alloc.	alloc.		alloc.	|
	|___________________________________________|

//NOTE - FREEING t_area chunks
memory are just labeled as freed.
Let's free, for example, 3° and 2° chunk:
	_____________________________________________	___________________
	|			ZONE OF 256 BYTES				|	|ZONE OF 4096 BYTES|
	|156 bytes allocated, 100 bytes free		|-->|__________________| -> ...
	|h9b16   +   h9b2   + h9b100   + h9b2 =		|		
	|25 byte +  11 byte + 109 byte + 11 byte 	|		
	|	|			|		|			|		|
next|	25			11		109			0		|
prev|	0			25		11			109		|
info|	alloc.		freed	freed		alloc.	|
	|___________________________________________|

//NOTE - COALESCING
if nearby freed area collides, they are merged.
prev and next are updated:
	_____________________________________________	___________________
	|			ZONE OF 256 BYTES				|	|ZONE OF 4096 BYTES|
	|156 bytes allocated, 100 bytes free		|-->|__________________| -> ...
	|h9b16   +   h9b2  	 + h9b2 =					|		
	|25 byte +  120 byte + 11 byte 				|		
	|	|			|		|					|
next|	25			120		0					|
prev|	0			25		120					|
info|	alloc.		freed	alloc.				|
	|___________________________________________|

*/

typedef	int32_t	t_bytelist;

/*
	when malloc is called, a t_area node is created.
	it represent ptr data.
	t_mem nodes are gathered by t_memzone var "area"

	info is a bitmask of e_area_info
*/
typedef	struct s_area
{
	t_bytelist	next;
	t_bytelist	prev;
	uint8_t		info;
}	t_area;

enum	e_area_info
{
	MEM_FREED = 1 << 0,
};

/*
	when mmap is called, a t_memzone node is created.
	it represent mmaped zone data.
	t_memzone nodes are gathered by t_alloc.
*/
typedef	struct s_memzone
{
	void		*ptr_node;
	t_bytelist	area;//list of area in the zone
	t_bytelist	first_free_area;//first free area, starting from left
	uint32_t	size;
	uint32_t	free_space;
	uint32_t	longest_chunk;//longest freed chunk
	uint32_t	index;
}	t_memzone;

/*
	stores the maximum size for every mmap area/zone type.
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
enum e_sizelimit_info
{
	POOL_SIZE = 120 * 32,//120: max t_memzone nodes; 32: sizeof(t_memzone)
	AREA_NUM = 4,//2^AREA_NUM represents the number of areas in a zone
	ZONE_TINY = (1 << 12),
	ZONE_SMALL = (1 << 18),
	AREA_TINY = ZONE_TINY >> AREA_NUM,
	AREA_SMALL = ZONE_SMALL >> AREA_NUM,
};

/*
list content must be stored somewhere.
pool is a memory pool for the list of t_memzone.
*/
typedef	struct s_pool
{
	void		*mem;
	uint32_t	bytes;
	uint32_t	len;
	uint32_t	size;
}	t_pool;

typedef struct s_alloc
{
//SECTION - zone size info
	t_sizelimit	size_zone;
	t_sizelimit	size_area;
//SECTION - zone memory pool and list
	t_pool		pool;
	t_list		*zone_tiny;
	t_list		*zone_small;
	t_list		*zone_large;
//SECTION - allocation metadata
	void 		*ptr_max;
	void 		*ptr_min;
	int			pagesize;
	uint32_t	bytes_alloc;
	uint32_t	bytes_freed;
}	t_alloc;

enum e_mmap_flags
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
void	*error_malloc(char *s);

#endif