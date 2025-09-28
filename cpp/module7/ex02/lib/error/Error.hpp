/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:04:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 19:19:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include <stdexcept>
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

typedef	std::string	string;

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
		string	get_msg(int type);
		int		get_code();
	public:
		Error(int code);
		void	print() const;
};

#endif