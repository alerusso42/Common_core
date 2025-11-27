/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_diff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:53:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:36:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

//ANCHOR - str_rdiff
/*
	Reversely advances the index of the string object while the current 
	character does not belong to the given string or char pointer.

	@input:		[t_str *this]----->	pointer to string object
				[const void *other]->pointer to another string object
									or a char pointer
	@return:	[t_str *]--------->	pointer to this
	@variables:	none
	@usage:	*-------------------------------*	
			|	str_rdiff(str, other);		|
			|	//OR						|
			|	rdiff(str, other);			|
			|	//OR						|
			|	str->m->rdiff(&str, other);	|
			*-------------------------------*
*/
t_str	*str_rdiff(t_str *this, const void *other)
{
	if (_str_identifier(other) == true)
		return (str_rdiff_str(this, other));
	else
		return (str_rdiff_char(this, other));
}

t_str	*str_rdiff_chr(t_str *this, char other)
{
	int32_t	i;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "rdiff"));
	i = (int32_t)(this->end - this->begin) - 1;
	while (i > this->i && this->buff[i] == other)
		i--;
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}

t_str	*str_rdiff_char(t_str *this, const char *other)
{
	int32_t	i;
	int32_t	j;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "rdiff"));
	i = (int32_t)(this->end - this->begin) - 1;
	j = 0;
	while (i > this->i && this->buff[i] == other[j])
	{
		j = -1;
		while (other[++j])
			if (this->buff[i] != other[j])
				break ;
		i--;
	}
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}

t_str	*str_rdiff_str(t_str *this, const t_str *other)
{
	int32_t	i;
	int32_t	j;

	if (str_check(this, NULL))
		return (_str_set_error(this, E_PARAM, "rdiff"));
	i = (int32_t)(this->end - this->begin) - 1;
	while (i > this->i && this->buff[i] == other->buff[j])
	{
		j = 0;
		while (other->buff[j])
		{
			if (this->buff[i] != other->buff[j])
				break ;
			++j;
		}
		i--;
	}
	if (i <= 0)
		this->i = this->npos;
	else
		this->i = i;
	return (this);
}
