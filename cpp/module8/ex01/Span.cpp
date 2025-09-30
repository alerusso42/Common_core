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
	this->_data.clear();
	this->_capacity = 0;
}

Span::Span(u_int32_t capacity): _data(capacity)
{
	this->_size = 0;
	if (capacity > this->SPAN_MAXSIZE)
		throw (Error(EX_BAD_SIZE));
	this->_capacity = capacity;
	if (capacity == 0)
	{
		this->_data.clear();
		return ;
	}
	for (u_int32_t i = 0; i < _capacity + 1; i++)
	{
		this->_data[i] = 0;
	}
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
	this->_data.push_back(std::rand());
	this->_size++;
}

void	Span::addNumber(int number)
{
	if (this->_size == this->_capacity)
		throw (Error(EX_OUT_BOUND));
	this->_data.push_back(number);
	this->_size++;
}

int		Span::shortestSpan(void)
{
	int							shortest;
	std::vector<int>::iterator	it;

	shortest = INT_MAX;
	if (_capacity < 2)
		throw (Error(EX_SINGLE_ELEM));
	std::sort(this->_data.begin(), this->_data.end());
	it = this->_data.begin();
	while ((it + 1) != this->_data.end())
	{
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
		++it;
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
	while (it != this->_data.end())
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
	if (this->_size == this->_capacity)
		throw (Error(EX_OUT_BOUND));
	this->_size = this->_capacity;
	std::generate(this->_data.begin(), this->_data.end(), std::rand);
}

