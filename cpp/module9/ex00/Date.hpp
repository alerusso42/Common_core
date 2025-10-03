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
private:
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
	int32_t	_datas[T_ALL + 1];
	int32_t	_year;
	int32_t	_month;
	int32_t	_day;
	int8_t	_hour;
	int8_t	_minute;
	int8_t	_second;
	bool		_has_seconds;
public:
//	canonic form:
	Date(string date);
	Date(string date, bool has_seconds);
	Date(int32_t year, int32_t month, int32_t day);
	~Date();
	Date(const Date &other);
	Date &operator=(const Date &other);
};

#endif
