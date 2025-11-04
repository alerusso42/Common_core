/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:28:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/04 15:02:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

# define USAGE "Insert one or more numeric values.\nthe program will \
print them."
# define DEFAULT_FILE "tests/default.sh"

static bool	testing(std::string filename);

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (std::cerr << "\033[31m" USAGE "\033[0m" << std::endl, 1);
	if (testing(argv[1]) == true)
		return (0);
	for (int i = 1; argv[i]; i++)
	{
		if (valid_number(argv[i], true) == 0 || special_cases(argv[i]))
		{
			std::cout << argv[i] << "\033[32m representations:\n\033[0m";
			ScalarConverter::convert(argv[i]);
		}
		else
			std::cout << argv[i] << "\033[31m is not a valid number.\n\033[0m";
	}
	std::cout << std::flush;
}

static bool	testing(std::string filename)
{
	std::string	line;

	if (filename == "test" || filename == "TEST")
		filename = DEFAULT_FILE;
	std::fstream	fd(filename.c_str(), std::ios::in);
	if (fd.fail())
		return (false);
	while (std::getline(fd, line))
	{
		if (line.empty() == true || line[0] == ' ' || line[0] == '#')
			continue ;
		if (valid_number(line, true) == 0 || special_cases(line))
		{
			std::cout << line << "\033[32m representations:\n\033[0m";
			ScalarConverter::convert(line);
		}
		else
			std::cout << line << "\033[31m is not a valid number.\n\033[0m";
	}
	return (true);
}
