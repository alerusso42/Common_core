/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:43:14 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:42:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - str_srealloc
/*
	Reallocates the internal buffer of the string object to a new size.

	@input:		[t_str *this]----->	pointer to string object
				[int32_t n]------->	new capacity size
	@return:	[t_str *]--------->	pointer to this
	@variables:	[char *temp]------>	temporary pointer to old buffer
	@usage:	*-------------------------------*	
			|	str_srealloc(str, n);		|
			|	//OR						|
			|	srealloc(str, n);			|
			|	//OR						|
			|	str->m->srealloc(&str, n);	|
			*-------------------------------*
*/
t_str	*str_srealloc(t_str *this, int32_t n)
{
	char	*temp;

	if (n <= 0)
		n = this->capacity + _STR_REALLOC_SIZE;
	temp = this->buff;
	this->buff = CALLOC(n + 1, sizeof(char));
	if (!this->buff)
		return (_str_set_error(this, E_ALLOC, "_realloc"));
	if (!temp)
		return (this);
	ncpy(this, temp, 0, n);
	FREE(temp);
	this->capacity = n;
	_str_set(this);
	return (this);
}

//ANCHOR - str_delete
/*
	Deletes the string object and frees its memory.

	@input:		[t_str *this]----->	pointer to string object
	@return:	[t_str *]--------->	NULL
	@variables:	none
	@usage:	*-------------------------------*	
			|	str = str_delete(str);		|
			|	//OR						|
			|	str = delete(str);			|
			|	//OR						|
			|	str = str->m->delete(&str);	|
			*-------------------------------*

//NOTE - WARNING
	This function frees the string object and returns NULL.
	If you access the string object after calling this function,
	it will lead to undefined behavior.
*/
t_str	*str_delete(t_str *this)
{
	if (!this)
		return (NULL);
	if (this->_garbage_coll_node)
		return (lst_delone(this->_garbage_coll_node, _str_destructor), NULL);
	FREE(this->buff);
	this->buff = NULL;
	this->capacity = -1;
	
	return (NULL);
}
