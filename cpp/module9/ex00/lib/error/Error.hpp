/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:04:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/04 19:55:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include <stdexcept>
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

enum e_error_main
{
	EX_BAD_VALUE,
	EX_TOO_MANY_FIELDS,
	EX_FILE,
	EX_NUMERIC_RANGE,
	EX_NUM,
};

enum	e_error_section
{
	ERROR_MAIN_CODE,
	ERROR_ARRAY,
	ERROR_DATE,
	ERROR_SECTIONS,
};

enum	e_error_array
{
	EX_ARRAY_BAD_SIZE,
	EX_ARRAY_OUT_BOUND,
	EX_ARRAY_NEGATIVE_INDEX,
	EX_ARRAY_ALLOC,
	EX_ARRAY_NUM,
};

enum e_error_date
{
	EX_DATE_BAD,
	EX_DATE_NEGATIVE,
	EX_DATE_RANGE_START,
	EX_DATE_YEAR_LOW,
	EX_DATE_YEAR_HIGH,
	EX_DATE_MONTH_LOW,
	EX_DATE_MONTH_HIGH,
	EX_DATE_DAY_LOW,
	EX_DATE_DAY_HIGH,
	EX_DATE_HOUR_LOW,
	EX_DATE_HOUR_HIGH,
	EX_DATE_CLOCK_LOW,
	EX_DATE_CLOCK_HIGH,
	EX_DATE_BISESTILE,
	EX_DATE_RANGE_END,
	EX_DATE_NUM,
};

class Error : public std::runtime_error
{
private:
	int			_code;
	std::string	get_msg(int type, int section);	
	std::string	get_msg_main_code(int type);
	std::string	get_msg_array(int type);
	std::string	get_msg_date(int type);
	int			get_code();
public:
	Error(int code);
	Error(int code, int section);
	void		print() const;
};

#endif