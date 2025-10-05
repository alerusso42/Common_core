/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:08:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/05 15:18:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

//	revert the content of a string
std::string	 	 ft_reverse(std::string s)
{
	int		i;
	char	temp;

	i = 0;
	while (i < (int)s.size() / 2)
	{
		temp = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = temp;
		i++;
	}
	return (s);
}

//	integer to ascii
std::string	 	 ft_itoa(int n)
{
	std::string	 	 s;
	bool	minus;

	if (n == 0)
	{
		s += '0';
		return (s);
	}
	minus = false;
	if (n < 0)
		minus = true;
	while (n != 0)
	{
		s += ((char)std::abs(n % 10) + '0');
		n /= 10;
	}
	if (minus == true)
		s += '-';
	s = ft_reverse(s);
	return (s);
}

# include <sstream>

template <typename T>
std::string	to_string(T data)
{
	std::ostringstream	stream;

	stream << data;
	return (stream.str());
}

#if __cplusplus < 201103L
#endif
