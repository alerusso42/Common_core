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

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "lib/lib.hpp"

typedef class Fixed
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

	Fixed&			operator=(const Fixed& copy);
	std::ostream&	operator<<(std::ostream& fd);
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
}	Fixed;

#endif
