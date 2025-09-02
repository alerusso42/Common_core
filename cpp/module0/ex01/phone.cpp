/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/02 12:42:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

static void	add(Contact *contact);
static void	search(PhoneBook *phone);

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
	(void)phone;
	if (s.compare("ADD") == 0 || s.compare("add") == 0)
		add(&phone->contacts[first_free_index(phone)]);
	else if (s.compare("SEARCH") == 0 || s.compare("search") == 0)
		search(phone);
}

//	add_info may fail if user insert a non valid string.
//	if fails, contact is reset.
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

/*
//REVIEW - search

Phone must have at least one contact.

1)	First, the entire phonebook is printed;
2)	Valid search checks if:
	-	the string is invalid; 
	-	stoi (=string to integer) fails; 
	-	index is over PHONE_SIZE or lower zero;
	-	contact selected is empty.
3)	Lastly, every contact is printed, with a '\n'. 

*/
static void	search(PhoneBook *phone)
{
	string	s;
	int		index;
	int		i;

	if (phone->contacts[0].first_name.empty() == true)
	{
		std::cout << EMPTY_CONTACTS_MSG;
		return ;
	}
	print_phonebook(phone);
	std::cout << "Please, insert a valid phone index:\n";
	std::getline(std::cin, s);
	while (valid_search(phone, s, &index) == false)
	{
		std::cout << "Please, insert a valid phone index:\n";
		std::getline(std::cin, s);
	}
	i = 0;
	while (i != ENTRY_NUM)
	{
		std::cout <<  *phone->contacts[index].entry_list[i] << std::endl;
		++i;
	}
	std::cout <<  phone->contacts[index].darkest_secret << std::endl;
}
