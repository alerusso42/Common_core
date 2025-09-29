/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:27:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/29 10:14:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "lib/lib.hpp"
# include "Array.hpp"

#define TPP	template	<typename T>Array<T>

//	empty constructor
template	<typename T>
Array<T>::Array(void)
{
	this->_data = NULL;
	this->_size = 0;
}

template	<typename T>
Array<T>::Array(u_int32_t size)
{
	if (size > this->ARRAY_MAXSIZE)
		throw (Error(EX_BAD_SIZE));
	this->_size = size;
	if (size == 0)
	{
		this->_data = NULL;
		return ;
	}
	this->_data = new T[size + 1];
	if (!this->_data)
		throw (Error(EX_ALLOC));
	this->_size = size;
	for (u_int32_t i = 0; i < size + 1; i++)
	{
		this->_data[i] = (T)0;
	}
}

TPP::~Array()
{
	delete [] this->_data;
}

TPP::Array(const Array &other)
{
	const T	*other_data;

	if (this == &other) 
		return ;
	this->_size = other.get_size();
	if (this->_size == 0)
	{
		this->_data = NULL;
		return ;
	}
	if (this->_size > this->ARRAY_MAXSIZE)
		throw (Error(EX_BAD_SIZE));
	this->_data = new T[this->_size + 1];
	if (!this->_data)
		throw (Error(EX_ALLOC));
	other_data = other.get_data();
	for (u_int32_t i = 0; i < this->_size + 1; i++)
	{
		this->_data[i] = other_data[i];
	}
}

template	<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	const T	*other_data;

	if (this == &other) 
		return (*this);
	this->_size = other.get_size();
	if (this->_size == 0)
	{
		this->_data = NULL;
		return (*this);
	}
	if (this->_size > this->ARRAY_MAXSIZE)
		throw (Error(EX_BAD_SIZE));
	this->_data = new T[this->_size + 1];
	if (!this->_data)
		throw (Error(EX_ALLOC));
	other_data = other.get_data();
	for (u_int32_t i = 0; i < this->_size + 1; i++)
	{
		this->_data[i] = other_data[i];
	}
	return (*this);
}

template	<typename T>
int	Array<T>::size(void) const
{
	return (this->_size);
}

template	<typename T>
const T	*Array<T>::get_data(void) const
{
	return (this->_data);
}

template	<typename T>
T	&Array<T>::operator[](int index)
{
	if (index < 0)
		throw (Error(EX_NEGATIVE_INDEX));
	else if (index > this->_size - 1)
		throw (Error(EX_OUT_BOUND));
	return (this->_data[index]);
}

#endif