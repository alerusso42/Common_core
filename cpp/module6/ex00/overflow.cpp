/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 11:30:12 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 12:12:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	overflow_check(string s)
{
	long long int	n;
	int				i;
	int				max_chars;

	i = s.find(".");
	if (i == -1)
		i = s.length();
	max_chars = 10 + (s[0] == '+' || s[0] == '-');
	if (i > max_chars)
		return (true); 
	n = std::atoll(s.c_str());
	if (n > INT_MAX || n < INT_MIN)
		return (true);
	return (false);
}

bool	float_out_of_range(double n)
{
	if (n > FLT_MAX || n < -FLT_MAX)
		return (true);
	if (n < 0)
		n *= -1;
	if (n < FLT_MIN)
		return (true);
	return (false);
}
