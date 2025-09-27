/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:27:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 13:43:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

bool	ft_strchr(string s, string charset)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[j])
		{
			if (s[i] == charset[j])
				return (true);
			++j;
		}
		i++;
	}
	return (false);
}

string	put_dot(int type, bool f)
{
	string	s;

	s.clear();
	if (type == T_CHAR || type == T_INT)
		s += ".0";
	if (f)
		s += "f";
	return (s);
}

bool	decimal_not_zero(string s)
{
	int	i;

	i = s.find(".");
	if (i < 0)
		return (false);
	++i;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != 'f')
			return (true);
		++i;
	}
	return (false);
}

int	ft_isdigit(char c)
{
	return ((c >= '0' || c <= '9') * c);
}
