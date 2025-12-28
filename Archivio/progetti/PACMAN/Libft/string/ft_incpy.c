/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_incpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:03:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 20:24:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - str_incpy
/*
	Copies characters from another string object or a char pointer
	into the current string object, while characters belong to the given set.

	@INDEX:	SET INDEX TO END OF COPIED CONTENT!
	@input:		[t_str *this]----->	pointer to string object
				[const void *other]->pointer to another string object
									or a char pointer
				[const void *set]-->	pointer to another string object
									or a char pointer representing the set
	@return:	[t_str *]--------->	pointer to this
	@variables:	none
	@usage:	*---------------------------------------*	
			|	str_incpy(str, other, set);		|
			|	//OR								|
			|	incpy(str, other, set);			|
			|	//OR								|
			|	str->m->incpy(&str, other, set);|
			*---------------------------------------*
*/
t_str	*str_incpy(t_str *this, const void *other, const void *set)
{
	const char	*charset;

	if (_str_identifier(set) == true)
		charset = ((const t_str *)set)->buff;
	else
		charset = (const char *)set;
	if (_str_identifier(other) == true)
		return (str_scpy_str(this, other, charset, INCLUDE));
	else
		return (str_scpy_char(this, other, charset, INCLUDE));
}

t_str	*str_scpy_char(t_str *this, const char *other, const char *set, int m)
{
	if (str_check(this, other) || !set || \
	(int32_t)ft_strlen(other) > this->capacity - this->i)
		return (_str_set_error(this, E_PARAM, "scpy"));
	this->i += sub_strcpy(this->buff + this->i, other, set, m);
	return (this);
}

t_str	*str_scpy_str(t_str *this, const t_str *other, const char *set, int m)
{
	if (str_check(this, other) || !set || \
	other->len > this->capacity - this->i)
		return (_str_set_error(this, E_PARAM, "scpy"));
	this->i += sub_strcpy(this->buff + this->i, other->buff, set, m);
	return (this);
}
