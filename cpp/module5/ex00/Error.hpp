/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:04:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/17 16:17:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include <stdexcept>
# include "lib/lib.hpp"

enum e_error
{
	EX_GRADE_HIGH,
	EX_GRADE_LOW,
	EX_NUM,
};

class Error : public std::runtime_error
{
	public:
		Error(int code);
		string	get_msg(int type);
		int		get_code();
		void	print() const;
	private:
		int		_code;
};

#endif