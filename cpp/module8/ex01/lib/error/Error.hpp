/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:04:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/30 14:48:50 by alerusso         ###   ########.fr       */
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
	EX_BAD_SIZE,
	EX_OUT_BOUND,
	EX_NEGATIVE_INDEX,
	EX_ALLOC,
	EX_SINGLE_ELEM,
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