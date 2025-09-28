/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:26:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 18:26:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#define TPP	template	<typename T>Array<T>

template	<typename T>
Array<T>::Array()
{

}

template	<typename T>
Array<T>::Array(u_int32_t size)
{
	(void)size;
}

TPP::~Array()
{

}

TPP::Array(const Array &other)
{ 
	(void)other;
}

template	<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other) 
		return (*this);
	this->_index = other.get_index();
	this->_size = other.get_size();
	return (*this);
}

template	<typename T>
int	Array<T>::get_index(void) const
{
	return (this->_index);
}

template	<typename T>
int	Array<T>::get_size(void) const
{
	return (this->_size);
}