/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:04:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/04 08:54:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include <stdexcept>
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

  

enum e_error
{
	EX_TIME_BAD,
	EX_TIME_NEGATIVE,
	EX_TIME_RANGE_START,
	EX_TIME_YEAR_LOW,
	EX_TIME_YEAR_HIGH,
	EX_TIME_MONTH_LOW,
	EX_TIME_MONTH_HIGH,
	EX_TIME_DAY_LOW,
	EX_TIME_DAY_HIGH,
	EX_TIME_CLOCK_LOW,
	EX_TIME_CLOCK_HIGH,
	EX_TIME_RANGE_END,
	EX_BAD_VALUE,
	EX_TOO_MANY_FIELDS,
	EX_FILE,
	EX_NUMERIC_RANGE,
	EX_NUM,
};

class Error : public std::runtime_error
{
	private:
		int		_code;
		std::string	 get_msg(int type);
		int		get_code();
	public:
		Error(int code);
		void	print() const;
};

#endif