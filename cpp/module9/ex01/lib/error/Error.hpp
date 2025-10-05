/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:04:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/05 18:36:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include "../strings/conversion.tpp"
# include <stdexcept>
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

/*REVIEW - Error class

//SECTION - throw errors
	To throw Errors:
		throw (Error(EX_insert_enum_name));
	OR, if you need to print additional stuff:
		throw (Error(EX_insert_enum_name, 0, double_var));
		throw (Error(EX_insert_enum_name, 0, string_var));
		throw (Error(EX_insert_enum_name, 0, int_var));

//SECTION - catch errors
To catch Errors:
	catch (const Error &e)
	{
		e.print();
	}

//SECTION - add errors
To add Errors:
	1)	Modify this enum;
	2)	go to Error.cpp: modify "get_msg_main_code".

//SECTION - personalized errors print
To modify error print:
	1)	in Error.hpp, add an Error constructor with your type;
	ex. Error(int code, int section, type t);
	2)	in Error.cpp, add that constructor;
	3)  in the constant initialization, pass to get_msg type as a string.
	ex. Error::Error(int code, int section, type t) : \
		std::runtime_error(get_msg(code, section, t.make_string())).

//SECTION - adding a error section
To add error section:
	1)	in Error.hpp, add the new section in e_error_section;
	2)	in Error.cpp, in "get_msg", add in the switch case
		your section;
	3)	add in Error.hpp a new function, named get_msg_NEWSECTION;
	4)	fill in Error.cpp get_msg_NEWSECTION with prints, 
		following "get_msg_main_code" example.
*/
enum e_error_main
{
	EX_INVALID_CHAR,
	EX_EMPTY_STACK,
	EX_DIVISION,
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
	EX_DATE_RANGE_END,
	EX_DATE_BISESTILE,
	EX_DATE_ALTER,
	EX_DATE_NUM,
};

std::string	ft_itoa(int n);

class Error : public std::runtime_error
{
private:
	int			_code;
	std::string	get_msg(int type, int section);
	std::string	get_msg(int type, int section, std::string s);	
	std::string	get_msg_main_code(int type);
	std::string	get_msg_array(int type);
	std::string	get_msg_date(int type);
	int			get_code();
public:
	Error(int code);
	Error(int code, int section);
	template <typename T>
	Error(int code, int section, T dt);
	void		print() const;
};

# include "Error.tpp"
#endif