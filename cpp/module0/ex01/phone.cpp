/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/10 17:04:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

static void	add(Contact *contact);

int main() 
{
	string		s;
	PhoneBook	phone;

	if (PHONE_SIZE <= 0)
		return (std::cerr << "Phone too small", 1);
	std::cout << "\033[1;32mWelcome to PhoneBook! Commands:";
	std::cout << "\nEXIT:\tStop program, clear the Phone forever"; 
	std::cout << "\nADD:\tAdd a new contact to the phone. Please fill every";
	std::cout << "field!";
	std::cout << "\nSEARCH:\tPrints all phonebook, then asks for the index of";
	std::cout << " the contact to print. The index is the saving order.";
	std::cout << " If number of contacts surpasses " << PHONE_SIZE << ", ";
	std::cout << "then first contact gets replaced.\nHave fun!\n\033[0m";
	std::cout << "Please, insert a valid command:\n";
	std::getline(std::cin, s);
	while (valid_string(s) == true && \
	s.compare("EXIT") != 0 && s.compare("exit") != 0)
	{
		execute(s, &phone);
		std::cout << "Please, insert a valid command:\n";
		std::getline(std::cin, s);
	}
	std::cout << "GOODBYE, JOJO!\n";
}

void	execute(string s, PhoneBook *phone)
{
	(void)phone;
	if (s.compare("ADD") == 0 || s.compare("add") == 0)
		add(&phone->contacts[first_free_index(phone)]);
	else if (s.compare("SEARCH") == 0 || s.compare("search") == 0)
		std::cout << "Not implemented.\n";
}

static void	add(Contact *contact)
{
	string	s;

	if (add_info(contact, &contact->first_name, "First name?") == false)
		return ;
	if (add_info(contact, &contact->last_name, "Last name?") == false)
		return ;
	if (add_info(contact, &contact->nickname, "Nickname?") == false)
		return ;
	if (add_info(contact, &contact->phone_number, "Phone number?") == false)
		return ;
	if (add_info(contact, &contact->darkest_secret, "Secret???") == false)
		return ;
}

