/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:46:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:09:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//SECTION - public

t_str	*str_set_start_index(t_str *str, int32_t i)
{
	str->i = i;
	return (str);
}

//SECTION - private

//ANCHOR - _str_identifier
/*

//	!!!This function is private! It shouldn't be used!

//	Identifies if the given pointer is a string object.

	@input:		[const void *p]------>	pointer to be checked
	@return:	[bool]--------------->	true or false
	@variables:	[const uint8_t *s]----->	byte-wise pointer to p
				[uint64_t id]--------->		expected identifier
				[int8_t bytes]-------->		number of bytes to check
//REVIEW 
//	It compares the first 8 bytes of the given pointer
	with the expected string identifier byte by byte.
	
	If it is a t_str *, it'll be reinterpreted as a char *;
	the first 8 bytes of the string object are the identifier.

//NOTE - WARNING!
	With this method, a char * which its first 8 bytes match the identifier,
	will be incorrectly identified as a t_str *.
	Be sure not to need char * with that pattern.
*/
bool	_str_identifier(const void *p)
{
	const uint8_t	*s;
	uint64_t		id;
	int8_t			bytes;

	if (!p)
		return (false);
	s = (const uint8_t *)p;
	id = _STR_IDENTIFIER;
	bytes = sizeof(uint64_t);
	while (bytes)
	{
		if (*s != (id & 255))
			return (false);
		bytes--;
		++s;
		id >>= 8;
	}
	return (true);
}

//ANCHOR - _str_reset
/*

//	!!!This function is private! It shouldn't be used!

//	Resets the string object's buffer to the given size.

	@input:		[t_str *this]----->	pointer to string object
				[int i]----------->	new buffer size
	@return:	[t_str *]--------->	pointer to string object
	@variables:	none
*/
t_str	*_str_reset(t_str *this, int i)
{
	this->capacity = -1;
	FREE(this->buff);
	this->buff = CALLOC(i + 1, sizeof(char));
	if (!this->buff)
		return (_str_set_error(this, E_ALLOC, "dup"));
	this->capacity = i;
	this->len = i;
	_str_set(this);
	return (this);
}


void	_str_set(t_str *this)
{
	this->begin = (uintptr_t)(void *)this->buff;
	this->half = (uintptr_t)(void *)this->buff + (this->len >> 1);
	this->end = (uintptr_t)(void *)this->buff + this->len;
	this->err = 0;
	this->i = 0;
}
