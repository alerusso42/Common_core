/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:06:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/04 08:54:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

Error::Error(int code) : std::runtime_error(get_msg(code))
{
	this->_code = code;
}

int	Error::get_code()
{
	return (this->_code);
}

void	Error::print(void) const
{
	std::cerr << "\033[31mException: " << this->what();
	std::cerr << "[" << this->_code << "]\033[0m" << std::endl;
}

std::string	 Error::get_msg(int type)
{
	std::string	 s;

	if (type == EX_TIME_BAD)
		s = "Bad time in database";
	if (type == EX_TIME_NEGATIVE)
		s = "Negative time in database";
	if (type > EX_TIME_RANGE_START && type < EX_TIME_RANGE_END)
	{
		s = "Out of range time value in database";
	}
	if (type == EX_TIME_YEAR_LOW)
		s = "Out of range time value in database: year too low";
	else if (type == EX_BAD_VALUE)
		s = "Bad value in database";
	else if (type == EX_TOO_MANY_FIELDS)
		s = "Database entry must have two field: data and bitcoin value";
	else if (type == EX_FILE)
		s = "Open failed. Probably for second database file";
	else if (type == EX_NUMERIC_RANGE)
		s = "Values must be positive integer/float ranging from 0 to 10k";
	else
		s = "Unknown";
	return (s);
}
