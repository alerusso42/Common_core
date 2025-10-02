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

	if (type == EX_BAD_SIZE)
		s = "Specified size is too big.";
	else if (type == EX_OUT_BOUND)
		s = "Element is out of bounds";
	else if (type == EX_NEGATIVE_INDEX)
		s = "Negative index is not allowed";
	else if (type == EX_ALLOC)
		s = "Allocation failed";
	else if (type == EX_SINGLE_ELEM)
		s = "Calling Span functions with less than 2 elements is not allowed";
	else
		s = "Unknown";
	return (s);
}
