/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:03:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 20:24:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - str_excpy
/*
	Copies characters from another string object or a char pointer
	into the current string object, until a character from the given set .
	is found.

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
t_str	*str_excpy(t_str *this, const void *other, const void *set)
{
	const char	*charset;

	if (_str_identifier(set) == true)
		charset = ((const t_str *)set)->buff;
	else
		charset = (const char *)set;
	if (_str_identifier(other) == true)
		return (str_scpy_str(this, other, charset, EXCLUDE));
	else
		return (str_scpy_char(this, other, charset, EXCLUDE));
}
