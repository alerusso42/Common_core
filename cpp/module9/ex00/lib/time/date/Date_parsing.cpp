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
		throw (Error(EX_DATE_YEAR_LOW, ERROR_DATE));
	else if (year > R_YEAR_MAX)
		throw (Error(EX_DATE_YEAR_HIGH, ERROR_DATE));
	return (year);
}

int32_t	Date::check_month(int32_t month) const
{
	if (month < R_MONTH_MIN)
		throw (Error(EX_DATE_MONTH_LOW, ERROR_DATE));
	else if (month > R_MONTH_MAX)
		throw (Error(EX_DATE_MONTH_HIGH, ERROR_DATE));
	return (month);
}

int32_t	Date::check_day(int32_t day) const
{
	int32_t	calendar[C_ALL + 1];
	int32_t	i;

	if (day < R_DAY_MIN)
		throw (Error(EX_DATE_DAY_LOW, ERROR_DATE));
	if (this->_month == FEBRUARY)
		return (check_bisestile(day));
	i = 1;
	calendar[i++] = C_JANUARY;
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
	if (day > calendar[this->_month])
		throw (Error(EX_DATE_DAY_HIGH, ERROR_DATE));
	return (day);
}

int32_t	Date::check_hour(int32_t hour) const
{
	if (hour < R_HOUR_MIN)
		throw (Error(EX_DATE_HOUR_LOW, ERROR_DATE));
	else if (hour > R_HOUR_MAX)
		throw (Error(EX_DATE_HOUR_HIGH, ERROR_DATE));
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
int32_t	Date::check_bisestile(int32_t day) const
{
	if (day <= C_FEBRUARY)
		return (day);
	else if (day != 29)
		throw (Error(EX_DATE_DAY_HIGH, ERROR_DATE));
	else if (this->_year % 400 == 0)
		return (day);
	else if (this->_year % 100 == 0)
		throw (Error(EX_DATE_BISESTILE, ERROR_DATE));
	else if (this->_year % 4 != 0)
		throw (Error(EX_DATE_BISESTILE, ERROR_DATE));
	return (day);
}
