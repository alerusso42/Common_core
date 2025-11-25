/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:15:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/30 10:15:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _data(0)
{
	this->_size = 0;
	this->_capacity = 0;
	std::generate(this->_data.begin(), this->_data.end(), std::rand);
}

Span::Span(u_int32_t capacity): _data(capacity)
{
	this->_size = 0;
	if (capacity > this->SPAN_MAXSIZE)
		throw (Error(EX_BAD_SIZE));
	this->_capacity = capacity;
	std::generate(this->_data.begin(), this->_data.end(), std::rand);
}

Span::~Span()
{}

Span::Span(const Span &other): _data(other._capacity)
{
	if (this == &other)
		return ;
	this->_size = other._size;
	this->_capacity = other._capacity;
	for (u_int32_t i = 0; i < _capacity + 1; i++)
	{
		this->_data[i] = other._data[i];
	}
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	this->_size = other._size;
	this->_capacity = other._capacity;
	for (u_int32_t i = 0; i < _capacity + 1; i++)
	{
		this->_data[i] = other._data[i];
	}
	return (*this);
}

void	Span::addNumber(void)
{
	if (this->_size == this->_capacity)
		throw (Error(EX_OUT_BOUND));
	this->_data[_size] = std::rand();
	this->_size++;
}

void	Span::addNumber(int number)
{
	if (this->_size == this->_capacity)
		throw (Error(EX_OUT_BOUND));
	this->_data[_size] = number;
	this->_size++;
}

void	Span::print(void) const
{
	std::cout << "Span::print: size is\t" << this->_size << std::endl;
	for (u_int32_t i = 0; i != this->_size; i++)
		std::cout << "data[" << i << "]:\t" << this->_data[i] << std::endl;
}

int		Span::shortestSpan(void)
{
	int	shortest;

	shortest = INT_MAX;
	if (_capacity < 2)
		throw (Error(EX_SINGLE_ELEM));
	std::sort(this->_data.begin(), this->_data.end());
	for (std::vector<int>::iterator i = _data.begin(); i + 1 != _data.end(); ++i)
	{
		if (*(i + 1) - *i < shortest)
			shortest = *(i + 1) - *i;
	}
	return (shortest);
}

int		Span::longestSpan(void)
{
	int							shortest;
	int							longest;
	std::vector<int>::iterator	it;

	shortest = INT_MAX;
	longest = INT_MIN;
	if (_capacity < 2)
		throw (Error(EX_SINGLE_ELEM));
	std::sort(this->_data.begin(), this->_data.end());
	it = this->_data.begin();
	for (int len = this->_size; len != 0; len--)
	{
		if (*it < shortest)
			shortest = *it;
		if (*it > longest)
			longest = *it;
		++it;
	}
	return (longest - shortest);
}

void	Span::generate(void)
{
	if (this->_capacity == 0)
		throw (Error(EX_OUT_BOUND));
	this->_size = this->_capacity;
	std::generate(this->_data.begin(), this->_data.end(), std::rand);
}

