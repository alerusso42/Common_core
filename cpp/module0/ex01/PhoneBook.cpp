/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:35:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::~PhoneBook(void)
{
	std::cout << DIO << "\nGOODBYE, JOJO!\n";
	return ;
}

//NOTE -	Constructor may see all its data inside this function.
PhoneBook::PhoneBook(void)
{
	reset_id = 0;
}
		
Contact	*PhoneBook::get_contacts(void)
{
	return (this->contacts);
}

int		&PhoneBook::get_id(void)
{
	return (this->reset_id);
}

/*
//REVIEW - search

Phone must have at least one contact.

1)	First, the entire phonebook is printed;
2)	Valid search checks if:
	-	the std::string is invalid; 
	-	stoi (=std::string to integer) fails; 
	-	index is over PHONE_SIZE or lower zero;
	-	contact selected is empty.
3)	Lastly, every contact is printed, with a '\n'. 

*/
void	PhoneBook::search(void)
{
	std::string	 s;
	int		index;
	int		i;

	if (this->get_contacts()[0].empty() == true)
	{
		std::cout << EMPTY_CONTACTS_MSG;
		return ;
	}
	print_phonebook(this);
	std::cout << "Please, insert a valid phone index:\n";
	std::getline(std::cin, s);
	while (valid_search(this, s, &index) == false)
	{
		std::cout << "Please, insert a valid phone index:\n";
		std::getline(std::cin, s);
	}
	i = 0;
	while (i != ENTRY_NUM)
	{
		std::cout <<  *this->get_contacts()[index].get_list()[i] << std::endl;
		++i;
	}
	std::cout << this->get_contacts()[index].get_dark() << std::endl;
}

//	Finds the first free contact index to fill, or the oldest if full.
int	PhoneBook::first_free_index(void)
{
	int	i;

	i = 0;
	while (this->get_contacts()[i].empty() == false && i != PHONE_SIZE)
	{
		++i;
	}
	if (i == PHONE_SIZE)
	{
		std::cout << "\033[1;32mNumber\t\033[0m" << 0 << std::endl;
		if (this->get_id() == PHONE_SIZE)
			this->get_id() = 0;
		return (this->get_id()++);
	}
	std::cout << "\033[1;32mNumber\t\033[0m" << i << std::endl;
	return (i);
}

void	PhoneBook::add(void)
{
	this->get_contacts()[this->first_free_index()].add();
}
