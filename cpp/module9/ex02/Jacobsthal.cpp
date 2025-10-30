/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:59:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/30 17:09:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Jacobsthal.hpp"

Jacobsthal::Jacobsthal(void)
{
	this->_a = NUMBER_A;
	this->_b = NUMBER_B;
	this->_c = NUMBER_C;
}

Jacobsthal::~Jacobsthal(void)
{}

Jacobsthal::Jacobsthal(const Jacobsthal &other)
{
	this->_a = other._a;
	this->_b = other._b;
	this->_c = other._c;
}

Jacobsthal	Jacobsthal::operator=(const Jacobsthal &other)
{
	if (this == &other)
		return (*this);
	this->_a = other._a;
	this->_b = other._b;
	this->_c = other._c;
	return (*this);
}

int32_t	Jacobsthal::next(void)
{
	this->_c = (this->_a * 2 + this->_b);
	this->_a = this->_b;
	this->_b = this->_c;
	return (this->_c);
}

int32_t	Jacobsthal::prev(void) const
{
	return (this->_b);
}
