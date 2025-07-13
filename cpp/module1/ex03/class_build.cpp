/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_build.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:49:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/13 16:53:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

PhoneBook::~PhoneBook(void)
{
	std::cout << DIO << "\nGOODBYE, JOJO!\n";
	return ;
}

//NOTE -	Constructor may see all its data inside this function.
PhoneBook::PhoneBook(void)
{
	int	i;

	i = 0;
	reset_id = 0;
	while (i != PHONE_SIZE + 1)
	{
		contacts[i].entry_list[0] = &contacts[i].first_name;
		contacts[i].entry_list[1] = &contacts[i].last_name;
		contacts[i].entry_list[2] = &contacts[i].nickname;
		contacts[i].entry_list[3] = &contacts[i].phone_number;
		++i;
	}
}
