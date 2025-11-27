/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:27:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:45:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - str_trim
/*
	Trims n characters from the start index of the string object.

	@input:		[t_str *this]----->	pointer to string object
				[int32_t n]------->	number of characters to trim
	@return:	[t_str *]--------->	pointer to this
	@variables:	none
	@usage:	*-------------------------------*	
			|	str_trim(str, n);			|
			|	//OR						|
			|	trim(str, n);				|
			|	//OR						|
			|	str->m->trim(&str, n);		|
			*-------------------------------*
*/
t_str	*str_trim(t_str *this, int32_t n)
{
	n += this->i;
	str_cut(this, this->i, n);
	return (this);
}
