/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 22:09:56 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/11 22:10:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdbool.h>
# include <stddef.h>

void 	*malloc(size_t size);
void 	free(void *ptr);
void 	*realloc(void *ptr, size_t size);

void 	*malloc_file(uint32_t size, const char *file);
void 	*malloc_virtualfile(uint32_t size, const char *file);
void 	*malloc_tempfile(uint32_t size);
void	*malloc_anonymous(uint32_t size);
void 	print_extreme(void *p, t_alloc *dt, bool print);

# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <sys/mman.h>
# include <sys/unistd.h>
# include <sys/fcntl.h>
# include "../all.h"

