/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:55:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 19:04:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static t_str	*string_mother(t_str *curr);
size_t			ft_strlen(const char *s);

t_str	str_constructor(t_str *str, char *buff)
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

void	str_destructor(t_str *str)
{
	printf("%s\tdestructor\n", str->buff);
	_str_get_methods(NULL);
	FREE(str->buff);
}

void	_str_set(t_str *this)
{
	this->begin = (uintptr_t)(void *)this->buff;
	this->half = (uintptr_t)(void *)this->buff + (this->len >> 1);
	this->end = (uintptr_t)(void *)this->buff + this->len;
	this->len = get_len(this);
	this->err = 0;
	this->i = 0;
}

t_str	*_str_reset(t_str *this, int i)
{
	this->capacity = i;
	this->buff = CALLOC(i + 1, sizeof(char));
	if (!this->buff)
		return (_str_set_error(this, E_ALLOC, "dup"), 1);
	_str_set(this);
	return (this);
}

int	main()
{
	STR(s, "ROCKY1");
	STR(s2, "ROCKY2");
	STR(s3, "ROCKY3");
	s3.m->dup_str(&s3, &s2);
	return (0);
}
