/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:06:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/07 01:04:23 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

//SECTION - Message list
/*
	EX_INVALID_CHAR,
	EX_EMPTY_STACK,
	EX_DIVISION,
*/
std::string	 Error::get_msg_main_code(int type)
{
	std::string	 s;

	if (type == EX_REPEATED)
		s = "Cannot repeat numbers. Repeated:";
	return (s);
}

//SECTION - Class implementation

Error::Error(int code) : \
std::runtime_error(get_msg(code, ERROR_MAIN_CODE))
{
	this->_code = code;
}

Error::Error(int code, int section) : \
std::runtime_error(get_msg(code, section))
{
	this->_code = code;
}

int	Error::get_code()
{
	return (this->_code);
}

void	Error::print(void) const
{
	std::cerr << "\033[31mException" << this->what();
	std::cerr << "[" << this->_code << "]\033[0m" << std::endl;
}

std::string	 Error::get_msg(int type, int section)
{
	switch (section)
	{
		case (ERROR_MAIN_CODE) :
			return ((std::string)":\t" + get_msg_main_code(type));
		case (ERROR_ARRAY) :
			return ((std::string)"[Array]: " + get_msg_array(type));
		case (ERROR_DATE) :
			return ((std::string)"[Date]: " + get_msg_date(type));
		default :
			return ("[Bad section]");
	}
}

std::string	Error::get_msg(int type, int section, std::string s)
{
	s.insert(0, " => ");
	switch (section)
	{
		case (ERROR_MAIN_CODE) :
			return ((std::string)":\t" + get_msg_main_code(type) + s);
		case (ERROR_ARRAY) :
			return ((std::string)"[Array] " + get_msg_array(type) + s);
		case (ERROR_DATE) :
			return ((std::string)"[Date] " + get_msg_date(type) + s);
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
		s = "Negative time not allowed";
	else if (type > EX_DATE_RANGE_START && type < EX_DATE_RANGE_END)
	{
		s = "Out of range time value: ";
		s += time_range_msg(type);
	}
	else if (type == EX_DATE_ALTER)
		s = "Operation made the Date class go out of range";
	else if (type == EX_DATE_BISESTILE)
		s = "year is not bisestile";
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
		s = "Month does not exist";
	else if (type == EX_DATE_MONTH_LOW)
		s = "Month does not exist";
	else if (type == EX_DATE_DAY_HIGH)
		s = "Day too high for selected month";
	else if (type == EX_DATE_HOUR_LOW)
		s = "Hour too low";
	else if (type == EX_DATE_HOUR_HIGH)
		s = "Hour too high";
	else if (type == EX_DATE_DAY_LOW)
		s = "Day too low";
	else if (type == EX_DATE_CLOCK_HIGH)
		s = "Clock times (minute, second)";
	else if (type == EX_DATE_CLOCK_LOW)
		s = "Clock times (minute, second)";
	if (type % 2 == 0)
		s += ": maximum allowed is";
	else
		s += ": minimum allowed is";
	return (s);
}
