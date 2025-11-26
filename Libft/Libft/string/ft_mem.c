/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:43:14 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/26 18:35:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

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
