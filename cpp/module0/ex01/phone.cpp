/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/09 16:13:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phone.hpp>

int main(int argc, char *argv[]) 
{
	string	s;

	s.empty();
	std::cout << "Welcome to PhoneBook! Please insert one of the following:";
	std::cout << "\nEXIT:\tStop program, clear the Phone forever"; 
	std::cout << "\nADD:\tAdd a new contact to the phone. Please fill every";
	std::cout << "field!";
	std::cout << "\nSEARCH:\tPrints all phonebook, then asks for the index of";
	std::cout << " the contact to print. The index is the saving order.";
	std::cout << " If number of contacts surpasses " << PHONE_SIZE << ", ";
	std::cout << "then first contact gets replaced.\nHave fun!\n";
	while (s.size() < 1000 && s.compare("EXIT") != 0 && s.compare("exit") != 0)
	{
		
		std::cout << "Please, insert a valid command.\n";
		std::cin >> s;
	}
		
}

int	first_free_index(PhoneBook *phone)
{
	int	i;

	i = 0;
	while (phone->contacts[i].first_name[0] != '\0')
	{
		++i;
	}
	if (i == PHONE_SIZE)
		return (0);
	return (i);
}

