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

#endif