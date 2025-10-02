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

void	ScalarConverter::convert(std::string literal)
{
	double	n;
	int		special_case;
	int		type;

	special_case = special_cases(literal);
	type = find_type(literal, special_case);
	if (type == T_CHAR && literal.length() == 1 && !ft_isdigit(literal[0]))
		n = literal[0];
	else
		n = std::atof(literal.c_str());
	convert_char(n, special_case, type);
	convert_int(n, special_case, type);
	convert_float(n, special_case, type);
	convert_double(n, special_case, type);
	std::cout << "\n";
}

int	special_cases(std::string s)
{
	std::string	 special[]	= {SPECIAL};

	for (int i = 0; special[i].empty() == false; i++)
	{
		if (s == special[i])
			return (i);
	}
	return (false);
}

int		find_type(std::string s, int special_case)
{
	double	n;

	if (s.length() == 1 && s[0] > 31 && s[0] < 127)
		return (T_CHAR);
	else if (!special_case && overflow_check(s))
		return (T_OVERFLOW);
	else if (special_case)
	{
		if (special_case >= S_INFF && special_case <= S_NANF)
			return (T_FLOAT);
		return (T_DOUBLE);
	}
	else if (ft_strchr(s, ".f") == false || decimal_not_zero(s) == false)
	{
		if (std::atoi(s.c_str()) <= UCHAR_MAX)
			return (T_CHAR);
		return (T_INT);
	}
	n = std::atof(s.c_str());
	if (float_out_of_range(n) == false)
		return (T_FLOAT);
	return (T_DOUBLE);
}
