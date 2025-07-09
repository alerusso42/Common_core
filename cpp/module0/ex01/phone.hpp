/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:10:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/09 15:59:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_HPP
# define PHONE_HPP

#include <iostream>
#include <string>
# define PHONE_SIZE 8

typedef	std::string	string;

typedef class Contact
{
	private:
		/* data */
	public:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;	
}	Contact;

typedef class PhoneBook
{
	private:
		/* data */
	public:
		Contact	contacts[PHONE_SIZE + 1];
		PhoneBook(Contact contacts[PHONE_SIZE + 1]);
		~PhoneBook();
}	Phone;

int	first_free_index(PhoneBook *phone);


#endif