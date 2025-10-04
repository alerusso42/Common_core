/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:04:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/04 17:09:14 by alerusso         ###   ########.fr       */
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
	EX_BAD_SIZE,
	EX_OUT_BOUND,
	EX_NEGATIVE_INDEX,
	EX_ALLOC,
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