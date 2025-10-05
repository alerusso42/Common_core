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

void	debug_print(std::map<Date, double> map);

/*REVIEW - btc
	//SECTION - what btc does
//	btc is a database with bitcoin prices over time.
//	It takes a file as input with argv:
	the files must store a list of pair Date | number_bitcoin_bought
//	the database prints the values of number_bitcoin_bought * price at Date.
//	database file has a similar structure: Date,price
//	They are both is .csv format.
//	Example can be found in data/ and input/.

	//SECTION - resolution
	The general idea: usins a std::map, my favourite data type,
	to store database and sort it;
	then, read the input file, and search the dates in the std::map.

	//SECTION - std::map
	An std::map is a container that takes two param: a key, and a value.
	My key is the custom class Date, that has overload for <, <=, >, >=.
	std::map use my overload to sort the database.

	//SECTION - Date
	Date is a class that can store and operating over time values.
	It has an overload for comparison operators, +, +=, -, -=, <<.
	When one of the constructor is called with bad params,
	such as invalid day, year below/above limits, unformatted param,
	Date throws exception with explicit message. 
*/
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

//Sizeof Date = 20
int main2()
{
	std::cout << sizeof(Date) << std::endl;
	return (0);
}

//SECTION - database testing

//database: unsorted
int main3(int argc, char *argv[])
{
	std::map<Date, double>	map;

	if (argc != 2)
		return (print_error("Error: could not open file"), 1);
	else if (valid_input((std::string)argv[1]) != true)
		return (print_error("Error: could not open file"), 1);
	try
	{
		read_database(map, "unsorted.csv");
		debug_print(map);
		print_input(map, argv[1]);
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

//database: one field
int main4(int argc, char *argv[])
{
	std::map<Date, double>	map;

	if (argc != 2)
		return (print_error("Error: could not open file"), 1);
	else if (valid_input((std::string)argv[1]) != true)
		return (print_error("Error: could not open file"), 1);
	try
	{
		read_database(map, "one_field.csv");
		debug_print(map);
		print_input(map, argv[1]);
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

//SECTION - input testing

//empty
int	main5()
{
	std::map<Date, double>	map;

	try
	{
		read_database(map, DATABASE_NAME);
		print_input(map, "empty.csv");
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

//fields
int	main6()
{
	std::map<Date, double>	map;

	try
	{
		read_database(map, DATABASE_NAME);
		print_input(map, "fields.csv");
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

//value
int	main7()
{
	std::map<Date, double>	map;

	try
	{
		read_database(map, DATABASE_NAME);
		print_input(map, "value.csv");
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

//date
int	main8()
{
	std::map<Date, double>	map;

	try
	{
		read_database(map, DATABASE_NAME);
		print_input(map, "date.csv");
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

//testing file
int	main9()
{
	std::map<Date, double>	map;

	try
	{
		read_database(map, DATABASE_NAME);
		print_input(map, "testing.csv");
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

// testing over Date class
int	main10()
{
	Date	date1((std::string)"2022-01-12", '-');
	Date	date2((std::string)"2022-01-12", '-');

	try
	{
		date2 = date1 + 4534;
		std::cout << date2 << std::endl;
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

void	debug_print(std::map<Date, double> map)
{
	u_int32_t	count;

	count = 0;
	for (typename std::map<Date, double>::iterator i = map.begin(); i != map.end(); i++)
	{
		std::cout << "pair[" << count << "]:\n";
		std::cout << i->first << "|" << i->second << "\n";
		++count;
	}
	std::cout << std::endl;
}
