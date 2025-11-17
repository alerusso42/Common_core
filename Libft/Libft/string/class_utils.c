/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:28:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/17 19:30:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int		str_get_start_index(t_str *str)
{
	return (str->i);
}

void	str_set_start_index(t_str *str, int i)
{
	str->i = i;
}

int		_str_set_error(t_str *str, int err, char *func_name)
{
	str->err = err;
	switch (err)
	{
		case (E_ALLOC) :
			write(2, "String:\tFATAL:\tAllocation error", 31);
			break ;
		case (E_PARAM) :
			write(2, "String:\tbad parameter in function\t", 34);
			write(2, func_name, ft_strlen(func_name));
			break ;
		case (E_ATOI_FAIL) :
			write(2, "String:\tAtoi has failed for this param->\t", 41);
			write(2, func_name, ft_strlen(func_name));
	}
	write(2, "\n", 1);
	return (err);
}

bool	str_check_char(t_str *this, char *other)
{
	if (this->err == E_ALLOC || !other)
		return (1);
	if (this->i == this->npos)
		return (1);
	return (EXIT_SUCCESS);
}

bool	str_check_str(t_str *this, t_str *other)
{
	if (this->err == E_ALLOC || other->err == E_ALLOC)
		return (1);
	if (this->i == this->npos || other->err == E_ALLOC)
		return (1);
	return (EXIT_SUCCESS);
}

bool	str_check_this(t_str *this, void *empty)
{
	(void)empty;
	if (this->err == E_ALLOC)
		return (1);
	if (this->i == this->npos)
		return (1);
	return (EXIT_SUCCESS);
}
