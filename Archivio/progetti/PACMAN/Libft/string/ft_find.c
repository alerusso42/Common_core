/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:44:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:37:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int32_t	ft_strstr_int(const char *, const char *);

//ANCHOR - str_find
/*
	Finds the first occurrence of another string object or a char pointer
	in the current string object.

	@input:		[t_str *this]----->	pointer to string object
				[const void *other]->pointer to another string object
									or a char pointer
	@return:	[t_str *]--------->	pointer to this
	@variables:	none
	@usage:	*-------------------------------*	
			|	str_find(str, other);		|
			|	//OR						|
			|	find(str, other);			|
			|	//OR						|
			|	str->m->find(&str, other);	|
			*-------------------------------*
*/
t_str	*str_find(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_find_str(this, other));
	else
		return (str_find_char(this, other));
}

t_str	*str_find_chr(t_str *this, char other)
{
	char	chr[2];

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	*chr = other;
	chr[1] = 0;
	this->i = ft_strstr_int(this->buff, chr);
	return (this);
}

t_str	*str_find_char(t_str *this, const char *other)
{
	if (str_check(this, other))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = ft_strstr_int(this->buff, other);
	return (this);
}

t_str	*str_find_str(t_str *this, const t_str *other)
{
	if (str_check(this, other))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = ft_strstr_int(this->buff, other->buff);
	return (this);
}
