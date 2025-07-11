/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:30:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/11 17:40:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

//	Finds the first free contact index to fill, or the oldest if full.
int	first_free_index(PhoneBook *phone)
{
	int	i;

	i = 0;
	while (phone->contacts[i].first_name.empty() == false && i != PHONE_SIZE)
	{
		++i;
	}
	if (i == PHONE_SIZE)
	{
		std::cout << "\033[1;32mNumber\t\033[0m" << 0 << std::endl;
		if (phone->reset_id == PHONE_SIZE)
			phone->reset_id = 0;
		return (phone->reset_id++);
	}
	std::cout << "\033[1;32mNumber\t\033[0m" << i << std::endl;
	return (i);
}

//	Sets every entry in the contact to zero.
void	reset_contact(Contact *contact)
{
	int	i;

	i = 0;
	while (i != ENTRY_NUM)
	{
		(*contact->entry_list[i]).clear();
		++i;
	}
}

//	Add an entry string dest in a contact. Prints a message before input.
bool	add_info(Contact *contact, string *dest, string msg)
{
	string	s;

	std::cout << msg << std::endl;
	std::getline(std::cin, s);
	if (valid_input(s) == false)
		return (reset_contact(contact), false);
	*dest = s;
	return (true);
}

/*
//REVIEW - valid_search

Valid search checks if:
	-	the string is invalid; 
	-	atoi fails; 
	-	index is over PHONE_SIZE or lower zero;
	-	contact selected is empty.

//NOTE - try.. catch is a conditional guard.
//		 its purpouse is to enter in the catch part only if
		 a variable is set to a specific value.
//		 the variable is ptr: is a pointer to the class exception.
//		 the class is definied in std.
//		 therefore, this works only for std:: methods.
*/
bool	valid_search(PhoneBook *phone, string s, int *index)
{
	if (valid_input(s) == false)
		return (false);
	if (std::isdigit(s[0]) == false)
	{
		std::cout << ATOI_BAD_VALUE_MSG;
		return (false);
	}
	*index = std::atoi(s.c_str());
	if (*index < 0 || *index >= PHONE_SIZE)
	{
		std::cout << INVALID_SEARCH_MSG;
		return (false);
	}
	if (phone->contacts[*index].first_name.empty() == true)
	{
		std::cout << MISSING_NUMBER_MSG;
		return (false);
	}
	return (true);
}
