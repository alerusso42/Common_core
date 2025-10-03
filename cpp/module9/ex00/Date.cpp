/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:52:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 16:52:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(string date)
{
	int	i;

	i = 0;
	while (date[i] && i != T_HOUR)
	{
		if (ft_atoi(date, &this->_datas[i], i) != 0)
			throw Error(EX_BAD_TIME);
		else if (ft_atoi(&this->_datas[i] )
		++i;
	}
}

Date::Date(string date, bool has_seconds)
{

}

Date::Date(int32_t year, int32_t month, int32_t day)
{

}

Date::~Date()
{

}

Date::Date(const Date &other)
{ 
	(void)other;
}

Date &Date::operator=(const Date &other)
{
	if (this != &other) 
	{
		// add field
	}
	return (*this);
}
