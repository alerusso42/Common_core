/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:30:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/10 17:12:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

int	first_free_index(PhoneBook *phone)
{
	int	i;

	i = 0;
	while (phone->contacts[i].first_name[0] != '\0' && i != PHONE_SIZE)
	{
		++i;
	}
	if (i == PHONE_SIZE)
	{
		std::cout << "\033[1;32mNumber\t\033[0m" << 0 << std::endl;
		return (0);
	}
	std::cout << "\033[1;32mNumber\t\033[0m" << i << std::endl;
	return (i);
}

bool	valid_string(string s)
{
	int	i;

	if (s.empty() == true)
		return (false);
	if (s.size() >= 1000)
		return (false);
	i = 0;
	while (s[i])
	{
		if (std::isprint(s[i]) == false)
			return (false);
		++i;
	}
	return (true);
}

void	reset_contact(Contact *contact)
{
	contact->first_name.clear();
	contact->last_name.clear();
	contact->nickname.clear();
	contact->phone_number.clear();
	contact->darkest_secret.clear();
}

bool	add_info(Contact *contact, string *dest, string msg)
{
	string	s;

	std::cout << msg << std::endl;
	std::getline(std::cin, s);
	if (valid_string(s) == false)
		return (std::cout << "\033[1;31mBad value\n\033[0m", \
			reset_contact(contact), false);
	*dest = s;
	return (true);
}
