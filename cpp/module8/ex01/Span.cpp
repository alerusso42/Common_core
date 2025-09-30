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

Span::Span()
{
	this->_data.clear();
	this->_capacity = 0;
}

Span::Span(u_int32_t capacity)
{
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
{

}

Span::Span(const Span &other)
{ 
	(void)other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other) 
	{
		// add field
	}
	return (*this);
}

int		Span::shortestSpan(void)
{
	std::sort(this->_data.begin(), this->_data.end());
}

int		Span::longestSpan(void)
{}

void	Span::generate(void)
{}

