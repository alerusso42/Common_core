/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:11:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/17 11:07:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
//REVIEW - phonebook

PHONE_SIZE must be at least 1

1)	Print guide prints the instruction;
2)	Takes a string in input using getline.
	while its invalid, ask it again;
3)	if input is "exit", return.
	else, execute a command.
*/
int main()
{
	string		s;
	PhoneBook	phone;

	if (PHONE_SIZE <= 0)
		return (std::cerr << "Phone too small", 1);
	print_guide();
	std::cout << "Please, insert a valid command:\n";
	std::getline(std::cin, s);
	while (valid_input(s) == false)
		std::getline(std::cin, s);
	while (s.compare("EXIT") != 0 && s.compare("exit") != 0)
	{
		execute(s, &phone);
		std::cout << "Please, insert a valid command:\n";
		std::getline(std::cin, s);
		while (valid_input(s) == false)
			std::getline(std::cin, s);
	}
}

//	First_free_index select from the phone the first free space,
//	or the oldest occupied space.
void	execute(string s, PhoneBook *phone)
{
	if (s.compare("ADD") == 0 || s.compare("add") == 0)
		phone->add();
	else if (s.compare("SEARCH") == 0 || s.compare("search") == 0)
		phone->search();
}
