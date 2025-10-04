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
# include "../../lib.hpp"

class Date
{
private:
	void	add_field(int32_t datas[]);
	int32_t	find_difference(const Date &other) const;
	void	alter_values(Date &date, int32_t value);
	void	make_calendar(int32_t calendar[]) const;
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
		T_ARRAY,
	};
	enum e_ranges
	{
		R_YEAR_MIN =	1900,
		R_YEAR_MAX =	2100,
		R_MONTH_MIN = 	1,
		R_MONTH_MAX = 	12,
		R_DAY_MIN =		1,
		R_HOUR_MIN = 	0,
		R_HOUR_MAX = 	23,
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
		FEBRUARY = 2,
	};
	int32_t	_year;
	int32_t	_month;
	int32_t	_day;
	int8_t	_hour;
	int8_t	_minute;
	int8_t	_second;
	int8_t	_separator;
	bool	_has_clock;

	int32_t	check_year(int32_t year) const;
	int32_t	check_month(int32_t month) const;
	int32_t	check_day(int32_t day) const;
	int32_t	check_hour(int32_t hour) const;
	int32_t	check_clock(int32_t clock) const;
	int32_t	check_bisestile(int32_t bisestile) const;
public:
//	canonic form:
	Date(std::string date, char separator);
	Date(std::string date, char separator, bool has_seconds);
	Date(int32_t year, int32_t month, int32_t day);
	Date(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second);
	~Date();
	Date(const Date &other);
	Date &operator=(const Date &other);

	//SECTION - getters
	int32_t	*get_date(int32_t fields[]) const;
	int32_t	*get_date(int32_t fields[], bool get_clock) const;
	bool	get_clock_bool(void) const;

	//SECTION - operator overloads
	bool	operator<(const Date &other) const;
	bool	operator<=(const Date &other) const;
	bool	operator>(const Date &other) const;
	bool	operator>=(const Date &other) const;
	bool	operator==(const Date &other) const;
	Date	&operator++(void);
	Date	&operator--(void);
	Date	operator++(int post);
	Date	operator--(int post);

	//SECTION - print
	void	basic_print(std::ostream &ostream) const;
};

std::ostream	&operator<<(std::ostream &stream, const Date &date);

#endif
