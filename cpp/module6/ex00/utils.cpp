/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:27:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/25 14:44:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

static bool	ft_strchr(string s, string charset);

int		find_type(string s, int special_case)
{
	if (ft_strchr(s, ".f") == false)
	{
		if (std::atoi(s.c_str()) <= 255)
			return (T_CHAR);
		return (T_INT);
	}
	if (special_case)
	{
		if (special_case >= S_INFF && special_case <= S_NANF)
			return (T_DOUBLE);
		return (T_FLOAT);
	}
	if (std::atof(s.c_str()) < 3.40e+38)
		return (T_FLOAT);
	return (T_DOUBLE);
}

static bool	ft_strchr(string s, string charset)
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
	std::cout << "char:\t";
	if (special_case)
		std::cout << "Impossible\n";
	else if (n <= 31 || n >= 127)
		std::cout << "Not displayable\n";
	else
		std::cout << static_cast<char>(n) << "\n";
}

void	convert_int(double n, int special_case, int type)
{
	std::cout << "int:\t";
	if (special_case)
		std::cout << "Impossible\n";
	else
		std::cout << static_cast<int>(n) << "\n";
}

void	convert_float(double n, int special_case, int type)
{
	(void)special_case;
	std::cout << "float:\t"<< static_cast<float>(n) << "\n";
}

void	convert_double(double n, int special_case, int type)
{
	(void)special_case;
	std::cout << "double:\t"<< n;
}
