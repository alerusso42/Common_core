/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:24:29 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 18:35:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
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
	t_str_methods	*m;
	int8_t			*buff;
	uintptr_t		begin;
	uintptr_t		half;
	uintptr_t		end;
	int32_t			npos;
	int32_t			len;
	int32_t			capacity;
	int32_t			i;
	t_str_error		err;
};

struct s_str_methods
{
	STR_METHODS
};

enum	e_str
{
	INCLUDE,
	EXCLUDE,
};

#endif