/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:08:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/05 15:36:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_TPP
# define CONVERSION_TPP
# include <iostream>
# include <string>
# include <cstdlib>

//REVIEW - 	ft_to_string
/*
	std::to_string is a useful function, that converts
	a lot of data type to std::string.
	Unluckly, it is available only with cplusplus 2011.

	This macro is put to use a custom function if not available.
	Else, ft_to_string calls the original.
	
	std::ostringstream is a stream like std::cout, 
	but is not connected to the terminal: it just
	prints on a std::string.
	It is useful because stream has internal functions to
	manage conversions; therefore we use it to convert.
*/

# if __cplusplus < 201103L
#  include <sstream>

template <typename T>
std::string	ft_to_string(T data)
{
	std::ostringstream	stream;

	stream << data;
	return (stream.str());
}
# else
#  define ft_to_string std::to_string
# endif
#endif
