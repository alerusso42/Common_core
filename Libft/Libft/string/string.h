/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:24:29 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 22:55:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include <stdbool.h>
# include <unistd.h>
# include <malloc.h>
# include <limits.h>
# include <stdint.h>
# include "../libft.h"
# include "string_macros.h"
# include "string_methods.h"

typedef struct s_str			t_str;
typedef struct s_str_methods	t_str_methods;
typedef enum e_str_error		t_str_error;
typedef int32_t					err;

enum	e_str_error
{
	E_EXIT_SUCCESS = EXIT_SUCCESS,
	E_ALLOC,
	E_PARAM,
	E_NPOS,
	E_ATOI_FAIL,
};

struct s_str
{
	uint64_t		_str_identifier;
	t_str_methods	*m;
	char			*buff;
	uintptr_t		begin;
	uintptr_t		half;
	uintptr_t		end;
	int32_t			npos;
	int32_t			len;
	int32_t			capacity;
	int32_t			i;
	t_str_error		err;
	bool			heap;
};

struct s_str_methods
{
	STR_METHODS
};

#endif