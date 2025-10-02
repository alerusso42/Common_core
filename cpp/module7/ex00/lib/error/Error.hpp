/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:04:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:31:38 by alerusso         ###   ########.fr       */
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
	EX_GRADE_HIGH,
	EX_GRADE_LOW,
	EX_NOT_SIGN,
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