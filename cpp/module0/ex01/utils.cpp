/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:30:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/17 11:21:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
		std::cerr << ATOI_BAD_VALUE_MSG;
		return (false);
	}
	*index = std::atoi(s.c_str());
	if (*index < 0 || *index >= PHONE_SIZE)
	{
		std::cerr << INVALID_SEARCH_MSG;
		return (false);
	}
	if (phone->get_contacts()[*index].empty() == true)
	{
		std::cerr << MISSING_NUMBER_MSG;
		return (false);
	}
	return (true);
}
