/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:35:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/23 21:35:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{(void)other; return (*this);}

void	ScalarConverter::convert(string literal)
{
	double	n;
	int		special_case;
	int		type;

	special_case = special_cases(literal);
	type = find_type(literal, special_case);
	(void)type;
	n = std::atof(literal.c_str());
	convert_char(n, special_case, type);
	convert_int(n, special_case, type);
	convert_float(n, special_case, type);
	convert_double(n, special_case, type);
	std::cout << "\n";
}

int	special_cases(string s)
{
	string	special[]	= {SPECIAL};

	for (int i = 0; special[i].empty() == false; i++)
	{
		if (s == special[i])
			return (i);
	}
	return (false);
}
