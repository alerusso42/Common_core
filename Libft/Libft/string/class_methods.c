/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:51:42 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/02 12:10:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static err		_str_store_methods(t_str *s, bool reset);
static void		_str_register_function(t_str_methods *m);

//ANCHOR - _str_get_methods
/*
//	!!!This function is private! It shouldn't be used!

//	Sets internal function pointers.

	@input:		[t_str *this]----->	pointer to string object
	@return:	string error code
	@variables:	none
*/
err	_str_get_methods(t_str *s, bool reset)
{
	if (s == NULL)
		return (_str_store_methods(NULL, reset));
	s->err = _str_store_methods(s, reset);
	return (s->err);
}

//ANCHOR - _str_store_methods
/*
//	!!!This function is private! It shouldn't be used!

//	Sets or frees the internal methods structure.

	@input:		[t_str *s]------>	pointer to string object
	@return:	[string error code]
	@variables:	[static int32_t str_allocated]->number of string objects
				[static t_str_methods *methods]->pointer to methods structure
*/
static err		_str_store_methods(t_str *s, bool reset)
{
	static int32_t			str_allocated;
	static t_str_methods	*methods;

	if (s == NULL)
	{
		if (str_allocated != 0)
			str_allocated -= 1;
		if (str_allocated == 0 && reset)
		{
			STR_LOG("Since no more string exists, methods are freed.\n");
			FREE(methods);
			methods = NULL;
		}
		return (EXIT_SUCCESS);
	}
	if (!methods)
	{
		STR_LOG("Allocating %zu bytes for methods\n", sizeof(t_str_methods));
		methods = CALLOC(1, sizeof(t_str_methods));
		if (!methods)
			return (E_ALLOC);
		else
			_str_register_function(methods);
	}
	++str_allocated;
	s->m = methods;
	return (EXIT_SUCCESS);
}

//ANCHOR - _str_register_function
/*
//	!!!This function is private! It shouldn't be used!

//	Registers all string methods into the methods structure.

	@input:		[t_str_methods *m]-->pointer to methods structure
	@return:	none
	@variables:	none
*/
static void	_str_register_function(t_str_methods *m)
{
	m->str_addl = str_addl;
	m->str_addr = str_addr;
	m->str_app = str_app;
	m->str_cmp = str_cmp;
	m->str_cpy = str_cpy;
	m->str_cut = str_cut;
	m->str_diff = str_diff;
	m->str_excpy = str_excpy;
	m->str_find = str_find;
	m->str_first = str_first;
	m->str_incpy = str_incpy;
	m->str_itoa = str_itoa;
	m->str_join = str_join;
	m->str_last = str_last;
	m->str_lower = str_lower;
	m->str_ncmp = str_ncmp;
	m->str_ncpy = str_ncpy;
	m->str_push = str_push;
	m->str_rdiff = str_rdiff;
	m->str_reverse = str_reverse;
	m->str_rfind = str_rfind;
	m->str_satoi = str_satoi;
	m->str_sdup = str_sdup;
	m->str_sort = str_sort;
	m->str_sfree = str_delete;
	m->str_srealloc = str_srealloc;
	m->str_trim = str_trim;
	m->str_upper = str_upper;
}
