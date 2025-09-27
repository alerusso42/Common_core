/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:27:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 12:00:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

//DBL_MAX

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

void	convert_char(double n, int special_case, int type)
{
	(void)type;
	std::cout << "char:\t";
	if (type == T_OVERFLOW)
		std::cout << "Impossible (overflow/underflow)\n";
	else if (special_case)
		std::cout << "Impossible\n";
	else if (n <= 31 || n >= 127)
		std::cout << "Not displayable\n";
	else
		std::cout << static_cast<char>(n) << "\n";
}

void	convert_int(double n, int special_case, int type)
{
	(void)type;
	std::cout << "int:\t";
	if (type == T_OVERFLOW)
		std::cout << "Impossible (overflow/underflow)\n";
	else if (special_case)
		std::cout << "Impossible\n";
	else
		std::cout << static_cast<int>(n) << "\n";
}

void	convert_float(double n, int special_case, int type)
{
	std::cout << "float\t";
	if (type == T_OVERFLOW)
		std::cout << "Impossible (overflow/underflow)\n";
	else if (special_case)
	{
		if (type == T_DOUBLE && special_case)
			convert_special(special_case - S_HALF);
		else
			convert_special(special_case);
	}
	else if (type != T_DOUBLE)
		std::cout << static_cast<float>(n) << "\n";
	else
		std::cout << "Impossible (overflow/underflow)\n";
}

void	convert_double(double n, int special_case, int type)
{
	std::cout << "double\t";
	if (type == T_OVERFLOW)
		std::cout << "Impossible (overflow/underflow)\n";
	else if (special_case)
	{
		if (type == T_FLOAT && special_case)
			convert_special(special_case + S_HALF);
		else
			convert_special(special_case);
	}
	else
		std::cout << n << "\n";
}

void	convert_special(int special_case)
{
	string	special[] = {SPECIAL};

	std::cout << special[special_case] << "\n";
}
