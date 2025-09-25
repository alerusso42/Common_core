/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:28:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/25 09:23:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

# define USAGE "Insert one or more numeric values.\nthe program will \
print them."

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (std::cerr << "\033[31m" USAGE "\033[0m" << std::endl, 1);
	for (int i = 1; argv[i]; i++)
	{
		if (valid_number(argv[i], true) == 0 || special_cases(argv[i]))
		{
			std::cout << argv[i] << " representations:\n";
			ScalarConverter::convert(argv[i]);
		}
		else
			std::cout << argv[i] << "\033[31m is not a valid number.\n\033[0m";
	}
	std::cout << std::flush;
}
