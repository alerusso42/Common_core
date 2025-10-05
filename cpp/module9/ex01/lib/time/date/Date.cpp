/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:52:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 16:52:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(std::string date, char separator)
{
	int32_t	datas[T_ALL + 1];
	size_t	pos;
	int		i;

	if (valid_input(date) == false)
		throw Error(EX_DATE_BAD, ERROR_DATE);
	pos = 0;
	i = 0;
	while (date[pos] && i < T_HOUR)
	{
		if (ft_atoi(date, &datas[i], pos) != 0)
			throw Error(EX_DATE_BAD, ERROR_DATE);
		else if (datas[i] < 0)
			throw Error(EX_DATE_NEGATIVE, ERROR_DATE);
		pos = date.find_first_of(separator, pos);
		if (pos == date.npos)
			break ;			
		pos += 1;
		++i;
	}
	if (i < T_DAY)
		throw Error(EX_DATE_BAD, ERROR_DATE);
	this->_has_clock = false;
	this->_separator = separator;
	add_field(datas);
}

Date::Date(std::string date, char separator, bool has_clock)
{
	int32_t	datas[T_ALL + 1];
	size_t	pos;
	int		i;

	if (valid_input(date) == false)
		throw Error(EX_DATE_BAD, ERROR_DATE);
	pos = 0;
	i = 0;
	while (date[i] && i < T_ALL)
	{
		if (ft_atoi(date, &datas[i], pos) != 0)
			throw Error(EX_DATE_BAD, ERROR_DATE);
		else if (datas[i] < 0)
			throw Error(EX_DATE_NEGATIVE, ERROR_DATE);
		pos = date.find_first_of(separator, pos);
		if (pos == date.npos)
			break ;
		pos += 1;
		++i;
	}
	if ((has_clock && i < T_SECOND) || (!has_clock && i < T_DAY))
		throw Error(EX_DATE_BAD, ERROR_DATE);
	this->_has_clock = has_clock;
	this->_separator = separator;
	add_field(datas);
}

Date::Date(int32_t year, int32_t month, int32_t day)
{
	int32_t	fields[] = {year, month, day};

	this->_has_clock = false;
	this->_separator = '-';
	add_field(fields);
}

Date::Date(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second)
{
	int32_t	fields[] = {year, month, day, hour, minute, second};

	this->_has_clock = true;
	this->_separator = '-';
	add_field(fields);
}

Date::~Date()
{}

Date::Date(const Date &other)
{ 
	if (this == &other)
		return ;
	this->_separator = other._separator;
	this->_year = other._year;
	this->_month = other._month;
	this->_day = other._day;
	this->_has_clock = other._has_clock;
	if (this->_has_clock == false)
		return ;
	this->_hour = other._hour;
	this->_minute = other._minute;
	this->_second = other._second;
	return ;
}

Date &Date::operator=(const Date &other)
{
	if (this == &other)
		return (*this);
	this->_separator = other._separator;
	this->_year = other._year;
	this->_month = other._month;
	this->_day = other._day;
	this->_has_clock = other._has_clock;
	if (this->_has_clock == false)
		return (*this);
	this->_hour = other._hour;
	this->_minute = other._minute;
	this->_second = other._second;
	return (*this);
}

//SECTION - private

void	Date::add_field(int32_t datas[])
{
	this->_year = check_year(datas[T_YEAR]);
	this->_month = check_month(datas[T_MONTH]);
	this->_day = check_day(datas[T_DAY]);
	if (this->_has_clock == false)
		return ;
	this->_hour = check_hour(datas[T_HOUR]);
	this->_minute = check_clock(datas[T_MINUTE]);
	this->_second = check_clock(datas[T_SECOND]);
}

void	Date::make_calendar(int32_t calendar[]) const
{
	int32_t	i;

	i = 0;
	calendar[i++] = C_DECEMBER;
	calendar[i++] = C_JANUARY;
	if (is_bisestile(this->_year) == true)
		calendar[i++] = C_FEBRUARY + 1;
	else
		calendar[i++] = C_FEBRUARY;
	calendar[i++] = C_MARCH;
	calendar[i++] = C_APRIL;
	calendar[i++] = C_MAY;
	calendar[i++] = C_JUNE;
	calendar[i++] = C_JULY;
	calendar[i++] = C_AUGUST;
	calendar[i++] = C_SEPTEMBER;
	calendar[i++] = C_OCTOBER;
	calendar[i++] = C_NOVEMBER;
	calendar[i++] = C_DECEMBER;
	calendar[i++] = C_JANUARY;
}

void	Date::make_calendar(const Date &other, int32_t calendar[]) const
{
	int32_t	i;

	i = 0;
	calendar[i++] = C_DECEMBER;
	calendar[i++] = C_JANUARY;
	if (is_bisestile(other._year) == true)
		calendar[i++] = C_FEBRUARY + 1;
	else
		calendar[i++] = C_FEBRUARY;
	calendar[i++] = C_MARCH;
	calendar[i++] = C_APRIL;
	calendar[i++] = C_MAY;
	calendar[i++] = C_JUNE;
	calendar[i++] = C_JULY;
	calendar[i++] = C_AUGUST;
	calendar[i++] = C_SEPTEMBER;
	calendar[i++] = C_OCTOBER;
	calendar[i++] = C_NOVEMBER;
	calendar[i++] = C_DECEMBER;
	calendar[i++] = C_JANUARY;
}

//SECTION - Public
//SECTION - getters

int32_t	*Date::get_date(int32_t fields[]) const
{
	fields[T_YEAR] = this->_year;
	fields[T_MONTH] = this->_month;
	fields[T_DAY] = this->_day;
	fields[T_HOUR] = -1;
	if (this->_has_clock == false)
		return (fields);
	fields[T_HOUR] = this->_hour;
	fields[T_MINUTE] = this->_minute;
	fields[T_SECOND] = this->_second;
	fields[T_ALL] = -1;
	return (fields);
}

/*
	Needs fields size + 1: last is filled with a -1 (sentinel value).
*/
int32_t	*Date::get_date(int32_t fields[], bool get_clock) const
{
	fields[T_YEAR] = this->_year;
	fields[T_MONTH] = this->_month;
	fields[T_DAY] = this->_day;
	fields[T_HOUR] = -1;
	if (this->_has_clock == false && get_clock == true)
		return (fields);
	fields[T_HOUR] = this->_hour;
	fields[T_MINUTE] = this->_minute;
	fields[T_SECOND] = this->_second;
	fields[T_ALL] = -1;
	return (fields);
}

bool	Date::get_clock_bool(void) const
{
	return (this->_has_clock);
}

//SECTION - print

void	Date::basic_print(std::ostream &ostream) const
{
	int32_t	fields[T_ARRAY];

	get_date(fields);
	for (int i = 0; fields[i] > 0; i++)
	{
		if (i != 0)
			ostream << this->_separator;
		if (fields[i] < 10)
			ostream << "0";
		ostream << fields[i];
	}
}
