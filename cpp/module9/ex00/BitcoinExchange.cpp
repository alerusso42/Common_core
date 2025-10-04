/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:44:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/04 20:40:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void	check_bitcoin_value(std::string entry, std::string separator);

void	database_insert_entry(std::map<Date, double> map, std::string entry)
{
	int32_t	pos;

	try
	{
		Date	date(entry, '-');
		pos = entry.find_first_of(SEPARATOR_DATABASE);
		if (pos == entry.npos)
			throw ()
	}
	catch(const Error& e)
	{
		e.print();
	}
	
}

static void	check_bitcoin_value(std::string entry, std::string separator)
{
	
}

