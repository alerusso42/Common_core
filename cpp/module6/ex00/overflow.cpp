/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 11:30:12 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 13:04:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	overflow_check(string s)
{
	long long int	n;
	int				i;
	int				leading_zero;
	int				max_chars;

	leading_zero = 0;
	for (int j = (s[0] == '+' || s[0] == '-'); s[j] == '0'; j++)
		leading_zero += 1;
	i = s.find(".");
	if (i == -1)
		i = s.length();
	max_chars = 10 + (s[0] == '+' || s[0] == '-') + leading_zero;
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
