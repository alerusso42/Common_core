/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:59:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/03 19:53:19 by alerusso         ###   ########.fr       */
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
	this->_a = this->_b;
	this->_b = this->_c;
	this->_c = (this->_a * 2 + this->_b);
	return (this->_c - 1);
}

int32_t	Jacobsthal::prev(void) const
{
	return (this->_b - 1);
}

int32_t	Jacobsthal::curr(void) const
{
	return (this->_c - 1);
}
