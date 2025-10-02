/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:06:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:31:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

Error::Error(int code) : std::runtime_error(get_msg(code))
{
	this->_code = code;
}

int	Error::get_code()
{
	return (this->_code);
}

void	Error::print(void) const
{
	std::cerr << "\033[31mException: " << this->what();
	std::cerr << "[" << this->_code << "]\033[0m" << std::endl;
}

std::string	 Error::get_msg(int type)
{
	std::string	 s;

	if (type == EX_GRADE_HIGH)
		s = "Grade too high";
	else if (type == EX_GRADE_LOW)
		s = "Grade too low";
	else if (type == EX_NOT_SIGN)
		s = "Form NOT sign";
	else
		s = "Unknown";
	return (s);
}
