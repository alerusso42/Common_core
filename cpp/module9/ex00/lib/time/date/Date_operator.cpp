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

static bool	alter_one(int32_t *time, int32_t value, int32_t min, int32_t max);
static bool	alter_one(int32_t *time, int32_t value, int32_t min, int32_t cal[], int32_t mon);

/*
	For now it works only with 1 and -1
*/
void	Date::alter_values(Date &date, int32_t value)
{
	int32_t	calendar[C_ARRAY];

	if (date._has_clock)
	{
		if (alter_one((int32_t *)&date._second, value, R_CLOCK_MIN, R_CLOCK_MAX) == true)
			return ;
		if (alter_one((int32_t *)&date._minute, value, R_CLOCK_MIN, R_CLOCK_MAX) == true)
			return ;
		if (alter_one((int32_t *)&date._hour, value, R_HOUR_MIN, R_HOUR_MAX) == true)
			return ;
	}
	make_calendar(date, calendar);
	if (alter_one(&date._day, value, R_DAY_MIN, calendar, date._month) == true)
		return ;
	if (alter_one(&date._month, value, R_MONTH_MIN, R_MONTH_MAX) == true)
		return ;
	if (alter_one(&date._year, value, R_YEAR_MIN, R_YEAR_MAX) == true)
		return ;
	throw (Error(EX_DATE_ALTER, ERROR_DATE));
}

static bool	alter_one(int32_t *time, int32_t value, int32_t min, int32_t max)
{
		*time += value;
		if (*time < min)
			*time = max;
		else if (*time > max)
			*time = min;
		else
			return (true);
		return (false);
}

static bool	alter_one(int32_t *time, int32_t value, int32_t min, int32_t cal[], int32_t mon)
{
		*time += value;
		if (*time < min)
			*time = cal[mon - 1];
		else if (*time > cal[mon])
			*time = min;
		else
			return (true);
		return (false);
}

static void	normalize_op(int32_t value, int32_t *op, int32_t *reverse_sign)
{
	if (value < 0)
	{
		*op *= -1;
		*reverse_sign = 1;
	}
	else
	{
		*reverse_sign = -1;
	}
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

Date	&Date::operator++(void)
{
	alter_values(*this, +1);
	return (*this);
}

Date	&Date::operator--(void)
{
	alter_values(*this, -1);
	return (*this);
}

Date	Date::operator++(int post)
{
	Date	before(*this);

	(void)post;
	alter_values(*this, +1);
	return (before);
}

Date	Date::operator--(int post)
{
	Date	before(*this);

	(void)post;
	before = *this;
	alter_values(*this, -1);
	return (before);
}

Date	&Date::operator+=(int32_t value)
{
	int32_t	op = +1;
	int32_t	reverse_sign;

	if (value == 0)
		return (*this);
	normalize_op(value, &op, &reverse_sign);
	while (value)
	{
		alter_values(*this, reverse_sign);
		value += reverse_sign;
	}
	return (*this);
}

Date	&Date::operator-=(int32_t value)
{
	int32_t	op = -1;
	int32_t	reverse_sign;

	if (value == 0)
		return (*this);
	normalize_op(value, &op, &reverse_sign);
	while (value)
	{
		alter_values(*this, reverse_sign);
		value += reverse_sign;
	}
	return (*this);
}

Date	Date::operator+(int32_t value)
{
	Date	date(*this);
	int32_t	op = +1;
	int32_t	reverse_sign;

	if (value == 0)
		return (date);
	normalize_op(value, &op, &reverse_sign);
	while (value)
	{
		alter_values(date, op);
		value += reverse_sign;
	}
	return (date);
}

Date	Date::operator-(int32_t value)
{
	Date	date(*this);
	int32_t	op = -1;
	int32_t	reverse_sign;

	if (value == 0)
		return (date);
	normalize_op(value, &op, &reverse_sign);
	while (value)
	{
		alter_values(date, op);
		value += reverse_sign;
	}
	return (date);
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
