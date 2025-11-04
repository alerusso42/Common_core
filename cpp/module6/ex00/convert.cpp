/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:42:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/04 15:11:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"

void	convert_char(double n, int special_case, int type)
{
	(void)type;
	std::cout << C_YELLOW << "char:\t" << C_RESET;
	if (special_case)
		std::cout << "Impossible\n";
	else if (n <= 31 || n >= 127)
		std::cout << "Not displayable\n";
	else
		std::cout << "'" << static_cast<char>(n) << "'" << "\n";
}

void	convert_int(double n, int special_case, int type)
{
	(void)type;
	std::cout << C_YELLOW << "int:\t" << C_RESET;
	if (type == T_OVERFLOW)
		std::cout << "Impossible (overflow/underflow)\n";
	else if (special_case)
		std::cout << "Impossible\n";
	else
		std::cout << static_cast<int>(n) << "\n";
}

void	convert_float(double n, int special_case, int type)
{
	std::cout << C_YELLOW << "float:\t" << C_RESET << std::setprecision(6);
	if (special_case)
	{
		if (type == T_DOUBLE && special_case)
			convert_special(special_case - S_HALF);
		else
			convert_special(special_case);
	}
	else if (type != T_DOUBLE)
		std::cout << n << put_dot(type, true) << "\n";
	else
		std::cout << "Impossible (overflow/underflow)\n";
	std::cout << std::setprecision(0);
}

void	convert_double(double n, int special_case, int type)
{
	std::cout << C_YELLOW << "double:\t" << C_RESET << std::setprecision(15);
	if (special_case)
	{
		if (type == T_FLOAT && special_case)
			convert_special(special_case + S_HALF);
		else
			convert_special(special_case);
	}
	else
		std::cout << n << put_dot(type, false) << "\n";
	std::cout << std::setprecision(0);
}

void	convert_special(int special_case)
{
	std::string	 special[] = {SPECIAL};

	std::cout << special[special_case] << "\n";
}
