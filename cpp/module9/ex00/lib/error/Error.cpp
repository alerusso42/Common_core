/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:06:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/04 20:09:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

Error::Error(int code) : std::runtime_error(get_msg(code, ERROR_MAIN_CODE))
{
	this->_code = code;
}

Error::Error(int code, int section) : std::runtime_error(get_msg(code, section))
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

/*
	EX_BAD_VALUE,
	EX_TOO_MANY_FIELDS,
	EX_FILE,
	EX_NUMERIC_RANGE,
	EX_NUM,
*/
std::string	 Error::get_msg_main_code(int type)
{
	std::string	 s;

	if (type == EX_BAD_VALUE)
		s = "Bitcoin has bad value.";
	else if (type == EX_ARRAY_OUT_BOUND)
		s = "Entry has too many fields";
	else if (type == EX_ARRAY_NEGATIVE_INDEX)
		s = "Cannot open file";
	else if (type == EX_ARRAY_ALLOC)
		s = "Bitcoin range does not allowed input value";
	else
		s = "Unknown";
	return (s);
}

std::string	 Error::get_msg(int type, int section)
{
	switch (section)
	{
		case (ERROR_MAIN_CODE) :
			return (get_msg_main_code(type));
		case (ERROR_ARRAY) :
			return ((std::string)"Array:\t" + get_msg_array(type));
		case (ERROR_DATE) :
			return ((std::string)"Array:\t" + get_msg_array(type));
		default :
			return ("Bad section");
	}
}

std::string	 Error::get_msg_array(int type)
{
	std::string	 s;

	if (type == EX_ARRAY_BAD_SIZE)
		s = "Specified size is too big.";
	else if (type == EX_ARRAY_OUT_BOUND)
		s = "Element is out of bounds";
	else if (type == EX_ARRAY_NEGATIVE_INDEX)
		s = "Negative index is not allowed";
	else if (type == EX_ARRAY_ALLOC)
		s = "Allocation failed";
	else
		s = "Unknown";
	return (s);
}

static std::string	time_range_msg(int type);

std::string	 Error::get_msg_date(int type)
{
	std::string	 s;

	if (type == EX_DATE_BAD)
		s = "Bad time";
	else if (type == EX_DATE_NEGATIVE)
		s = "Negative time in database";
	else if (type > EX_DATE_RANGE_START && type < EX_DATE_RANGE_END)
	{
		s = "Out of range time value in database:\t";
		s += time_range_msg(type);
	}
	else if (type == EX_DATE_YEAR_LOW)
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

static std::string	time_range_msg(int type)
{
	std::string	s;

	s.clear();
	if (type == EX_DATE_YEAR_HIGH)
		s = "Year too high";
	else if (type == EX_DATE_YEAR_LOW)
		s = "Year too low";
	else if (type == EX_DATE_MONTH_HIGH)
		s = "Month does not exist, maximum allowed is 12";
	else if (type == EX_DATE_MONTH_LOW)
		s = "Month does not exist, minimum allowed is 0";
	else if (type == EX_DATE_DAY_HIGH)
		s = "Day too high for selected month";
	else if (type == EX_DATE_HOUR_LOW)
		s = "Hour too low, minimum allowed is 0";
	else if (type == EX_DATE_HOUR_HIGH)
		s = "Hour too high, maximum allowed is 23";
	else if (type == EX_DATE_DAY_LOW)
		s = "Day too low, minimum allowed is 1";
	else if (type == EX_DATE_CLOCK_HIGH)
		s = "Clock times (hour, minute, second) must not be higher than 59";
	else if (type == EX_DATE_CLOCK_LOW)
		s = "Clock times (hour, minute, second) must not be lower than 0";
	else if (type == EX_DATE_BISESTILE)
		s = "year is not bisestile";
	return (s);
}
