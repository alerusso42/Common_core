/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:51:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/02 15:44:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pair.hpp"

//SECTION - canon form
Pair::Pair(int32_t size)
{
	if (size <= 1)
		size = 2;
	this->_buffer = NULL;
	this->_capacity = size;
	this->_error = 0;
	this->_size = 0;
	this->_insertions = 0;
	this->_alloc();
}
	
Pair::Pair(Pair &other)
{
	*this = other;
}

Pair::~Pair()
{
	delete[] this->_buffer;
}

Pair	Pair::operator=(Pair &other)
{
	if (this == &other)
		return (*this);
	if (this->_buffer)
		delete[] this->_buffer;
	this->_buffer = NULL;
	this->_capacity = other._capacity;
	this->_size = other._size;
	this->_error = other._error;
	this->_insertions = other._insertions;
	if (this->_error == this->E_ALLOC)
		return (*this);
	this->_copy(this->_buffer, other._buffer);
	return (*this);
}

//SECTION - public
	
void	Pair::add(int32_t p1, int32_t p2)
{
	if (this->_size >= this->_capacity)
		this->_realloc();
	if (this->_error == E_ALLOC)
		return ;
	if (p1 >= this->_capacity)
		return ((void)this->error(this->E_OUT_RANGE));
	this->_buffer[p1] = p2;
	this->_size += 1;
}

int32_t	Pair::find(int32_t pos)
{
	if (this->_error == E_ALLOC)
		return (-1);
	if (pos + this->_insertions >= this->_capacity)
		return ((void)this->error(this->E_OUT_RANGE), INT_MAX);
	if (this->_buffer[pos + this->_insertions] == -1)
		return ((void)this->error(this->E_EMPTY), INT_MAX);
	return (this->_buffer[pos + this->_insertions++]);
}

void	Pair::rm(void)
{
	this->_insertions += 1;
}

int32_t	Pair::error() const
{
	if (this->_error == E_OK)
		return (0);
	return (INT_MAX);
	std::cerr << "\033[31m";
	switch (this->_error)
	{
		case (E_ALLOC) :
			std::cerr << "Allocation error";
			break ;
		case (E_EMPTY) :
			std::cerr << "Key has not been associated";
			break ;
		case (E_OUT_RANGE) :
			std::cerr << "Requested key is out of range. Max size is " << this->_size;
	}
	std::cerr << std::endl << "\033[0m";
	return (this->_error);
}

int32_t	Pair::error(int32_t val)
{
	this->_error = val;
	return (this->error());
}

//SECTION - private
	
void	Pair::_realloc()
{
	int32_t	*temp;

	this->_capacity *= 2;
	temp = new (std::nothrow) int32_t[this->_capacity];
	if (!temp)
	{
		this->_error = this->E_ALLOC;
		return ;
	}
	for (int32_t i = this->_capacity / 2; i < this->_capacity; i++)
		temp[i] = -1;
	this->_copy(temp, this->_buffer);
	delete[] this->_buffer;
	this->_buffer = temp;
}

void	Pair::_alloc()
{
	this->_buffer = new (std::nothrow) int32_t[this->_capacity];
	if (!this->_buffer)
		this->_error = this->E_ALLOC;
	for (int32_t i = 0; i < this->_capacity; i++)
	{
		this->_buffer[i] = -1;
	}
}

void	Pair::_copy(int32_t *new_arr, int32_t *old_arr)
{
	if (this->error())
		return ;
	for (int32_t i = 0; i < this->_size; i++)
		new_arr[i] = old_arr[i];
}
