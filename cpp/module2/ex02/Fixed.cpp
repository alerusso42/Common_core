/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:51:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/02 16:51:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point = copy.getRawBits();
}

Fixed::Fixed(const int n)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = n << this->frac_bits;
}

/*	n:										42.4199982
	n * (1 << this->frac_bits):				10859.5195
	(int)(n * (1 << this->frac_bits)):		10859
	(int)(n * (1 << this->frac_bits) + 0.5):10860
*/	
Fixed::Fixed(const float n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = n * (1 << this->frac_bits) + (n > 0 ? 0.5 : -0.5);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


std::ostream&	operator<<(std::ostream& fd, const Fixed& fp)
{
	fd << fp.toFloat();
	return (fd);
}

int		Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

int	Fixed::toInt(void) const
{
	return (this->fixed_point >> this->frac_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point / (1 << this->frac_bits));
}

Fixed&	Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = copy.getRawBits();
	return (*this);
}

char	Fixed::operator<(const Fixed& copy)
{
	return (copy.fixed_point < )
}

char	Fixed::operator<=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = copy.getRawBits();
	return (*this);
}

char	Fixed::operator>(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = copy.getRawBits();
	return (*this);
}

char	Fixed::operator>=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = copy.getRawBits();
	return (*this);
}

char	Fixed::operator==(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = copy.getRawBits();
	return (*this);
}

char	Fixed::operator!=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = copy.getRawBits();
	return (*this);
}
