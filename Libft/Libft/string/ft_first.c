/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:44:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:38:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - str_first
/*
	Advances the index of the string object until one of the characters 
	from another string object or a char pointer is found.

	@input:		[t_str *this]----->	pointer to string object
				[const void *other]->pointer to another string object
									or a char pointer
	@return:	[t_str *]--------->	pointer to this
	@variables:	none
	@usage:	*-------------------------------*	
			|	str_first(str, other);		|
			|	//OR						|
			|	first(str, other);			|
			|	//OR						|
			|	str->m->first(&str, other);	|
			*-------------------------------*
*/
t_str	*str_first(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_first_str(this, other));
	else
		return (str_first_char(this, other));
}

t_str	*str_first_chr(t_str *this, char other)
{
	char	chr[2];

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	*chr = other;
	this->i = sub_strlen(this->buff + this->i, chr, EXCLUDE);
	return (this);
}

t_str	*str_first_char(t_str *this, const char *other)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = sub_strlen(this->buff + this->i, other, EXCLUDE);
	return (this);
}

t_str	*str_first_str(t_str *this, const t_str *other)
{
	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "find"));
	this->i = sub_strlen(this->buff + this->i, other->buff, EXCLUDE);
	return (this);
}
