/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:51:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/02 16:51:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Fixed
{
private:
	int					fixed_point;
	static const int	frac_bits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();

	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	Fixed&				operator=(const Fixed& val);
	Fixed&				operator+=(const Fixed& val);
	Fixed&				operator-=(const Fixed& val);
	Fixed&				operator*=(const Fixed& val);
	Fixed&				operator/=(const Fixed& val);
	bool				operator<(const Fixed& val);
	bool				operator<=(const Fixed& val);
	bool				operator>(const Fixed& val);
	bool				operator>=(const Fixed& val);
	bool				operator==(const Fixed& val);
	bool				operator!=(const Fixed& val);
	Fixed				operator++(int);
	Fixed				operator--(int);
	Fixed				operator++(void);
	Fixed				operator--(void);
	Fixed				operator+(const Fixed& val);
	Fixed				operator-(const Fixed& val);
	Fixed				operator*(const Fixed& val);
	Fixed				operator/(const Fixed& val);
	std::ostream&		operator<<(std::ostream& fd);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
};

std::ostream&	operator<<(std::ostream& fd, const Fixed& fp);

#endif
