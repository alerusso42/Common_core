/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:52:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 16:52:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	std::map<Date, double>	map;

	if (argc != 2)
		return (print_error("Error: could not open file"), 1);
	else if (valid_input((std::string)argv[1]) != true)
		return (print_error("Error: could not open file"), 1);
	try
	{
		read_database(map, DATABASE_NAME);
		print_input(map, argv[1]);
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

int main2()
{
	std::map<Date, double>	m;

	try
	{
		Date	date("2004-03-31", '-', false);
		std::cout << date << std::endl;
		date.basic_print(std::cout);
		std::cout << std::endl;
	}
	catch(const Error &e)
	{
		e.print();
	}
	(void)m;
	std::cout << sizeof(Date) << std::endl;
	return (0);
}

int main3() 
{
	std::cout << sizeof(Date) << std::endl;
	std::cout << sizeof(size_t) << std::endl;
	return (0);
}
