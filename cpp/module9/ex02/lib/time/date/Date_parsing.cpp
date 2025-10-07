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

int32_t	Date::check_year(int32_t year) const
{
	if (year < R_YEAR_MIN)
		throw (Error(EX_DATE_YEAR_LOW, ERROR_DATE, R_YEAR_MIN));
	else if (year > R_YEAR_MAX)
		throw (Error(EX_DATE_YEAR_HIGH, ERROR_DATE, R_YEAR_MAX));
	return (year);
}

int32_t	Date::check_month(int32_t month) const
{
	if (month < R_MONTH_MIN)
		throw (Error(EX_DATE_MONTH_LOW, ERROR_DATE, R_MONTH_MIN));
	else if (month > R_MONTH_MAX)
		throw (Error(EX_DATE_MONTH_HIGH, ERROR_DATE, R_MONTH_MAX));
	return (month);
}

int32_t	Date::check_day(int32_t day) const
{
	int32_t	calendar[C_ARRAY];

	if (day < R_DAY_MIN)
		throw (Error(EX_DATE_DAY_LOW, ERROR_DATE, R_MONTH_MIN));
	make_calendar(calendar);
	if (this->_month == FEBRUARY && day == C_FEBRUARY + 1)
	{
		if (calendar[FEBRUARY] != C_FEBRUARY + 1)
			throw (Error(EX_DATE_BISESTILE, ERROR_DATE, this->_year));
	}
	if (day > calendar[this->_month])
		throw (Error(EX_DATE_DAY_HIGH, ERROR_DATE, calendar[this->_month]));
	return (day);
}

int32_t	Date::check_hour(int32_t hour) const
{
	if (hour < R_HOUR_MIN)
		throw (Error(EX_DATE_HOUR_LOW, ERROR_DATE, R_HOUR_MIN));
	else if (hour > R_HOUR_MAX)
		throw (Error(EX_DATE_HOUR_HIGH, ERROR_DATE, R_HOUR_MAX));
	return (hour);
}

int32_t	Date::check_clock(int32_t clock) const
{
	if (clock < R_CLOCK_MIN)
		throw (Error(EX_DATE_CLOCK_LOW, ERROR_DATE));
	else if (clock > R_CLOCK_MAX)
		throw (Error(EX_DATE_CLOCK_HIGH, ERROR_DATE));
	return (clock);
}

/*
	A year in the gregorian calendar is bisestile if:
	(checks are in priority order)

	1)	is a multiple of 400 (1600, 2000, ecc.);
	2)	is NOT a multiple of 100 (1600, 2000, ecc.);
	3)	is a multiple of 4.
*/
bool	Date::is_bisestile(int32_t year) const
{
	if (year % 400 == 0)
		return (true);
	else if (year % 100 == 0)
		return (false);
	else if (year % 4 == 0)
		return (true);
	return (false);
}
