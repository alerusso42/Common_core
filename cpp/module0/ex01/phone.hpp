/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:10:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/10 17:09:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_HPP
# define PHONE_HPP

#include <iostream>
#include <string>
# define PHONE_SIZE 2

# define RST		"\033[0m" /* Reset to default color */
# define RED		"\033[1;31m" /* Bold Red */
# define BGREEN		"\033[1;32m" /* Bold Green */
# define BYELLOW	"\033[1;33m" /* Bold Yellow*/
# define BBLUE		"\033[1;34m" /* Bold Blue*/
# define BMAGENTA	"\033[1;35m" /* Bold Magenta*/
# define BCYAN		"\033[1;36m" /* Bold Cyan*/
# define BWHITE		"\033[1;37m" /* Bold White*/

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
		//PhoneBook(Contact contacts[PHONE_SIZE + 1]);
		//~PhoneBook();
}	Phone;

bool	valid_string(string s);
void	reset_contact(Contact *phone);
int		first_free_index(PhoneBook *phone);
void	execute(string s, PhoneBook *phone);
bool	add_info(Contact *phone, string *dest, string msg);


#endif