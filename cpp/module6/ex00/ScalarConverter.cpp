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
	bool	special_case;

	special_case = special_cases(literal);
	n = std::atof(literal.c_str());
	if (n <= 31 || n >= 127)
		std::cout << "Not displayable\n";
	else if (special_case)
		std::cout << "Impossible\n";
	else
		std::cout << "char:\t" << static_cast<char>(n) << "\n";
	if (special_case)
		std::cout << "Impossible\n";
	else
		std::cout << "int:\t" << static_cast<int>(n) << "\n";
	std::cout << "float:\t"<< static_cast<float>(n) << "\n";
	std::cout << "double:\t"<< n;
	std::cout << std::endl;
}

bool	special_cases(string s)
{
	string	special[]	= {SPECIAL};

	for (int i = 0; special[i].empty() == false; i++)
	{
		if (s == special[i])
			return (true);
	}
	return (false);
}
