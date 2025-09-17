/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:18:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/17 11:20:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "lib/lib.hpp"

Contact::Contact()
{
	int	i;

	i = 0;
	while (i != PHONE_SIZE + 1)
	{
		this->entry_list[0] = &this->first_name;
		this->entry_list[1] = &this->last_name;
		this->entry_list[2] = &this->nickname;
		this->entry_list[3] = &this->phone_number;
		++i;
	}
}

Contact::~Contact()
{}

//	Sets every entry in the contact to zero.
void	Contact::reset_contact(void)
{
	int	i;

	i = 0;
	while (i != ENTRY_NUM)
	{
		((*this->entry_list)[i]).clear();
		++i;
	}
}

//	add_info may fail if user insert a non valid string.
//	if fails, contact is reset.
void	Contact::add(void)
{
	while (add_info(&this->first_name, "First name?", false) == false);
	while (add_info(&this->last_name, "Last name?", false) == false);
	while (add_info(&this->nickname, "Nickname?", false) == false);
	while (add_info(&this->phone_number, "Phone number?", true) == false);
	while (add_info(&this->darkest_secret, "Secret???", false) == false);
}

//	Add an entry string dest in a contact. Prints a message before input.
bool	Contact::add_info(string *dest, string msg, bool numeric)
{
	string	s;

	std::cout << msg << std::endl;
	std::getline(std::cin, s);
	if (valid_input(s) == false)
		return (reset_contact(), false);
	if (numeric && ft_atoi(s, NULL) != 0)
		return (std::cerr << ATOI_BAD_VALUE_MSG, false);
	*dest = s;
	return (true);
}

bool	Contact::empty() const
{
	return (this->first_name.empty());
}

string	**Contact::get_list()
{
	return (this->entry_list);
}

const string	Contact::get_dark(void) const
{
	return (this->darkest_secret);
}