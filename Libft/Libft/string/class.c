/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:55:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/26 18:39:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static void	_str_garbage_collector(t_str *p);

t_str	_str_constructor(t_str *str, const char *buff)
{
	printf("%s\tconstructor\n", buff);
	*str = (t_str){0};
	str->_str_identifier = _STR_IDENTIFIER;
	str->capacity = -1;
	str->set = str_set_start_index;
	if (_str_get_methods(str) != EXIT_SUCCESS)
		return (*str);
	if (sdup(str, buff)->err != 0)
		return (*str);
	str->npos = INT32_MAX;
	_str_set(str);
	return (*str);
}

bool	str_new(t_str **str, const char *buff)
{
	*str = CALLOC(1, sizeof(t_str));
	if (!*str)
		return (EXIT_FAILURE);
	_str_constructor(*str, buff);
	_str_garbage_collector(*str);
	return (EXIT_SUCCESS);
}

static void	_str_garbage_collector(t_str *p)
{
	static t_list	*garbage_list;

	if (!p)
		return (lst_clear(&garbage_list, _str_destructor));
	else if (p == (void *)1 && garbage_list)
	{
		garbage_list = garbage_list->next;
		return ;
	}
	p->_garbage_coll_node = lst_new(p);
	lst_back(&garbage_list, p->_garbage_coll_node);
}

void	_str_destructor(void *str)
{
	printf("%s\tdestructor\n", ((t_str *)str)->buff);
	_str_get_methods(NULL);
	FREE(((t_str *)str)->buff);
	if (((t_str *)str)->_garbage_coll_node)
	{
		_str_garbage_collector((t_str *)1);
		FREE(str);
	}
}

void	str_terminate(void)
{
	_str_garbage_collector(NULL);
}
