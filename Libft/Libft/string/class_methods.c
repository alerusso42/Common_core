/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:51:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/23 18:59:33 by codespace        ###   ########.fr       */
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
	m->satoi = str_satoi;
//	m->cat_char = str_cat_char;
//	m->cat_str = str_cat_str;
	m->cmp_char = str_cmp_char;
	m->cmp_str = str_cmp_str;
	m->cut = str_cut;
	m->diff_chr = str_diff_chr;
	m->diff_char = str_diff_char;
	m->diff_str = str_diff_str;
	m->sdup_char = str_sdup_char;
	m->sdup_str = str_sdup_str;
	m->find_chr = str_find_chr;
	m->find_char = str_find_char;
	m->find_str = str_find_str;
	m->get_i = str_get_start_index;
	m->get_len = str_get_len;
	m->itoa = str_itoa;
	m->join_char = str_join_char;
	m->join_str = str_join_str;
	m->lower = str_lower;
	m->ncmp_char = str_ncmp_char;
	m->ncmp_str = str_ncmp_str;
	m->reverse = str_reverse;
	m->rdiff_chr = str_rdiff_chr;
	m->rdiff_char = str_rdiff_char;
	m->rdiff_str = str_rdiff_str;
	m->rfind_chr = str_rfind_chr;
	m->rfind_char = str_rfind_char;
	m->rfind_str = str_rfind_str;
	m->set_i = str_set_start_index;
	m->sort = str_sort;
	m->upper = str_upper;
}
