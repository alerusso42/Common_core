/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:55:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/13 18:29:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycast_tty.hpp"
#define LOG "logfile"

static void	interpreter(std::ofstream &stream, int8_t type, va_list &list);

void	debug_print(std::string s, ...)
{
	va_list			list;
	std::ofstream	stream(LOG, std::ios_base::app);

	if (stream.fail())
		return ;
	va_start(list, s);
	for (typename std::string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (*it != '%')
			stream << *it;
		else
		{
			++it;
			if (it == s.end())
				break ;
			interpreter(stream, *it, list);
		}
	}
	stream << std::flush;
	va_end(list);
}

static void	interpreter(std::ofstream &stream, int8_t type, va_list &list)
{
	if (type == 'c')
		stream << (int8_t)va_arg(list, int32_t);
	else if (type == 's')
		stream << (int8_t *)va_arg(list, int8_t *);
	else if (type == 'd' || type == 'i')
		stream << (int32_t)va_arg(list, int32_t);
	else if (type == 'u')
		stream << (u_int32_t)va_arg(list, u_int32_t);
	else if (type == 'f')
		stream << (double)va_arg(list, double);
	else if (type == '%')
		stream << "%";
}
