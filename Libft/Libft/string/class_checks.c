/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:28:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:12:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - _str_set_error
/*

//	!!!This function is private! It shouldn't be used!

//	Sets error state of the string object.

	@input:		[t_str *str]------>	pointer to string object
				[int err]--------->	error code
				[char *func_name]->function name where error occurred
	@return:	[t_str *]--------->	pointer to string object
	@variables:	none
*/
t_str	*_str_set_error(t_str *str, int err, char *func_name)
{
	if (str->buff == NULL)
		return (str);
	if (!str->err)
		str->err = err;
	switch (err)
	{
		case (E_ALLOC) :
			str->capacity = -1;
			write(2, "String:\tFATAL:\tAllocation error", 31);
			break ;
		case (E_PARAM) :
			write(2, "String:\tbad parameter in function\t", 34);
			write(2, func_name, ft_strlen(func_name));
			break ;
		case (E_ATOI_FAIL) :
			write(2, "String:\tAtoi has failed for this param->\t", 41);
			write(2, func_name, ft_strlen(func_name));
			break ;
		case (E_NPOS) :
			str->err = 0;
			break ;
	}
	write(2, "\n", 1);
	return (str);
}

//ANCHOR - str_check_char
/*

//	!!!This function is private! It shouldn't be used!

//	Checks validity of operations involving this object and a char pointer.

	@input:		[t_str *this]----->	pointer to string object
				[const char *other]->pointer to char
	@return:	[bool]----------->	success or failure
	@variables:	none
*/
bool	str_check_char(t_str *this, const char *other)
{
	if (this->err == E_ALLOC || !this->buff)
		return (1);
	else if (!other)
		this->err = E_PARAM;
	else if (this->i == this->npos)
		this->err = E_NPOS;
	return (this->err > 0);
}

//ANCHOR - str_check_str
/*

//	!!!This function is private! It shouldn't be used!

//	Checks validity of operations involving this object and a t_str pointer.

	@input:		[t_str *this]----->	pointer to string object
				[const char *other]->pointer to char
	@return:	[bool]----------->	success or failure
	@variables:	none
*/
bool	str_check_str(t_str *this, const t_str *other)
{
	if (this->err == E_ALLOC || !this->buff)
		return (1);
	else if (other->err == E_ALLOC)
		this->err = E_PARAM;
	else if (this->i == this->npos)
		this->err = E_NPOS;
	return (this->err > 0);
}

//ANCHOR - str_check_str
/*

//	!!!This function is private! It shouldn't be used!

//	Checks validity of operations involving this object.

	@input:		[t_str *this]----->	pointer to string object
	@return:	[bool]----------->	success or failure
	@variables:	none
*/
bool	str_check_this(t_str *this, const void *empty)
{
	(void)empty;
	if (this->err == E_ALLOC || !this->buff)
		return (1);
	else if (this->i == this->npos)
		this->err = E_NPOS;
	return (this->err > 0);
}
