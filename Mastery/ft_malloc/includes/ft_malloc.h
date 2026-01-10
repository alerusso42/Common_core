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
# include "../all.h"
# define MALLOC_WARNINGS true

typedef struct s_alloc	t_alloc;

void 	*malloc(uint32_t size);
void 	free(void *ptr);
void 	*realloc(void *ptr, uint32_t size);

//FIXME - togliere: solo debug
t_alloc	*_global_data(bool reset);

#endif