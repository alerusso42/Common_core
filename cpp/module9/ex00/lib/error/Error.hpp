/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:04:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/03 19:17:31 by alerusso         ###   ########.fr       */
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
	EX_BAD_TIME,
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