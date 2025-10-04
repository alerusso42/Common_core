/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date_Date::operator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:02:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/04 19:13:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

//NOTE - find_difference
/*
	This function returns:
	-1 if this is less than other;
	0 if they are equal;
	1 if this is bigger than other.

	If this or other does not have clock values (hour, minute, second), it
	is not considered in the comparation, even if the other data struct has it.
*/
int32_t	Date::find_difference(const Date &other) const
{
	int32_t	this_date[T_ARRAY];
	int32_t	other_date[T_ARRAY];

	this->get_date(this_date);
	other.get_date(other_date);
	for (int i = T_YEAR; i != T_ALL; i++)
	{
		if (this_date[i] > other_date[i])
			return (1);
		else if (this_date[i] < other_date[i])
			return (-1);
		else if (i == T_HOUR)
			if (this->_has_clock == false || other._has_clock == false)
				return (0);
	}
	return (0);
}

bool	Date::operator<(const Date &other) const
{
	return (find_difference(other) == -1);
}

bool	Date::operator<=(const Date &other) const
{
	return (find_difference(other) <= 0);
}

bool	Date::operator>(const Date &other) const
{
	return (find_difference(other) == 1);
}

bool	Date::operator>=(const Date &other) const
{
	return (find_difference(other) >= 0);
}

bool	Date::operator==(const Date &other) const
{
	return (find_difference(other) == 0);
}

std::ostream	&operator<<(std::ostream &stream, const Date &date)
{
	int32_t	datas[20];

	date.get_date(datas);
	stream << "\033[34m";
	if (date.get_clock_bool() == true)
		stream << "Date:\tYear\tMonth\tDay\tHour\tMinute\tSecond\n";
	else
		stream << "Date:\tYear\tMonth\tDay\n";
	stream << "\033[33m";
	stream << "Values:\t";
	for (int32_t i = 0; datas[i] > 0; i++)
	{
		stream << datas[i] << "\t";
	}
	stream << "\033[0m";
	return (stream);
}
