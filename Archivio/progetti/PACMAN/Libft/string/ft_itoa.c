/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:46:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 16:28:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static char	*alloc_string(char *allocated_string, int num, int *index);

char	*ft_itoa(int num)
{
	int		temp_num;
	int		index;
	char	*str;

	index = 0;
	temp_num = num;
	while ((temp_num > 9) || (temp_num < -9))
	{
		index++;
		temp_num /= 10;
	}
	str = NULL;
	str = alloc_string(str, num, &index);
	if (!str)
		return (NULL);
	str[index + 1] = '\0';
	while (num != 0)
	{
		if (num < 0)
			str[index--] = (((num % 10) * -1) + 48);
		else
			str[index--] = ((num % 10) + 48);
		num /= 10;
	}
	return (str);
}

static char	*alloc_string(char *allocated_string, int num, int *index)
{
	if (num < 0)
		*index += 1;
	allocated_string = (char *)CALLOC((*index) + 2, sizeof(char));
	if (!allocated_string)
		return (NULL);
	if (num < 0)
	{
		allocated_string[0] = '-';
	}
	if (num == 0)
	{
		allocated_string[(*index)] = '0';
	}
	return (allocated_string);
}

//ANCHOR - str_itoa
/*
	Converts an integer to a string and stores it in the string object.

	@input:		[t_str *this]----->	pointer to string object
				[int32_t value]--->	integer value to convert
	@return:	[t_str *]--------->	pointer to this
	@variables:	none
	@usage:	*-------------------------------*	
			|	str_itoa(str, value);		|
			|	//OR						|
			|	itoa(str, value);			|
			|	//OR						|
			|	str->m->itoa(&str, value);	|
			*-------------------------------*
*/
t_str	*str_itoa(t_str *this, int32_t value)
{
	FREE(this->buff);
	this->buff = ft_itoa((int)value);
	if (!this->buff)
		this->err = E_ALLOC;
	return (this);
}
