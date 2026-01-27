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
# include <stdint.h>
# include <stdbool.h>
# include <stddef.h>
# define MALLOC_WARNINGS true

typedef struct s_alloc	t_alloc;

typedef	enum e_show_alloc_mem_flags
{
	MALL_SHOW_PRINT_ALL = 1,
	MALL_SHOW_PRINT_BIT = 2,
	MALL_SHOW_PRINT_HEX = 16,
	MALL_SHOW_PRINT_BYTE = 256,
	MALL_SHOW_FREED = 1 << 9,
}		e_show_alloc_mem_flags;

void 	*malloc(size_t size);
void 	free(void *ptr);
void 	*realloc(void *ptr, size_t size);
void	show_alloc_mem();
void	show_alloc_mem_ex(uint32_t flags);
void 	*calloc(size_t nmemb, size_t size);
int 	mallopt(int __param, int __val);
//SECTION - funzioni inutili da overlodare
void	*xmalloc(size_t size);
void 	*reallocarray(void *ptr, size_t nmemb, size_t size);
void	*memalign(size_t __alignment, size_t __size);
void 	*valloc(size_t __size);
void 	*pvalloc(size_t __size);

//FIXME - togliere: solo debug
t_alloc	*malloc_global_data();

#endif