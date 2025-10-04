/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:44:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/04 23:55:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

static void		database_insert_entry(std::map<Date, double> &map, std::string entry);
static double	check_bitcoin(std::string entry, std::string sep, bool check_max);
static void	print_bitcoin_value(std::map<Date, double> &map, std::string entry);

void	read_database(std::map<Date, double> &map, std::string database_name)
{
	std::fstream	database(database_name.c_str(), std::ios::in);
	std::string		line;

	if (database.fail() == true)
		throw (Error(EX_OPEN_DATABASE));
	std::getline(database, line);
	if (line.empty() == true)
		throw (Error(EX_EMPTY_DATABASE));
	while (std::getline(database, line))
		database_insert_entry(map, line);
}

void	print_input(std::map<Date, double> &map, std::string input_name)
{
	std::fstream	input(input_name.c_str(), std::ios::in);
	std::string		line;

	if (map.empty() == true)
		return ;
	if (input.fail() == true)
		throw (Error(EX_OPEN_INPUT));
	std::getline(input, line);
	if (line.empty() == true)
		throw (Error(EX_EMPTY_INPUT));
	while (std::getline(input, line))
	{
		try
		{
			print_bitcoin_value(map, line);
		}
		catch(const Error& e)
		{
			e.print();
		}
	}
}

static void	database_insert_entry(std::map<Date, double> &map, std::string entry)
{
	double	n;

	try
	{
		Date	date(entry, '-');
		n = check_bitcoin(entry, SEPARATOR_DATABASE, false);
		map[date] = n; 
	}
	catch(const Error& e)
	{
		e.print();
	}
}

static double	check_bitcoin(std::string entry, std::string sep, bool check_max)
{
	size_t	pos;
	double	bitcoin_value;

	pos	= entry.find_first_of(sep);
	if (pos == entry.npos)
		throw (Error(EX_TOO_FEW_FIELDS));
	pos += sep.length();
	if (entry.substr(pos).find_first_of(sep) != entry.npos)
		throw (Error(EX_TOO_MANY_FIELDS));
	if (valid_number(entry.substr(pos), true) != 0)
		throw (Error(EX_BAD_VALUE));
	bitcoin_value = std::atof(entry.substr(pos).c_str());
	if (bitcoin_value < BITCOIN_MIN)
		throw (Error(EX_NUMERIC_RANGE));
	else if (check_max == true && bitcoin_value > BITCOIN_MAX)
		throw (Error(EX_NUMERIC_RANGE));
	return (bitcoin_value);
}

static void	print_bitcoin_value(std::map<Date, double> &map, std::string entry)
{
	double	n;

	try
	{
		Date	date(entry, '-');
		n = check_bitcoin(entry, SEPARATOR_INPUT, true);
		if (date < map.begin()->first)
			throw (Error(EX_TOO_OLD));
		date.basic_print(std::cout);
		std::cout << " => " << n << " = ";
		if (date > (map.rbegin()->first))
			std::cout << map.rbegin()->second * n;
		else
		{
			while (map.find(date) == map.end())
				date--;
			std::cout << map.find(date)->second * n;
		}
		std::cout << std::endl;
	}
	catch(const Error& e)
	{
		e.print();
	}
}
