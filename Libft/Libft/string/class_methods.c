/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:51:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 19:39:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static err		_str_store_methods(t_str *s);
static void		_str_register_function(t_str_methods *m);

err	_str_get_methods(t_str *s)
{
	if (s == NULL)
		return (_str_store_methods(NULL));
	s->err = _str_store_methods(s);
	return (s->err);
}

static err		_str_store_methods(t_str *s)
{
	static int32_t			str_allocated;
	static t_str_methods	*methods;

	if (s == NULL)
	{
		if (str_allocated != 0)
			str_allocated -= 1;
		if (str_allocated == 0)
		{
			printf("Since no more string exists, methods are freed.\n");
			FREE(methods);
			methods = NULL;
		}
		return (EXIT_SUCCESS);
	}
	if (!methods)
	{
		printf("Allocating %zu bytes for methods\n", sizeof(t_str_methods));
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

static void	_str_register_function(t_str_methods *m)
{
	m->atoi = str_atoi;
	m->cat_char = str_cat_char;
	m->cat_str = str_cat_str;
	m->cmp_char = str_cmp_char;
	m->cmp_str = str_cmp_str;
	m->cut_char = str_cut_char;
	m->str_cut = str_cut;
	m->dup_char = str_dup_char;
	m->dup_str = str_dup_str;
	m->find_chr = str_find_str;
	m->get_i = str_get_start_index;
	m->get_len = str_get_len;
	m->itoa = str_itoa;
	m->join_char = str_join_char;
	m->join_str = str_join_str;
	m->lower = str_lower;
	m->ncmp_char = str_ncmp_char;
	m->ncmp_str = str_ncmp_str;
	m->reverse = str_reverse;
	m->rfind_chr = str_rfind_chr;
	m->rfind_char = str_rfind_char;
	m->rfind_str = str_rfind_str;
	m->set_i = str_set_start_index;
	m->sort = str_sort;
	m->trim_char = str_trim_char;
	m->trim_str = str_trim_str;
	m->upper = str_upper;
}
