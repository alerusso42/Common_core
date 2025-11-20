/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:51:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/20 21:48:54 by alerusso         ###   ########.fr       */
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
	m->str_satoi = str_satoi;
//	m->str_cat_char = str_cat_char;
//	m->str_cat_str = str_cat_str;
	m->str_cmp_char = str_cmp_char;
	m->str_cmp_str = str_cmp_str;
	m->str_cut = str_cut;
	m->str_diff_chr = str_diff_chr;
	m->str_diff_char = str_diff_char;
	m->str_diff_str = str_diff_str;
	m->str_sdup_char = str_sdup_char;
	m->str_sdup_str = str_sdup_str;
	m->str_find_chr = str_find_chr;
	m->str_find_char = str_find_char;
	m->str_find_str = str_find_str;
	m->get_i = str_get_start_index;
	m->get_len = str_get_len;
	m->str_itoa = str_itoa;
	m->str_join_char = str_join_char;
	m->str_join_str = str_join_str;
	m->str_lower = str_lower;
	m->str_ncmp_char = str_ncmp_char;
	m->str_ncmp_str = str_ncmp_str;
	m->str_reverse = str_reverse;
	m->str_rdiff_chr = str_rdiff_chr;
	m->str_rdiff_char = str_rdiff_char;
	m->str_rdiff_str = str_rdiff_str;
	m->str_rfind_chr = str_rfind_chr;
	m->str_rfind_char = str_rfind_char;
	m->str_rfind_str = str_rfind_str;
	m->set_i = str_set_start_index;
	m->str_sort = str_sort;
	m->str_upper = str_upper;
}
