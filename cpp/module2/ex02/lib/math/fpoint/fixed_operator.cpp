/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_operator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:36:49 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/10 11:11:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream&	operator<<(std::ostream& fd, const Fixed& fp)
{
	fd << fp.toFloat();
	return (fd);
}

Fixed&	Fixed::operator=(const Fixed& val)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = val.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed& val)
{
	return (this->fixed_point < val.fixed_point);
}

bool	Fixed::operator<=(const Fixed& val)
{
	return (this->fixed_point <= val.fixed_point);
}

bool	Fixed::operator>(const Fixed& val)
{
	return (this->fixed_point > val.fixed_point);
}

bool	Fixed::operator>=(const Fixed& val)
{
	return (this->fixed_point >= val.fixed_point);
}

bool	Fixed::operator==(const Fixed& val)
{
	return (this->fixed_point == val.fixed_point);
}

bool	Fixed::operator!=(const Fixed& val)
{
	return (this->fixed_point != val.fixed_point);
}

//	for some reason, ++a and a++ are reversed
Fixed	Fixed::operator++(int something)
{
	Fixed	val;

	(void)something;
	val = *this;
	this->fixed_point++;
	return (val);
}

Fixed	Fixed::operator--(int something)
{
	Fixed	val;

	(void)something;
	val = *this;
	this->fixed_point--;
	return (val);
}

Fixed	Fixed::operator++(void)
{
	++this->fixed_point;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	--this->fixed_point;
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& val)
{
	Fixed	res;

	res.fixed_point = this->fixed_point + val.getRawBits();
	return (res);
}

Fixed	Fixed::operator-(const Fixed& val)
{
	Fixed	res;

	res.fixed_point = this->fixed_point - val.getRawBits();
	return (res);
}

/*
	1)	we do a normal multiplication between the fixed value.
		they are just int values;
	2)	however, both number are fixed_point, so they are both multipled
		by (1 << frac_bits). So, we have one (1 << frac_bits) in exceed;
	3)	to solve this, we divide by the result by (1 << frac_bits).

	es:	5.05 * 2 = 10.10;	frac_bits = 8 (1 << 8 = 256)
	5.05 float = 5.05 * 256 fixed;		2 float = 2 * 256 fixed

	(5.05 * 256) * (2 * 256) = (10.10) * (256 * 256)	//	too much 256
	(10.10) * (256 * 256) / 256 = 10.10 * 256 fixed 
*/
Fixed	Fixed::operator*(const Fixed& val)
{
	Fixed	res;

	res.fixed_point = (this->fixed_point * val.getRawBits());
	res.fixed_point /= (float)(1 << this->frac_bits);
	return (res);
}

/*
	1)	same for multiplication, but the problem is reversed:
		we lose one constant (1 << frac_bits);
	2)	to solve this, the first number is multipled by (1 << frac_bits);
	3)	to round the number, we cast it to float.

	es:	5.05 / 2 = 2.025;	frac_bits = 8 (1 << 8 = 256)
	5.05 float = 5.05 * 256 fixed;		2 float = 2 * 256 fixed

	(5.05 * 256) / (2 * 256) = (2.025) * (1)	//	no longer fixed
	(2.025) * (256) = 518.4	-> rounded: 518
*/
Fixed	Fixed::operator/(const Fixed& val)
{
	Fixed	res;

	if (val.getRawBits() == 0)
	{
		std::cerr << "\033[31m";
		std::cerr << "Fixed::operator /, Warning:\n";
		std::cerr << this->fixed_point << " divided by " << val.getRawBits();
		std::cerr << std::endl;
		std::cerr << "\033[0m";
	}
	res = *this;
	res = res.fixed_point / (float)val.getRawBits();
	return (res);
}
