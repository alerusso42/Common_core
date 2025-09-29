/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:06:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/29 23:24:36 by alerusso         ###   ########.fr       */
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

string	Error::get_msg(int type)
{
	string	s;

	if (type == EX_NOT_FOUND)
		s = "Not found";
	else
		s = "Unknown";
	return (s);
}
