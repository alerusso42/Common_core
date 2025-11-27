/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:47:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:28:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - str_app
/*
//	Appends the content of another string object or a char pointer
	to the current string object.

	@INDEX:		IGNORES SET INDEX DURING OPERATION!
	@input:		[t_str *this]----->	pointer to string object
				[const void *other]->pointer to another string object
									or a char pointer
	@return:	[t_str *]--------->	pointer to this
	@variables:	none
	@usage:	*-------------------------------*	
			|	str_app(str, other);		|
			|	//OR						|
			|	app(str, other);			|
			|	//OR						|
			|	str->m->app(&str, other);	|
			*-------------------------------*
*/
t_str	*str_app(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_app_str(this, other));
	else
		return (str_app_char(this, other));
}

//	Uses str_join under the hood.
t_str *str_app_str(t_str *s, const t_str *s2)
{
	int32_t	temp;

	if (!s || s->i == s->npos)
		return (s);
	temp = s->i;
	s->i = 0;
	str_join_str(s, s2, 0);
	if (s->i != s->npos)
		s->i = temp;
	return (s);
}

//	Uses str_join under the hood.
t_str *str_app_char(t_str *s, const char *s2)
{
	int32_t	temp;

	if (!s || s->i == s->npos)
		return (s);
	temp = s->i;
	s->i = 0;
	str_join_char(s, s2, 0);
	if (s->i != s->npos)
		s->i = temp;
	return (s);
}
