/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:52:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 16:52:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP
# include "lib/lib.hpp"
# include <map>

class Date
{
protected:
	enum e_date
	{
		T_YEAR,
		T_MONTH,
		T_DAY,
		T_HOUR,
		T_MINUTE,
		T_SECOND,
		T_ALL,
	};
	enum e_ranges
	{
		R_YEAR_MIN =	1900,
		R_YEAR_MAX =	2100,
		R_MONTH_MIN = 	1,
		R_MONTH_MAX = 	12,
		R_CLOCK_MIN = 	0,
		R_CLOCK_MAX = 	59,
		R_ALL,
	};
	enum e_calendar
	{
		C_JANUARY = 	31,
		C_FEBRUARY = 	28,
		C_MARCH = 		31,
		C_APRIL = 		30,
		C_MAY = 		31,
		C_JUNE = 		30,
		C_JULY = 		31,
		C_AUGUST = 		31,
		C_SEPTEMBER = 	30,
		C_OCTOBER = 	31,
		C_NOVEMBER = 	30,
		C_DECEMBER = 	31,
		C_ALL =			12,
	};
	int32_t	_year;
	int32_t	_month;
	int32_t	_day;
	int8_t	_hour;
	int8_t	_minute;
	int8_t	_second;
	bool	_has_seconds;
	void	check_year(int32_t year);
	void	check_month(int32_t month);
	void	check_day(int32_t day);
	void	check_clock(int32_t clock);
public:
//	canonic form:
	Date(string date, char separator);
	Date(string date, char separator, bool has_seconds);
	Date(int32_t year, int32_t month, int32_t day);
	~Date();
	Date(const Date &other);
	Date &operator=(const Date &other);
};

#endif
