/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:55:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/25 22:34:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//static t_str	*string_mother(t_str *curr);
size_t			ft_strlen(const char *s);

t_str	str_constructor(t_str *str, char *buff)
{
	printf("%s\tconstructor\n", buff);
	*str = (t_str){0};
	str->_str_identifier = _STR_IDENTIFIER;
	str->capacity = -1;
	str->heap = false;
	if (_str_get_methods(str) != EXIT_SUCCESS)
		return (*str);
	if (sdup(str, buff)->err != 0)
		return (*str);
	str->npos = INT32_MAX;
	_str_set(str);
	return (*str);
}

/*
t_str	str_ptr_constructor(t_str *str, char *buff)
{
	printf("%s\tconstructor\n", buff);
	*str = (t_str){0};
	if (_str_get_methods(str) != EXIT_SUCCESS)
		return (*str);
	if (dup(str, buff)->err != 0)
		return (*str);
	str->npos = UINT32_MAX;
	_str_set(str);
	return (*str);
}

static int		realloc_mother(t_str **str, int *size, int len)
{
	
}

static t_str	*string_mother(t_str *curr)
{
	static int		size;
	static int		len;
	static t_str	*mother;

	if (curr == (t_str *)1)
	{
		while (len)
			FREE(mother[--len].buff);
		size = 0;
		return (FREE(mother), NULL);
	}
	else if (!curr)
	{
		if ((!mother || size == len) \
		&& realloc_mother(&mother, &size, len) != 0)
			return (NULL);
		return (&mother[len++]);
	}
	if (curr && !mother)
		return (NULL);
	
}

void	str_ptr_destructor(t_str **str)
{
	printf("%s\tdestructor\n", (*str)->buff);
	_str_get_methods(NULL);
	FREE((*str)->buff);
	FREE(*str);
}*/

void	_str_destructor(t_str *str)
{
	printf("%s\tdestructor\n", str->buff);
	_str_get_methods(NULL);
	FREE(str->buff);
}
