/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:39:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/05 16:24:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_TPP
# define ERROR_TPP
#include "Error.hpp"

template <typename T>
Error::Error(int code, int section, T dt) : \
std::runtime_error(get_msg(code, section, ft_to_string(dt)))
{
	this->_code = code;
}

#endif