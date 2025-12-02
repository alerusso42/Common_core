/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:52:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 16:52:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP
/* Auto-generated header aggregator */
# include "lib/lib.hpp"
# include "map"
# include <fstream>

# define SEPARATOR_DATABASE ","
# define SEPARATOR_INPUT " | "
# define DATABASE_NAME "data.csv"
# define DATABASE_DIR "data"
# define INPUT_DIR "input"

enum e_bitcoin_ranges
{
	BITCOIN_MIN = 0,
	BITCOIN_MAX = 1000,
};

void	read_database(std::map<Date, double> &map, std::string database_name);
void	print_input(std::map<Date, double> &map, std::string input_name);

# define USAGE "\033[32mwhat btc does\033[33m\n\
btc is a database with bitcoin prices over time.\n\
It takes a file as input with argv:\n\
the files must store a list of pair Date | number_bitcoin_bought\n\
the database prints the values of number_bitcoin_bought * price at Date.\n\
database file has a similar structure: Date,price\n\
They are both is .csv format.\n\
Example can be found in data/ and input/.\033[0m\n"

#endif